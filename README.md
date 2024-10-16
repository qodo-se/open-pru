<div align="center">

<img src="https://upload.wikimedia.org/wikipedia/commons/b/ba/TexasInstruments-Logo.svg" width="150"><br/>
# OPEN PRU

[Introduction](#introduction) | [Features](#features) | [Overview](#overview) | [Learn](#learn) | [Usage](#usage) | [Contribute](#contributing-to-the-project)

</div>

## Introduction

OPEN PRU is a software development package designed for usage with PRU processor from Texas Instruments Sitara devices and Jacinto class of devices. These devices currently include

- [AM2431](https://www.ti.com/product/AM2431), [AM2432](https://www.ti.com/product/AM2432), [AM2434](https://www.ti.com/product/AM2434)
- [AM6411](https://www.ti.com/product/AM6411), [AM6412](https://www.ti.com/product/AM6412), [AM6421](https://www.ti.com/product/AM6421), [AM6422](https://www.ti.com/product/AM6422), [AM6441](https://www.ti.com/product/AM6441), [AM6442](https://www.ti.com/product/AM6442)

OPEN PRU is designed with user experience and simplicity in mind. The repository includes out-of-box Getting started PRU labs, Macro definitions and application examples.

## Features

- Out of Box Getting started labs, Macro definitions and application Examples
  - [PRU Academy](./pru_academy): Task manager, Interrupt controller, Broadside accelerator, Labs etc.,
  - [Application examples](./examples): ADC, SENT, I2C, I2S etc.,
  - [Macro definitions](./source) of PRUSS, PRUICSSM, PRUICSSG components

## Overview

The MCU+ SDK is a dependency when building OPEN PRU projects that include code for an MCU+ core, Users can use Prebuilt SDK installers for specific devices or clone MCU+ SDK repository


#### Option1 : Prebuilt SDK installers for specific devices are available at below links. Please note that installers are packaged specific to each device to reduce size.

- [AM243x MCU+ SDK](https://www.ti.com/tool/MCU-PLUS-SDK-AM243X)
- [AM64x  MCU+ SDK](https://www.ti.com/tool/MCU-PLUS-SDK-AM64X)

#### Option2 : MCU+ SDK repostiory is core for all the Sitara MCU and MPU devices, checkout README.md to clone
- [MCU PLUS SDK](https://github.com/TexasInstruments/mcupsdk-core)
- when MCU+ SDK repostiory is used, it is required to run below command to switch MCU PLUS SDK product to development mode
   ```bash
   make gen-buildfiles DEVICE=am64x GEN_BUILDFILES_TARGET=development
   make gen-buildfiles DEVICE=am243x   GEN_BUILDFILES_TARGET=development
   ```

## Learn

TI has an amazing collection of tutorials as PRU Academy to help you get started.

- [PRU getting_started](./pru_academy/getting_started)

## Usage

### Prerequisites

#### Supported HOST environments

- Validated on Windows 10 64bit, higher versions may work
- Validated on Ubuntu 18.04 64bit, higher versions may work

**In windows the dependencies has to be manually installed. Given below are the steps**:

1. Download and install Code Composer Studio v12.8 from [here](https://www.ti.com/tool/download/CCSTUDIO "Code Composer Studio")
   - Install at default folder, C:\ti

2. Download and install SysConfig 1.21.0 from [here](https://www.ti.com/tool/download/SYSCONFIG "SYSCONFIG 1.21.0")
   - Install at default folder, C:/ti

3. Download and intall PRU compiler
   - [PRU-CGT-2-3](https://www.ti.com/tool/PRU-CGT) (ti-pru-cgt)
   - Install at default folder, C:/ti

4. Download and install GCC for Cortex A53 (only needed for AM64x developers)
   - [GNU-A](https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-mingw-w64-i686-aarch64-none-elf.tar.xz)
   - [GNU-RM](https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2017q4/gcc-arm-none-eabi-7-2017-q4-major-win32.zip)
   - Install at default folder, C:/ti


### Building the examples 


#### Basic Building With Makefiles

---

**NOTE**

- Use `gmake` in windows, add path to gmake present in CCS at `C:\ti\ccsxxxx\ccs\utils\bin` to your windows PATH. We have
  used `make` in below instructions.
- Unless mentioned otherwise, all below commands are invoked from root folder of the "open-pru"  repository.
- Current supported device names are am64x, am243x
- Pass one of these values to `"DEVICE="`
- You can also build components (examples, tests or libraries) in `release` or `debug`
  profiles. To do this pass one of these values to `"PROFILE="`

---

1. Update MCU_PLUS_SDK_PATH in [makefile](./makefile) and [imports.mak](./imports.mak) 

2. Make sure to build the PRU firmware before attempting to build an example. For example,
   to build a PRU firmware for empty example of AM243x, run the following:
   ```bash
	make -s -C examples/empty/firmware/am243x-lp/icss_g0_pru0_fw/ti-pru-cgt     all 
	make -s -C examples/empty/firmware/am243x-lp/icss_g0_pru1_fw/ti-pru-cgt     all 
	make -s -C examples/empty/firmware/am243x-lp/icss_g0_rtu_pru0_fw/ti-pru-cgt all
	make -s -C examples/empty/firmware/am243x-lp/icss_g0_rtu_pru1_fw/ti-pru-cgt all
	make -s -C examples/empty/firmware/am243x-lp/icss_g0_tx_pru0_fw/ti-pru-cgt  all
	make -s -C examples/empty/firmware/am243x-lp/icss_g0_tx_pru1_fw/ti-pru-cgt  all
   ```
   Once the PRU Firmware build is complete, Firmware header files of PRU are moved to R5F default include path, to build R5F example run:
   ```bash
   make -s -C examples/empty/am243x-lp/r5fss0-0_freertos/ti-arm-clang all PROFILE=debug
   ```

3. Following are the commands to build **all examples**. Valid PROFILE's are "release" or "debug"

   ```bash
   make -s -j4 clean DEVICE=am243x PROFILE=debug
   make -s -j4 all   DEVICE=am243x PROFILE=debug
   ```

#### Basic Building With CCS

- **When using CCS projects to build**, import the CCS project from the above mentioned Example folder path for R5F and PRU, After this `main.asm`, `linker.cmd` files gets copied to ccs workspace of PRU project.

- Build the PRU project using the CCS project menu (see [for AM64x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/CCS_PROJECTS_PAGE.html), [for AM243x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM243X/latest/exports/docs/api_guide_am243x/CCS_PROJECTS_PAGE.html)).
     - Build Flow: Once you click on build in PRU project, firmware header file which is generated in release or debug folder of ccs workspace, is moved to  `<open-pru/examples/pru_io/empty/firmware/device/>`

- Build the R5F project using the CCS project menu (see [for AM64x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/CCS_PROJECTS_PAGE.html), [for AM243x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM243X/latest/exports/docs/api_guide_am243x/CCS_PROJECTS_PAGE.html)).
     - Firmware header file path is included in R5F project include options by default, Instructions in Firmware header file can be written into PRU IRAM memory using PRUICSS_loadFirmware API (see [for AM64x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/group__DRV__PRUICSS__MODULE.html#ga3e7c763e5343fe98f7011f388a0b7ffe), [for AM243x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM243X/latest/exports/docs/api_guide_am243x/group__DRV__PRUICSS__MODULE.html#ga3e7c763e5343fe98f7011f388a0b7ffe))
     - Build Flow: Once you click on build in R5F project, SysConfig files are generated, Finally the R5F project will be generated using both the generated SysConfig and PRU project binaries.

### More information on Board usage

For more details on Board usage, please refer to the Getting started section of MCU+ SDK README_FIRST_*.html page. User guides contain information on
  
- EVM setup
- CCS Setup, loading and running examples
- Flashing the EVM
- SBL, ROV and much more.

Getting started guides of MCU+ SDK are specific to a particular device. The links for all the supported devices are given below

- [AM243x Getting Started Guide](https://software-dl.ti.com/mcu-plus-sdk/esd/AM243X/latest/exports/docs/api_guide_am243x/GETTING_STARTED.html)
- [AM64x  Getting Started Guide](https://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/GETTING_STARTED.html)

## Technical Support

Please consider creating a post on [TI's E2E forum](https://e2e.ti.com/)

## Contributing to the project

This project is currently not accepting contributions. Coming Soon!


