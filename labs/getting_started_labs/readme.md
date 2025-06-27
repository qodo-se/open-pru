# Getting Started Labs

## Introduction

For documentation on the Getting Started Labs, please reference
the PRU Academy Getting Started Labs Section. TODO:Insert link when PRU academy goes public.

The PRU Getting Started Labs apply to the PRU on AM64x.
The Getting Started Labs demonstrate how to compile PRU firmware that is written
in C, assembly, or mixed C and assembly. Steps are provided for compiling the
firmware from the terminal within the OpenPRU repository, or from Code Composer Studio (CCS).

The Getting Started Labs also demonstrate how to initialize the PRU from CCS,
another processor core running Linux, another processor core running RTOS, or
another processor core that runs bare metal code (no OS).

# Supported Combinations

 Parameter      | Value
 ---------------|-----------
 ICSSG          | ICSSG0 - PRU0, PRU1, RTU0, RTU1, TX_PRU0,TX_PRU1
 Toolchain      | pru-cgt
 Board          | am64x-evm

# Steps to Run the Example

> Prerequisite: [PRU-CGT-2-3](https://www.ti.com/tool/PRU-CGT) (ti-pru-cgt) should be installed at: `C:/ti/`

- **When using CCS projects to build**, import the CCS project from the above mentioned Example folder path for R5F(if applicable) and PRU, After this `main.asm`, `linker.cmd` files gets copied to ccs workspace of PRU project. The `main.asm` contains sample code to halt PRU program

     - Build the PRU project using the CCS project menu (see [for AM64x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/CCS_PROJECTS_PAGE.html), [for AM243x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM243X/latest/exports/docs/api_guide_am243x/CCS_PROJECTS_PAGE.html), [for AM261x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM261X/latest/exports/docs/api_guide_am261x/CCS_PROJECTS_PAGE.html), [for AM263x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM263X/latest/exports/docs/api_guide_am263x/CCS_PROJECTS_PAGE.html), [for AM263Px](https://software-dl.ti.com/mcu-plus-sdk/esd/AM263PX/latest/exports/docs/api_guide_am263px/CCS_PROJECTS_PAGE.html)).
          - Build Flow: Once you click on build in PRU project, firmware header file which is generated in release or debug folder of ccs workspace, is moved to  `<open-pru/examples/pru_io/empty/firmware/device/>`

     - Build the R5F project using the CCS project menu (see [for AM64x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/CCS_PROJECTS_PAGE.html), [for AM243x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM243X/latest/exports/docs/api_guide_am243x/CCS_PROJECTS_PAGE.html), [for AM261x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM261X/latest/exports/docs/api_guide_am261x/CCS_PROJECTS_PAGE.html), [for AM263x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM263X/latest/exports/docs/api_guide_am263x/CCS_PROJECTS_PAGE.html), [for AM263Px](https://software-dl.ti.com/mcu-plus-sdk/esd/AM263PX/latest/exports/docs/api_guide_am263px/CCS_PROJECTS_PAGE.html)).
          - Firmware header file path is included in R5F project include options by default, Instructions in Firmware header file can be written into PRU IRAM memory using PRUICSS_loadFirmware API (see [for AM64x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/group__DRV__PRUICSS__MODULE.html#ga3e7c763e5343fe98f7011f388a0b7ffe), [for AM243x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM243X/latest/exports/docs/api_guide_am243x/group__DRV__PRUICSS__MODULE.html#ga3e7c763e5343fe98f7011f388a0b7ffe), [for AM261x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM261X/latest/exports/docs/api_guide_am261x/group__DRV__PRUICSS__MODULE.html#ga3e7c763e5343fe98f7011f388a0b7ffe), [for AM263x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM263X/latest/exports/docs/api_guide_am263x/group__DRV__PRUICSS__MODULE.html#ga3e7c763e5343fe98f7011f388a0b7ffe), [for AM263Px](https://software-dl.ti.com/mcu-plus-sdk/esd/AM263PX/latest/exports/docs/api_guide_am263px/group__DRV__PRUICSS__MODULE.html#ga3e7c763e5343fe98f7011f388a0b7ffe))
          - Build Flow: Once you click on build in R5F project, SysConfig files are generated, Finally the R5F project will be generated using both the generated SysConfig and PRU project binaries.

     - Launch a CCS debug session and run the executable, (see [for AM64x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/CCS_LAUNCH_PAGE.html), [for AM243x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM243X/latest/exports/docs/api_guide_am243x/CCS_LAUNCH_PAGE.html), [for AM261x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM261X/latest/exports/docs/api_guide_am261x/CCS_LAUNCH_PAGE.html), [for AM263x](https://software-dl.ti.com/mcu-plus-sdk/esd/AM263X/latest/exports/docs/api_guide_am263x/CCS_LAUNCH_PAGE.html), [for AM263Px](https://software-dl.ti.com/mcu-plus-sdk/esd/AM263PX/latest/exports/docs/api_guide_am263px/CCS_LAUNCH_PAGE.html))

- **When using makefiles to build**, make sure to build the PRU firmware before attempting to build an example. To build the PRU firmware for the labs For example, to build a PRU firmware lab, do the following:
     -    Add the path of the project.js file to example_file_list in <PATH_TO_OPEN_PRU>/.project/device/project_{device}.js, it should look similar to below
          ```
          const example_file_list = [
               /*NOTE: Always add PRU firware project first to ensure R5F picks latest firmware header when all examples are built at once using makefile*/
               "examples/empty/firmware/.project/project.js",
               "examples/empty/.project/project.js",
               "labs/getting_started_labs/<LAB_TO_BUILD>/firmware/.project/project.js"
          ];
          ```

          - If the lab has R5 code, add the path to the project.js file to the example_file_list as well. This will be the same file list minus the firmware directory (e.g. `labs/getting_started_labs/<LAB_TO_BUILD>/.project/project.js`).

     -    Generate build files for the target device.
          ```
          make gen-buildfiles DEVICE=<DEVICE> MCU_PLUS_SDK_PATH=<MCU_PLUS_SDK_INSTALL_PATH>
          ```   
     -    update MCU_PLUS_SDK_PATH in `<open-pru/makefile>` and `<open-pru/imports.mak>` 

     -    Build the lab 
          ```bash
          make -s -C examples/labs/getting_started_labs/<LAB_TO_BUILD>/firmware/<DEVICE>/icss_g0_pru0_fw/ti-pru-cgt     all 
          make -s -C examples/labs/getting_started_labs/<LAB_TO_BUILD>/firmware/<DEVICE>/icss_g0_pru1_fw/ti-pru-cgt     all 
          make -s -C examples/labs/getting_started_labs/<LAB_TO_BUILD>/firmware/<DEVICE>/icss_g0_rtu_pru0_fw/ti-pru-cgt all
          make -s -C examples/labs/getting_started_labs/<LAB_TO_BUILD>/firmware/<DEVICE>/icss_g0_rtu_pru1_fw/ti-pru-cgt all
          make -s -C examples/labs/getting_started_labs/<LAB_TO_BUILD>/firmware/<DEVICE>/icss_g0_tx_pru0_fw/ti-pru-cgt  all
          make -s -C examples/labs/getting_started_labs/<LAB_TO_BUILD>/firmware/<DEVICE>/icss_g0_tx_pru1_fw/ti-pru-cgt  all
          ```
     -    For labs containting RTOS code, once the PRU Firmware build is complete, to build the lab run:
          ```bash
          make -s -C examples/labs/getting_started_labs/<LAB_TO_BUILD>
          /<DEVICE>/r5fss0-0_freertos/ti-arm-clang all PROFILE=debug
          ```


# Writing PRU code

* The main.asm files have TODOs in them so they are incomplete for the purpose of learning and interacting with the labs. If the user wishes to build a complete project and run it - complete the TODOs in the main.asm file. The solution can be seen in the solution folder inside of the firmware directory of the lab of choice. Use this for guidance if needed.*
