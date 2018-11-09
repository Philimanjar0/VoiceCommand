################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ..\makefile.init

RM := del 

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries\WiFi\src\subdir.mk
-include libraries\SimplePacketComs\src\client\subdir.mk
-include libraries\SimplePacketComs\src\subdir.mk
-include libraries\Preferences\src\subdir.mk
-include libraries\Esp32SimplePacketComs\src\wifi\subdir.mk
-include libraries\Esp32SimplePacketComs\src\server\subdir.mk
-include libraries\Esp32SimplePacketComs\src\device\subdir.mk
-include libraries\ArduinoHttpClient\src\subdir.mk
-include libraries\Adafruit_MQTT_Library\subdir.mk
-include libraries\Adafruit_IO_Arduino\src\wifi\subdir.mk
-include libraries\Adafruit_IO_Arduino\src\util\subdir.mk
-include libraries\Adafruit_IO_Arduino\src\blocks\subdir.mk
-include libraries\Adafruit_IO_Arduino\src\subdir.mk
-include core\core\libb64\subdir.mk
-include core\core\subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ..\makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
C:\Users\Phil\eclipse-workspace\VoiceLED\Release\arduino.ar \

ELF += \
VoiceLED.elf \

HEX += \
VoiceLED.hex \


# All Target
all: VoiceLED

# Tool invocations
VoiceLED: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"C:/Users/Phil/arduino-1.8.5/hardware/espressif/arduino-esp32/tools/xtensa-esp32-elf/bin/xtensa-esp32-elf-size" -A "C:/Users/Phil/eclipse-workspace/VoiceLED/Release/VoiceLED.elf"
	@echo 'Finished building target: $@'
	@echo ' '

C:\Users\Phil\eclipse-workspace\VoiceLED\Release\arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"C:/Users/Phil/arduino-1.8.5/hardware/espressif/arduino-esp32/tools/xtensa-esp32-elf/bin/xtensa-esp32-elf-ar" cru  "C:/Users/Phil/eclipse-workspace/VoiceLED/Release/arduino.ar"    C:/Users/Phil/eclipse-workspace/VoiceLED/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

VoiceLED.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"C:/Users/Phil/arduino-1.8.5/hardware/espressif/arduino-esp32/tools/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc" -nostdlib "-LC:/Users/Phil/arduino-1.8.5/hardware/espressif/arduino-esp32/tools/sdk/lib" "-LC:/Users/Phil/arduino-1.8.5/hardware/espressif/arduino-esp32/tools/sdk/ld" -T esp32_out.ld -T esp32.common.ld -T esp32.rom.ld -T esp32.peripherals.ld -T esp32.rom.spiram_incompatible_fns.ld -u ld_include_panic_highint_hdl -u call_user_start_cpu0 -Wl,--gc-sections -Wl,-static -Wl,--undefined=uxTopUsedPriority  -u __cxa_guard_dummy -u __cxx_fatal_exception  -Wl,--start-group   $(LINK_OBJ)  "C:/Users/Phil/eclipse-workspace/VoiceLED/Release/arduino.ar" -lgcc -lopenssl -lbtdm_app -lfatfs -lwps -lcoexist -lwear_levelling -lesp_http_client -lhal -lnewlib -ldriver -lbootloader_support -lpp -lmesh -lsmartconfig -ljsmn -lwpa -lethernet -lphy -lapp_trace -lconsole -lulp -lwpa_supplicant -lfreertos -lbt -lmicro-ecc -lcxx -lxtensa-debug-module -lmdns -lvfs -lsoc -lcore -lsdmmc -lcoap -ltcpip_adapter -lc_nano -lesp-tls -lrtc -lspi_flash -lwpa2 -lesp32 -lapp_update -lnghttp -lspiffs -lespnow -lnvs_flash -lesp_adc_cal -llog -lsmartconfig_ack -lexpat -lm -lc -lheap -lmbedtls -llwip -lnet80211 -lpthread -ljson  -lstdc++ -Wl,--end-group -Wl,-EL -o "C:/Users/Phil/eclipse-workspace/VoiceLED/Release/VoiceLED.elf" C:/Users/Phil/eclipse-workspace/VoiceLED/Release/arduino.ar
	@echo 'Finished building: $@'
	@echo ' '

VoiceLED.hex: $(ELF)
	@echo 'Do all objcopy commands'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	${A.RECIPE.OBJCOPY.HEX.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents

-include ..\makefile.targets
