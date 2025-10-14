## Avnet PSOC™ Edge DEEPCRAFT™ Voice Assistant

This demo project is the integration of 
Infineon's [PSOC™ Edge MCU: DEEPCRAFT™ Voice Assistant deployment](https://github.com/Infineon/mtb-example-psoc-edge-voice-assistant-deploy)
and [Avnet /IOTCONNECT ModusToolbox&trade; SDK](https://github.com/avnet-iotconnect/avnet-iotc-mtb-sdk). 

The project tracks light levels in multiple rooms and allows the user to 
drive the room lights with voice commands.

Please refer to the 
[Infineon's original project's Operation section](https://github.com/Infineon/mtb-example-psoc-edge-voice-assistant-deploy?tab=readme-ov-file#operation)
for more information on how to interact with the device using the voice prompts or the two other original Infoneon's demos, 
in addition to the supported **Smart Lights Demo**.

This project has a three project structure: CM33 secure, CM33 non-secure, and CM55 projects. All three projects are programmed to the external QSPI flash and executed in Execute in Place (XIP) mode. Extended boot launches the CM33 secure project from a fixed location in the external flash, which then configures the protection settings and launches the CM33 non-secure application. Additionally, CM33 non-secure application enables CM55 CPU and launches the CM55 application.

The M55 processor performs the DEEPCRAFT™ model heavy lifting and reports the data via IPC to the M33 processor.
The M33 Non-Secure application is a custom /IOTCONNECT application that is receiving the IPC messages, 
processing the data and sending it to /IOTCONNECT. 
This application can receive Cloud-To-Device commands as well and control one of the board LEDs or control the application flow.    

> **Note:**
> 1. The Audio and Voice middleware included in this example has a limited operation of about 15 and 30 minutes. For the unlimited license, contact Infineon support.
> 2. This code example supports only the LLVM compiler, which needs to be installed separately. See the *Setup The Project* section below.

## Requirements

- [ModusToolbox&trade;](https://www.infineon.com/modustoolbox) v3.6 or later (tested with v3.6)
- Board support package (BSP) minimum required version: 1.0.0
- Programming language: C
- Associated parts: All [PSOC&trade; Edge MCU](https://www.infineon.com/products/microcontroller/32-bit-psoc-arm-cortex/32-bit-psoc-edge-arm) parts

## Supported toolchains (make variable 'TOOLCHAIN')

- LLVM Embedded Toolchain for Arm&reg; [v20.0.0](https://github.com/ARM-software/LLVM-embedded-toolchain-for-Arm/releases/tag/preview-20.0.0-devdrop0) (`LLVM_ARM`) - Default value of `TOOLCHAIN`

> **Note:**
> Ensure to use LLVM preview-20.0.0-devdrop0. v19.1.5 does NOT work with this project. 


## Supported kits (make variable 'TARGET')

- [PSOC&trade; Edge E84 AI Kit](https://www.infineon.com/KIT_PSE84_AI) (`KIT_PSE84_AI`)
- [PSOC&trade; Edge E84 Evaluation Kit](https://www.infineon.com/KIT_PSE84_EVAL) (`KIT_PSE84_EVAL_EPC2`)

## Hardware setup

This example uses the board's default configuration. 
See the kit user guide to ensure that the board is configured correctly.

Ensure the following jumper and pin configuration on board.
- BOOT SW must be in the HIGH/ON position
- J20 and J21 must be in the tristate/not connected (NC) position

> **Note:** This hardware setup is not required for KIT_PSE84_AI.

## Setup The Project

To setup the project, please refer to the 
[/IOTCONNECT ModusToolbox&trade; PSOC Edge Developer Guide](DEVELOPER_GUIDE.md)
but note the following exceptions:
 - When installing components with ***ModusToolbox&trade; Setup***, Install **DEEPCRAFT™ Audio Enhancement Tech Pack** version 1.0.0 as well.
 - Install the [LLVM compiler v20.0.0](https://github.com/ARM-software/LLVM-embedded-toolchain-for-Arm/releases/tag/preview-20.0.0-devdrop0)
into a location (use a short path on Windows) like *C:/Infineon/Tools/LLVM-ET-Arm-20.0.0-Windows-x86_64*
 - Set this Environment Variables or set in common_app.mk with the path. 
   - CY_COMPILER_LLVM_ARM_DIR=[path to LLVM compiler location] - use forward slashes as path separator. 
   - For example: *C:/Infineon/Tools/LLVM-ET-Arm-19.1.5-Windows-x86_64*, where  *C:/llvm/LLVM-ET-Arm-19.1.5-Windows-x86_64* contains the *bin* directory form the extracted zip.

If you like to customize the wake word and the spoken commands, you need to have access to the [DEEPCRAFT&trade; Voice-Assistant Cloud tool](https://deepcraft-voice-assistant.infineon.com/) and create your own wake word and spoken commands.

## Running The Demo

This section will focus on running the **Smart Lights Demo** option in the [common.mk](common.mk) with our custom /IOTCONNECT application. 
If running the **LED Demo** or the **Cook Top Demo**, the application will only report the basic voice command events, 
and will not track the light levels.

- Afew seconds after executing the application, the device will connect to /IOTCONNECT, and begin sending telemetry packets similar to the example below:
```
>: {"d":[{"d":{"version":"S-1.1.0","ll_kitchen":0,"ll_bedroom":0,"ll_living_room":10,"event":"","has_event":false,"microphone_active":true}}]}
```

- Speak the wake word "OK Infineon" and one of the commands from this
[list](./proj_cm55/va_models/Smart_Lights_Demo/command_list_Smart_Lights_Demo.txt). 
Note that after speaking the wake word, the kit's blue LED keeps breathing till a timeout occurs or a command is spoken.
- Confirm that the command is printed correctly in the terminal, or at *Live Data* or *Latest Value* panel for your device.
- The application should update the light levels for the appropriate, room like *ll_kitchen* for example,
and transmit the appropriate values along with the spoken prompts to /IOTCONNECT.
- Additionally, the following command can be sent to the device using the /IOTCONNECT Web UI to interact with the device:

    | Command                  | Argument Type     | Description                                                        |
    |:-------------------------|-------------------|:-------------------------------------------------------------------|
    | `board-user-led`         | String (on/off)   | Turn the board LED on or off (Green on the AI Kit, Red on the EVK) |

          