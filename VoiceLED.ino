#include "Preferences.h"
#include "Arduino.h"
#include "Wifi.h"
#include "AdafruitIO.h"
#include "Adafruit_MQTT_Client.h"
#include "Adafruit_MQTT.h"
#include "ArduinoHttpClient.h"
#include <SimplePacketComs.h>
#include <Esp32SimplePacketComs.h>
#include <wifi/WifiManager.h>
//Create a wifi manager
WifiManager manager;

#define MQTT_SERV "io.adafruit.com"
#define MQTT_PORT 1883
#define MQTT_NAME "philiam12"
#define MQTT_PASS "f2f88c5775f446fc8c3bfd5caa323970"

const byte ledPin = 27;
const byte buttonPin = 33;

enum LEDmode {ON, OFF, WAITING};
LEDmode LED = OFF;

LEDmode button = OFF;


WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, MQTT_SERV, MQTT_PORT, MQTT_NAME, MQTT_PASS);

Adafruit_MQTT_Subscribe ledOnOff = Adafruit_MQTT_Subscribe(&mqtt, MQTT_NAME "/f/ledOnOff");

TaskHandle_t Task1;

portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR handleInterrupt() {
  portENTER_CRITICAL_ISR(&mux);
  Serial.println("hello");
  portEXIT_CRITICAL_ISR(&mux);
}

void setup()
{
	Preferences preferences;
	preferences.begin("wifi", false); // Note: Namespace name is limited to 15 chars
	//preferences.clear();// erase all stored passwords
	//preferences.putString("CarterHatesFun", "AnalJunkies");// set a specific default network to connect to if many possible are present
	// Use serial terminal to set passwords
	// open serial moniter and type the SSID and hit enter
	// when the device prints a prompt for a new password, type the password and hit enter
	preferences.end();
	// use the preferences to start up the wifi
	manager.setup();
	mqtt.subscribe(&ledOnOff);


	pinMode(ledPin, OUTPUT);
	pinMode(buttonPin, INPUT_PULLUP);

	pinMode(buttonPin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, CHANGE);

	xTaskCreatePinnedToCore(loopForSecondCore, "Task_1", 10000, NULL, 1, &Task1, 0);
}

void MQTT_connect()
{
	int8_t ret;

	// Stop if already connected.
	if (mqtt.connected())
	{
		return;
	}

	Serial.print("Connecting to MQTT... ");

	uint8_t retries = 3;
	while ((ret = mqtt.connect()) != 0) // connect will return 0 for connected
	{
		Serial.println(mqtt.connectErrorString(ret));
		Serial.println("Retrying MQTT connection in 5 seconds...");
		mqtt.disconnect();
		delay(5000);  // wait 5 seconds
		retries--;
		if (retries == 0)
		{
			// basically die and wait for WDT to reset me
			while (1);
		}
	}
	Serial.println("MQTT Connected!");
}

void loopForSecondCore(void * parameter){
	delay(20000);
	while(true){
		Serial.print("MQTT Task runs on Core: ");
		Serial.println(xPortGetCoreID());
		MQTT_connect();
		//Serial.println(digitalRead(i++));

		//Read from our subscription queue until we run out, or
		//wait up to 10 seconds for subscription to update
		Adafruit_MQTT_Subscribe * subscription;
		while ((subscription = mqtt.readSubscription(10000)))
		{
			//this line is almost acting like a delay, its waiting for the subscription to update
			//If we're in here, a subscription updated...           //can read sub updates without using this funciton call? can i do it on another core?
			if (subscription == &ledOnOff)                          //I think I found the answere here.. needs further investigation.
			{                                                       //https://github.com/programmer131/thingSpeakMQTT/blob/master/esp32/esp32.ino
				//Print the new value to the serial monitor
				Serial.print("ledOnOff: ");
				Serial.println((char*)ledOnOff.lastread);

				//If the new value is  "ON", turn the light on.
				//Otherwise, turn it off.
				if (!strcmp((char*)ledOnOff.lastread, "on"))
				{
					LED = ON;
				}
				else
				{
					LED = OFF;
				}
			}
		}
		// ping the server to keep the mqtt connection alive
		if (!mqtt.ping())
		{
			mqtt.disconnect();
		}
	}
}

void loop(){
	switch(LED)
	{
	case ON:
		digitalWrite(ledPin, HIGH);
		LED = WAITING;
		Serial.print("Loop Task runs on Core: ");
		Serial.println(xPortGetCoreID());
		break;
	case OFF:
		digitalWrite(ledPin, LOW);
		LED = WAITING;
		Serial.print("Loop Task runs on Core: ");
		Serial.println(xPortGetCoreID());
		break;
	case WAITING:
		break;
	}
	manager.loop();
}
