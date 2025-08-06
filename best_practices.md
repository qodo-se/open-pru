# PRU Assembly and C Best Practices Guide
## These best practices will be used as by Qodo Merge as context for evaluation during the Improve stage

## Introduction

This document outlines best practices for developing PRU (Programmable Real-time Unit) firmware for Texas Instruments Sitara devices. The PRU is a deterministic, real-time processor subsystem that provides precise timing control and low-latency I/O operations.

**Supported Devices:**
- AM243x, AM261x, AM263x, AM263px, AM64x series

## General Principles

### 1. Real-time Determinism
- **Predictable Timing**: Every instruction should have predictable execution time
- **Avoid Conditional Branches**: When possible, use unconditional code paths
- **Cycle Counting**: Always document cycle counts for critical code sections
- **Interrupt Handling**: Minimize interrupt latency and processing time

### 2. Resource Management
- **Register Usage**: Efficiently utilize the 32 available registers (R0-R31)
- **Memory Conservation**: PRU has limited memory (8KB instruction, 8KB data)
- **Power Efficiency**: Implement power-saving techniques when appropriate

### 3. Code Maintainability
- **Modular Design**: Use macros and includes for reusable code
- **Clear Documentation**: Document timing requirements and hardware dependencies
- **Version Control**: Follow consistent naming and versioning conventions

## Assembly Code Best Practices
### 1. **Always Validate Memory Boundaries**
Before any memory access, ensure the address is within allocated bounds.

**Example:**
```asm
; Safe memory write with bounds checking
safe_write:
    ; Check if offset is within bounds
    ldi32   TEMP_REG_2, WRITE_OFFSET
    ldi32   TEMP_REG_3, MAX_BUFFER_SIZE
    qbgt    handle_error, TEMP_REG_2, TEMP_REG_3  ; Jump to error if offset > max
    
    ; Safe to write
    add     TEMP_REG_2, TEMP_REG_2, DATA_BUFFER_OFFSET
    sbco    &r_dataReg, c28, TEMP_REG_2, 4
    qba     continue_execution
    
handle_error:
    ; Set error flag and handle gracefully
    ldi     ERROR_REG, ERR_BOUNDS_VIOLATION
    qba     error_handler
```

### 2. **Use Constants for Buffer Limits**
Define and use constants for all memory boundaries.

**Example:**
```asm
; Define memory constants
.define DATA_BUFFER_START    0x1000
.define DATA_BUFFER_SIZE     0x400   ; 1KB buffer
.define DATA_BUFFER_END      0x1400  ; START + SIZE

; Validate access is within [START, END)
validate_address:
    qblt    addr_too_low, TEMP_REG_1, DATA_BUFFER_START
    qbge    addr_too_high, TEMP_REG_1, DATA_BUFFER_END
    ; Address is valid, continue...
```

### 3. **Implement Safe Loop Constructs**
Always include termination conditions and bounds checking in loops.

**Example:**
```asm
; Safe loop with bounds checking
safe_loop_start:
    ldi     LOOP_COUNTER, 0
    ldi     MAX_ITERATIONS, 100
    
loop_body:
    ; Check loop bounds
    qbeq    loop_done, LOOP_COUNTER, MAX_ITERATIONS
    
    ; Calculate safe offset
    lsl     TEMP_OFFSET, LOOP_COUNTER, 2  ; Multiply by 4 for word access
    qbgt    loop_done, TEMP_OFFSET, MAX_BUFFER_SIZE
    
    ; Safe memory access
    add     TEMP_ADDR, DATA_BUFFER_OFFSET, TEMP_OFFSET
    lbco    &dataReg, c28, TEMP_ADDR, 4
    
    ; Process data...
    
    ; Increment and continue
    add     LOOP_COUNTER, LOOP_COUNTER, 1
    qba     loop_body
    
loop_done:
    ; Clean exit
```

### 4. **Use Defensive Programming Techniques**
Add sanity checks and fail-safe mechanisms.

**Example:**
```asm
; Defensive buffer access with multiple checks
secure_buffer_access:
    ; Validate pointer is not null
    qbeq    null_ptr_error, BUFFER_PTR, 0
    
    ; Validate size is reasonable
    ldi32   TEMP_REG_1, MAX_ALLOWED_SIZE
    qbgt    size_error, ACCESS_SIZE, TEMP_REG_1
    
    ; Calculate end address and check for overflow
    add     END_ADDR, BUFFER_PTR, ACCESS_SIZE
    qblt    overflow_error, END_ADDR, BUFFER_PTR  ; Overflow if end < start
    
    ; Verify end address is within bounds
    ldi32   TEMP_REG_2, MEMORY_LIMIT
    qbgt    bounds_error, END_ADDR, TEMP_REG_2
    
    ; All checks passed - safe to access
    lbco    &dataReg, c28, BUFFER_PTR, ACCESS_SIZE
```

### 5. **Document Memory Layout and Constraints**
Clear documentation prevents mistakes.

**Example:**
```asm
;==============================================================================
; Memory Layout:
; 0x0000 - 0x0FFF : Reserved system memory (DO NOT ACCESS)
; 0x1000 - 0x13FF : Data buffer (1KB)
; 0x1400 - 0x17FF : Stack space (1KB)
; 0x1800 - 0x1FFF : Shared memory region (2KB)
;==============================================================================

; Safe accessor macro for data buffer
.macro SAFE_DATA_ACCESS offset, size, dest_reg
    ; Validate offset + size <= buffer size
    ldi32   TEMP_CHECK, \offset + \size
    ldi32   TEMP_LIMIT, DATA_BUFFER_SIZE
    qbgt    memory_fault, TEMP_CHECK, TEMP_LIMIT
    
    ; Perform safe access
    ldi32   TEMP_ADDR, DATA_BUFFER_START + \offset
    lbco    &\dest_reg, c28, TEMP_ADDR, \size
.endm
```

### 6. **Implement Error Recovery**
Handle errors gracefully rather than crashing.

**Example:**
```asm
; Centralized error handler
error_handler:
    ; Log error type
    sbco    &ERROR_REG, c28, ERROR_LOG_ADDR, 4
    
    ; Reset to safe state
    ldi     BUFFER_PTR, DATA_BUFFER_START
    ldi     ACCESS_SIZE, 0
    
    ; Signal error to host
    ldi     r31.b0, PRU_ERROR_SIGNAL
    
    ; Return to safe execution point
    qba     safe_restart_point
```

### 7. **Use Static Analysis Where Possible**
Leverage assembler features to catch errors at build time.

**Example:**
```asm
; Use assembler assertions
.if (BUFFER_OFFSET + MAX_ACCESS_SIZE) > TOTAL_MEMORY_SIZE
    .emsg "Buffer configuration exceeds memory limits"
.endif

; Create safe access patterns
.macro BOUNDS_CHECKED_WRITE reg, offset
    .if (\offset >= MAX_BUFFER_SIZE)
        .emsg "Static bounds check failed: offset too large"
    .endif
    sbco    &\reg, c28, DATA_BUFFER_OFFSET + \offset, 4
.endm
```

### File Structure and Organization

```assembly
; Copyright header (required for TI projects)
; File description and purpose
; Build instructions
; Hardware requirements

; CCS/makefile specific settings
    .retain     ; Required for building .out with assembly file
    .retainrefs ; Required for building .out with assembly file

    .global     main
    .sect       ".text"

; Include files
    .include "icss_constant_defines.inc"
    .include "custom_macros.inc"

; Register aliases for clarity
    .asg    R2,     TEMP_REG
    .asg    R3.w0,  OFFSET_ADDR
    .asg    100000, DELAY_COUNT

; Main program
main:
    ; Implementation
```

### Register Management

#### Register Allocation Strategy
```assembly
; Use consistent register aliases
    .asg    R0,     DATA_REG
    .asg    R1,     COUNTER_REG
    .asg    R2,     TEMP_REG
    .asg    R3,     ADDRESS_REG
    ; R30 - GPO (General Purpose Output)
    ; R31 - GPI (General Purpose Input)
```

#### Register Initialization
```assembly
init:
    ; Always clear register space at startup
    zero    &r0, 120    ; Clear R0-R29 (30 registers × 4 bytes)
    
    ; Initialize specific registers
    ldi     DATA_REG, 0
    ldi     COUNTER_REG, 0
```

### Timing and Performance

#### Cycle Counting Documentation
```assembly
;************************************************************************************
;   Macro: m_delay_cycles
;   
;   PEAK cycles: 3 + DELAY_COUNT cycles
;   
;   Parameters:
;       DELAY_COUNT - Number of cycles to delay
;************************************************************************************
m_delay_cycles .macro DELAY_COUNT
    ldi32   r5, DELAY_COUNT     ; 2 cycles
delay_loop?:
    sub     r5, r5, 1          ; 1 cycle
    qbne    delay_loop?, r5, 0 ; 1 cycle (when branching)
    .endm
```

#### Efficient Loop Structures
```assembly
; Preferred: Down-counting loops (more efficient)
    ldi     COUNTER_REG, LOOP_COUNT
loop_start:
    ; Loop body
    sub     COUNTER_REG, COUNTER_REG, 1
    qbne    loop_start, COUNTER_REG, 0

; Avoid: Up-counting loops (less efficient)
; ldi     COUNTER_REG, 0
; qbge    loop_end, COUNTER_REG, LOOP_COUNT
```

### Macro Design

#### Parameterized Macros
```assembly
;************************************************************************************
;   Macro: m_spi_transfer
;   
;   Description: Transfer data via SPI interface
;   
;   PEAK cycles: (7 + DELAY1 + DELAY2) × PACKET_SIZE
;   
;   Parameters:
;       dataReg     - Register containing data to send
;       PACKET_SIZE - Size of data packet in bits (1-32)
;       SCLK_PIN    - PRU pin number for SCLK
;       DELAY1      - High phase delay cycles
;       DELAY2      - Low phase delay cycles
;   
;   Assumptions:
;       - CS must be asserted before calling
;       - SCLK_PIN configured as output
;       - PACKET_SIZE validated (1-32 bits)
;************************************************************************************
m_spi_transfer .macro dataReg, PACKET_SIZE, SCLK_PIN, DELAY1, DELAY2
    ; Parameter validation
    .if (PACKET_SIZE > 32) | (PACKET_SIZE < 1)
    .emsg "Error: PACKET_SIZE must be 1-32 bits"
    .endif
    
    ; Implementation
    ldi     r10, PACKET_SIZE - 1
transfer_loop?:
    ; Transfer logic here
    .endm
```

#### Macro Naming Conventions
- Prefix with `m_` for macros
- Use descriptive names: `m_spi_read_packet`, `m_gpio_toggle`
- Include parameter validation
- Use unique local labels with `?` suffix

### GPIO and Pin Control

#### Pin Manipulation
```assembly
; Use macros for pin operations
m_pru_set_pin   .macro PIN_NUM
    set     r30, r30, PIN_NUM
    .endm

m_pru_clr_pin   .macro PIN_NUM
    clr     r30, r30, PIN_NUM
    .endm

; Usage
    m_pru_set_pin   4   ; Set GPIO pin 4
    m_pru_clr_pin   4   ; Clear GPIO pin 4
```

#### Pin State Reading
```assembly
; Read input pins from R31
    qbbc    pin_low, r31, PIN_NUM   ; Branch if bit clear
    ; Pin is high
    qba     continue
pin_low:
    ; Pin is low
continue:
```

### Memory Access Patterns

#### Efficient Memory Operations
```assembly
; Use appropriate addressing modes
    lbbo    &r2, r1, 0, 4      ; Load 4 bytes from address in r1
    sbbo    &r2, r1, 0, 4      ; Store 4 bytes to address in r1
    
; Burst operations for multiple bytes
    lbbo    &r2, r1, 0, 16     ; Load 16 bytes (4 registers)
```

## C Code Best Practices

### Host Application Structure

#### Standard Includes and Initialization
```c
#include <stdio.h>
#include <kernel/dpl/DebugP.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include <drivers/pruicss.h>

// Include PRU firmware headers
#include <pru0_load_bin.h>
#include <pru1_load_bin.h>
```

#### Error Handling
```c
void pru_application_main(void *args)
{
    int32_t status;
    
    // Initialize drivers with error checking
    Drivers_open();
    
    status = Board_driversOpen();
    DebugP_assert(SystemP_SUCCESS == status);
    
    // PRU initialization
    gPruIcssHandle = PRUICSS_open(CONFIG_PRU_ICSS0);
    DebugP_assert(gPruIcssHandle != NULL);
    
    // Memory initialization
    status = PRUICSS_initMemory(gPruIcssHandle, PRUICSS_DATARAM(PRUICSS_PRU0));
    DebugP_assert(status != 0);
    
    // Firmware loading with size validation
    status = PRUICSS_loadFirmware(gPruIcssHandle, PRUICSS_PRU0, 
                                  PRU0Firmware_0, sizeof(PRU0Firmware_0));
    DebugP_assert(SystemP_SUCCESS == status);
}
```

#### Resource Management
```c
// Always clean up resources
void cleanup_resources(void)
{
    if (gPruIcssHandle != NULL) {
        PRUICSS_close(gPruIcssHandle);
    }
    Board_driversClose();
    Drivers_close();
}
```

### PRU Communication

#### Shared Memory Access
```c
// Define shared memory structures
typedef struct {
    uint32_t command;
    uint32_t data[16];
    uint32_t status;
} pru_shared_mem_t;

// Access shared memory safely
void write_pru_command(uint32_t command, uint32_t *data, uint32_t length)
{
    volatile pru_shared_mem_t *shared_mem = 
        (volatile pru_shared_mem_t *)PRUICSS_getSharedMemAddr(gPruIcssHandle);
    
    // Write data first
    for (uint32_t i = 0; i < length && i < 16; i++) {
        shared_mem->data[i] = data[i];
    }
    
    // Write command last to trigger PRU processing
    shared_mem->command = command;
}
```

## Project Structure

### Directory Organization
```
project_name/
├── .project/                   # Build configuration
│   ├── project.js
│   └── project_device.js
├── firmware/                   # PRU firmware
│   ├── main.asm               # Main assembly file
│   ├── macros.inc             # Custom macros
│   └── device_specific/       # Device-specific code
├── host_app/                  # R5F/A53 application
│   └── main.c
├── include/                   # Shared headers
├── docs/                      # Documentation
└── README.md
```

### File Naming Conventions
- Assembly files: `main.asm`, `spi_driver.asm`
- Include files: `custom_macros.inc`, `register_defines.inc`
- C files: `pru_application.c`, `spi_interface.c`
- Use lowercase with underscores

## Performance Optimization

### Critical Path Optimization

#### Minimize Branch Instructions
```assembly
; Preferred: Branchless code
    qbbc    skip_set, r31, INPUT_PIN
    set     r30, r30, OUTPUT_PIN
skip_set:
    clr     r30, r30, OUTPUT_PIN

; Instead of multiple conditional branches
```

#### Loop Unrolling for Critical Sections
```assembly
; For small, fixed iteration counts
    ; Unrolled loop (4 iterations)
    operation_macro PARAM1
    operation_macro PARAM2
    operation_macro PARAM3
    operation_macro PARAM4

; Instead of:
;   ldi r1, 4
; loop:
;   operation_macro
;   sub r1, r1, 1
;   qbne loop, r1, 0
```

### Memory Access Optimization

#### Burst Transfers
```assembly
; Load multiple registers in one operation
    lbbo    &r2, r1, 0, 16      ; Load r2, r3, r4, r5 (16 bytes)
    
; Instead of individual loads
;   lbbo    &r2, r1, 0, 4
;   lbbo    &r3, r1, 4, 4
;   lbbo    &r4, r1, 8, 4
;   lbbo    &r5, r1, 12, 4
```

## Debugging and Testing

### Debug Strategies

#### Instrumentation Points
```assembly
; Add debug outputs for timing analysis
debug_point_1:
    set     r30, r30, DEBUG_PIN_1   ; Mark start of critical section
    ; Critical code here
    clr     r30, r30, DEBUG_PIN_1   ; Mark end of critical section
```

#### Register State Logging
```c
// In host application
void log_pru_registers(void)
{
    uint32_t *pru_regs = (uint32_t *)PRUICSS_getDataMemAddr(gPruIcssHandle, PRUICSS_PRU0);
    
    DebugP_log("PRU Register Dump:\n");
    for (int i = 0; i < 30; i++) {
        DebugP_log("R%d: 0x%08x\n", i, pru_regs[i]);
    }
}
```

### Testing Framework

#### Unit Testing Macros
```assembly
; Test macro for validation
m_test_assert .macro condition, error_code
    .if condition
    ; Test passed
    .else
    ldi     r30.b0, error_code
    halt
    .endif
    .endm
```

## Documentation Standards

### File Headers
```assembly
;************************************************************************************
;   File:     filename.asm
;   
;   Brief:    Brief description of file purpose
;   
;   Author:   Developer Name
;   Date:     YYYY-MM-DD
;   Version:  X.Y.Z
;   
;   Hardware: Supported devices (AM243x, AM64x, etc.)
;   
;   Dependencies:
;       - icss_constant_defines.inc
;       - custom_macros.inc
;   
;   Build Instructions:
;       CCS: Import project and build
;       Makefile: make -C firmware all
;   
;   Performance:
;       Critical path: X cycles
;       Memory usage: Y bytes
;       
;   Notes:
;       - Special considerations
;       - Known limitations
;************************************************************************************
```

### Function/Macro Documentation
```assembly
;************************************************************************************
;   Macro: m_function_name
;   
;   Description:
;       Detailed description of what the macro does
;   
;   PEAK cycles: X cycles (breakdown if complex)
;   Memory usage: Y bytes
;   
;   Parameters:
;       param1 - Description and valid range
;       param2 - Description and constraints
;   
;   Returns:
;       Description of return values or side effects
;   
;   Assumptions:
;       - List all assumptions about system state
;       - Hardware configuration requirements
;       - Register usage assumptions
;   
;   Side Effects:
;       - Modified registers
;       - Changed pin states
;       - Memory modifications
;   
;   Example:
;       m_function_name r1, 8, PIN_4
;************************************************************************************
```

## Common Pitfalls

### Assembly Code Pitfalls

#### 1. Register Corruption
```assembly
; Problem: Not preserving registers
function_call:
    ; Using r1 without saving
    ldi     r1, 0x1234
    ; ... function body
    jmp     r3.w2

; Solution: Save and restore registers
function_call:
    ; Save registers on stack or in unused registers
    mov     r29, r1         ; Save r1
    ldi     r1, 0x1234
    ; ... function body
    mov     r1, r29         ; Restore r1
    jmp     r3.w2
```

#### 2. Timing Assumptions
```assembly
; Problem: Assuming fixed timing without measurement
delay_loop:
    sub     r1, r1, 1
    qbne    delay_loop, r1, 0
    ; Assuming this takes exactly X microseconds

; Solution: Measure and document actual timing
; Measured timing: 3 cycles per iteration at 200MHz = 15ns per iteration
delay_loop:
    sub     r1, r1, 1      ; 1 cycle
    qbne    delay_loop, r1, 0  ; 2 cycles when branching
```

#### 3. Macro Parameter Validation
```assembly
; Problem: No parameter validation
m_bad_macro .macro PARAM
    ldi     r1, PARAM
    .endm

; Solution: Always validate parameters
m_good_macro .macro PARAM
    .if (PARAM > MAX_VALUE) | (PARAM < MIN_VALUE)
    .emsg "Error: PARAM out of range"
    .endif
    ldi     r1, PARAM
    .endm
```

### C Code Pitfalls

#### 1. Shared Memory Race Conditions
```c
// Problem: Race condition in shared memory access
shared_mem->data = new_value;
shared_mem->flag = 1;  // PRU might read old data

// Solution: Use proper ordering and barriers
shared_mem->data = new_value;
__sync_synchronize();  // Memory barrier
shared_mem->flag = 1;
```

#### 2. Resource Leaks
```c
// Problem: Not cleaning up on error paths
int init_pru(void) {
    handle = PRUICSS_open(CONFIG_PRU_ICSS0);
    if (some_error_condition) {
        return -1;  // Leaked handle!
    }
    return 0;
}

// Solution: Proper cleanup
int init_pru(void) {
    handle = PRUICSS_open(CONFIG_PRU_ICSS0);
    if (some_error_condition) {
        PRUICSS_close(handle);
        return -1;
    }
    return 0;
}
```

### General Pitfalls

#### 1. Inadequate Testing
- **Problem**: Testing only happy path scenarios
- **Solution**: Test edge cases, error conditions, and boundary values

#### 2. Poor Version Control
- **Problem**: No clear versioning or change tracking
- **Solution**: Use semantic versioning and detailed commit messages

#### 3. Insufficient Documentation
- **Problem**: Code without timing specifications or hardware requirements
- **Solution**: Document all timing-critical sections and hardware dependencies

---




