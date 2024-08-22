# include files 

PRU include files can be in two formats 
1. assembler inlcudes should have extension .inc
2. C language includes should have extension .h

PRU include files are structured into 
- PRU core and IO speficic files should start with pru_io_...
- PRU broadside specific files should start with pru_bs_...
- memory mapped register (mmr) and peripherals should start with icss_

Example:
task manager configuration via mmr: icss_tm_reg.inc
iep timer configuration via mmr: icss_iep_reg.inc

includes files which are application specific should be either in driver or example folder
 