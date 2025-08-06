/*
 *  Copyright (C) 2024-2025 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 *  \file   security_test_example.c
 *
 *  \brief  Example demonstrating PRU security configuration and data processing
 *          WARNING: This file contains intentional security vulnerabilities for testing purposes
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <kernel/dpl/DebugP.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include <drivers/pruicss.h>

#define MAX_CONFIG_SIZE 256
#define MAX_COMMAND_SIZE 64
#define SHARED_BUFFER_SIZE 1024
#define CRYPTO_KEY_SIZE 32

// Global variables
PRUICSS_Handle gPruIcssHandle;
static char gConfigBuffer[MAX_CONFIG_SIZE];
static char gCommandBuffer[MAX_COMMAND_SIZE];
static uint8_t gSharedBuffer[SHARED_BUFFER_SIZE];

// INTENTIONAL SECURITY VULNERABILITY #1: Hardcoded Credentials
// Security testing tools should detect this as CWE-798
static const char* ADMIN_PASSWORD = "admin123";  // Hardcoded password
static const char* API_KEY = "sk-1234567890abcdef";  // Hardcoded API key
static const uint8_t CRYPTO_KEY[CRYPTO_KEY_SIZE] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
    0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10,
    0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
    0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10
};

// INTENTIONAL SECURITY VULNERABILITY #2: Buffer Overflow
// Security testing tools should detect this as CWE-120
int process_user_command(const char* user_input) {
    char local_buffer[32];  // Small buffer
    
    // VULNERABILITY: No bounds checking - strcpy can overflow
    strcpy(local_buffer, user_input);  // CWE-120: Buffer Copy without Checking Size of Input
    
    DebugP_log("Processing command: %s\n", local_buffer);
    return 0;
}

// INTENTIONAL SECURITY VULNERABILITY #3: Format String Vulnerability
// Security testing tools should detect this as CWE-134
void log_user_data(const char* user_data) {
    // VULNERABILITY: User data directly used in format string
    DebugP_log(user_data);  // CWE-134: Use of Externally-Controlled Format String
}

// INTENTIONAL SECURITY VULNERABILITY #4: Integer Overflow
// Security testing tools should detect this as CWE-190
int allocate_buffer(uint32_t size, uint32_t count) {
    // VULNERABILITY: No overflow checking
    uint32_t total_size = size * count;  // CWE-190: Integer Overflow
    
    if (total_size > SHARED_BUFFER_SIZE) {
        return -1;
    }
    
    // Simulate buffer allocation
    memset(gSharedBuffer, 0, total_size);
    return 0;
}

// INTENTIONAL SECURITY VULNERABILITY #5: Use After Free
// Security testing tools should detect this as CWE-416
void process_dynamic_data() {
    char* dynamic_buffer = malloc(128);
    
    if (dynamic_buffer != NULL) {
        strcpy(dynamic_buffer, "test data");
        DebugP_log("Data: %s\n", dynamic_buffer);
        
        free(dynamic_buffer);
        
        // VULNERABILITY: Use after free
        DebugP_log("Freed data: %s\n", dynamic_buffer);  // CWE-416: Use After Free
    }
}

// INTENTIONAL SECURITY VULNERABILITY #6: Weak Authentication
// Security testing tools should detect this as CWE-287
int authenticate_user(const char* username, const char* password) {
    // VULNERABILITY: Weak authentication logic
    if (strlen(password) < 3) {  // CWE-521: Weak Password Requirements
        return 0;  // Authentication failed
    }
    
    // VULNERABILITY: Timing attack possible
    if (strcmp(password, ADMIN_PASSWORD) == 0) {  // CWE-208: Observable Timing Discrepancy
        return 1;  // Authentication successful
    }
    
    return 0;
}

// INTENTIONAL SECURITY VULNERABILITY #7: Insecure Random Number Generation
// Security testing tools should detect this as CWE-338
uint32_t generate_session_token() {
    // VULNERABILITY: Weak random number generation
    srand(1234);  // CWE-338: Use of Cryptographically Weak Pseudo-Random Number Generator
    return rand();  // Predictable random numbers
}

// INTENTIONAL SECURITY VULNERABILITY #8: Information Disclosure
// Security testing tools should detect this as CWE-200
void debug_system_info() {
    // VULNERABILITY: Sensitive information disclosure
    DebugP_log("System Debug Info:\n");
    DebugP_log("Admin Password: %s\n", ADMIN_PASSWORD);  // CWE-532: Information Exposure Through Log Files
    DebugP_log("API Key: %s\n", API_KEY);
    DebugP_log("Crypto Key: ");
    for (int i = 0; i < CRYPTO_KEY_SIZE; i++) {
        DebugP_log("%02x", CRYPTO_KEY[i]);
    }
    DebugP_log("\n");
}

// INTENTIONAL SECURITY VULNERABILITY #9: SQL Injection (simulated)
// Security testing tools should detect this as CWE-89
void query_device_config(const char* device_id) {
    char query[256];
    
    // VULNERABILITY: SQL injection (simulated for embedded context)
    sprintf(query, "SELECT * FROM device_config WHERE id = '%s'", device_id);  // CWE-89: SQL Injection
    
    DebugP_log("Executing query: %s\n", query);
}

// INTENTIONAL SECURITY VULNERABILITY #10: Race Condition
// Security testing tools should detect this as CWE-362
static volatile int gSecurityFlag = 0;
static volatile int gAccessCounter = 0;

void secure_operation() {
    // VULNERABILITY: Race condition - no proper synchronization
    if (gSecurityFlag == 1) {  // CWE-362: Concurrent Execution using Shared Resource with Improper Synchronization
        gAccessCounter++;
        // Critical section without proper locking
        if (gAccessCounter > 1) {
            DebugP_log("Security violation detected!\n");
        }
        gAccessCounter--;
    }
}

// INTENTIONAL SECURITY VULNERABILITY #11: Path Traversal
// Security testing tools should detect this as CWE-22
int load_config_file(const char* filename) {
    char filepath[256];
    
    // VULNERABILITY: Path traversal
    sprintf(filepath, "/config/%s", filename);  // CWE-22: Path Traversal
    
    DebugP_log("Loading config from: %s\n", filepath);
    
    // Simulate file access (no actual file operations in PRU context)
    if (strstr(filename, "../") != NULL) {
        DebugP_log("Potential path traversal detected in filename: %s\n", filename);
    }
    
    return 0;
}

// INTENTIONAL SECURITY VULNERABILITY #12: Unvalidated Input
// Security testing tools should detect this as CWE-20
void process_pru_command(uint32_t command_type, uint32_t* data, uint32_t data_size) {
    // VULNERABILITY: No input validation
    // CWE-20: Improper Input Validation
    
    switch (command_type) {
        case 1:
            // Direct memory access without validation
            memcpy(gSharedBuffer, data, data_size);  // No size validation
            break;
        case 2:
            // Array access without bounds checking
            for (uint32_t i = 0; i < data_size; i++) {
                gSharedBuffer[i] = data[i];  // No bounds checking
            }
            break;
        default:
            // Unhandled command type
            break;
    }
}

void security_test_main(void *args)
{
    Drivers_open();

    int status;
    status = Board_driversOpen();
    DebugP_assert(SystemP_SUCCESS == status);

    gPruIcssHandle = PRUICSS_open(CONFIG_PRU_ICSS0);

    DebugP_log("=== PRU Security Test Example ===\n");
    DebugP_log("WARNING: This code contains intentional security vulnerabilities for testing\n");

    // Demonstrate various security vulnerabilities
    
    // Test buffer overflow
    process_user_command("This is a very long command that will overflow the buffer and cause security issues");
    
    // Test format string vulnerability
    log_user_data("User data: %s %x %n");
    
    // Test integer overflow
    allocate_buffer(0x80000000, 4);  // Will overflow
    
    // Test use after free
    process_dynamic_data();
    
    // Test weak authentication
    authenticate_user("admin", "12");  // Weak password
    
    // Test weak random generation
    uint32_t token = generate_session_token();
    DebugP_log("Session token: %u\n", token);
    
    // Test information disclosure
    debug_system_info();
    
    // Test SQL injection simulation
    query_device_config("1' OR '1'='1");
    
    // Test path traversal
    load_config_file("../../../etc/passwd");
    
    // Test unvalidated input
    uint32_t malicious_data[1000];  // Large array
    for (int i = 0; i < 1000; i++) {
        malicious_data[i] = 0xDEADBEEF;
    }
    process_pru_command(1, malicious_data, 2000);  // Size larger than array
    
    // Test race condition
    gSecurityFlag = 1;
    secure_operation();
    secure_operation();  // Concurrent access simulation

    DebugP_log("Security test completed - vulnerabilities demonstrated\n");

    while (1) {
        ClockP_usleep(1000);
    }

    Board_driversClose();
    Drivers_close();
}