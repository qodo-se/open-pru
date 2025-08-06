# Security Vulnerabilities Inserted for Testing

## Overview

I have intentionally inserted multiple common security vulnerabilities into the codebase to demonstrate how security testing suites can detect critical security issues. These vulnerabilities represent real-world security problems that are commonly found in embedded systems and should be caught by comprehensive security testing tools.

## Vulnerabilities Inserted

### 1. **Comprehensive Security Test Example**

**File**: `examples/security_test_example.c` (NEW FILE)

This file contains **12 different types of security vulnerabilities** commonly found in embedded systems:

#### CWE-798: Hardcoded Credentials
```c
static const char* ADMIN_PASSWORD = "admin123";  // Hardcoded password
static const char* API_KEY = "sk-1234567890abcdef";  // Hardcoded API key
static const uint8_t CRYPTO_KEY[CRYPTO_KEY_SIZE] = { /* hardcoded key */ };
```

#### CWE-120: Buffer Copy without Checking Size of Input
```c
int process_user_command(const char* user_input) {
    char local_buffer[32];  // Small buffer
    strcpy(local_buffer, user_input);  // No bounds checking
    return 0;
}
```

#### CWE-134: Use of Externally-Controlled Format String
```c
void log_user_data(const char* user_data) {
    DebugP_log(user_data);  // User data directly used in format string
}
```

#### CWE-190: Integer Overflow
```c
int allocate_buffer(uint32_t size, uint32_t count) {
    uint32_t total_size = size * count;  // No overflow checking
    return 0;
}
```

#### CWE-416: Use After Free
```c
void process_dynamic_data() {
    char* dynamic_buffer = malloc(128);
    free(dynamic_buffer);
    DebugP_log("Freed data: %s\n", dynamic_buffer);  // Use after free
}
```

#### CWE-287: Improper Authentication
```c
int authenticate_user(const char* username, const char* password) {
    if (strlen(password) < 3) {  // Weak password requirements
        return 0;
    }
    if (strcmp(password, ADMIN_PASSWORD) == 0) {  // Timing attack possible
        return 1;
    }
    return 0;
}
```

#### CWE-338: Use of Cryptographically Weak Pseudo-Random Number Generator
```c
uint32_t generate_session_token() {
    srand(1234);  // Weak random number generation
    return rand();  // Predictable random numbers
}
```

#### CWE-532: Information Exposure Through Log Files
```c
void debug_system_info() {
    DebugP_log("Admin Password: %s\n", ADMIN_PASSWORD);  // Sensitive info in logs
    DebugP_log("API Key: %s\n", API_KEY);
}
```

#### CWE-89: SQL Injection (Simulated)
```c
void query_device_config(const char* device_id) {
    char query[256];
    sprintf(query, "SELECT * FROM device_config WHERE id = '%s'", device_id);
}
```

#### CWE-362: Race Condition
```c
static volatile int gSecurityFlag = 0;
static volatile int gAccessCounter = 0;

void secure_operation() {
    if (gSecurityFlag == 1) {  // No proper synchronization
        gAccessCounter++;
        // Critical section without proper locking
        gAccessCounter--;
    }
}
```

#### CWE-22: Path Traversal
```c
int load_config_file(const char* filename) {
    char filepath[256];
    sprintf(filepath, "/config/%s", filename);  // No path validation
    return 0;
}
```

#### CWE-20: Improper Input Validation
```c
void process_pru_command(uint32_t command_type, uint32_t* data, uint32_t data_size) {
    switch (command_type) {
        case 1:
            memcpy(gSharedBuffer, data, data_size);  // No size validation
            break;
        case 2:
            for (uint32_t i = 0; i < data_size; i++) {
                gSharedBuffer[i] = data[i];  // No bounds checking
            }
            break;
    }
}
```

### 2. **Empty Example Vulnerabilities**

**File**: `examples/empty/empty_example.c`

#### CWE-798: Hardcoded Credentials
```c
#define DEFAULT_PASSWORD "pru_admin_2024"
#define SECRET_KEY "0x1234ABCD"
```

**Why This Should Be Detected**:
- Hardcoded credentials in source code
- Easily discoverable by static analysis
- Major security risk in production systems
- Violates security best practices

## Detection Methods

### Static Analysis Security Testing (SAST)

These vulnerabilities should be detected by:

1. **SonarQube**
   ```bash
   sonar-scanner -Dsonar.projectKey=open-pru -Dsonar.sources=examples/
   ```

2. **Checkmarx**
   ```bash
   cx scan create --project-name "open-pru" --source-dir examples/
   ```

3. **Veracode Static Analysis**
   ```bash
   veracode-wrapper.jar -vid <app_id> -vkey <api_key> -action UploadAndScan -appname "open-pru" -createprofile false -filepath examples/
   ```

4. **Clang Static Analyzer with Security Checks**
   ```bash
   clang --analyze -Xanalyzer -analyzer-checker=security examples/security_test_example.c
   ```

5. **Cppcheck with Security Rules**
   ```bash
   cppcheck --enable=all --addon=cert examples/security_test_example.c
   ```

6. **Semgrep Security Rules**
   ```bash
   semgrep --config=auto examples/
   ```

### Dynamic Analysis Security Testing (DAST)

1. **AddressSanitizer for Memory Issues**
   ```bash
   gcc -fsanitize=address -g examples/security_test_example.c
   ```

2. **Valgrind for Memory Leaks and Use-After-Free**
   ```bash
   valgrind --tool=memcheck --leak-check=full ./security_test_example
   ```

3. **ThreadSanitizer for Race Conditions**
   ```bash
   gcc -fsanitize=thread -g examples/security_test_example.c
   ```

### Interactive Application Security Testing (IAST)

1. **Runtime Security Monitoring**
2. **Fuzzing with Security-Focused Inputs**
3. **Dynamic Taint Analysis**

## Expected Detection Results

### Static Analysis Expected Outputs

**For Hardcoded Credentials (CWE-798)**:
```
examples/empty/empty_example.c:45: High: Hardcoded password detected
examples/security_test_example.c:52: High: Hardcoded API key detected
examples/security_test_example.c:53: High: Hardcoded cryptographic key detected
```

**For Buffer Overflow (CWE-120)**:
```
examples/security_test_example.c:67: High: Potential buffer overflow in strcpy
examples/security_test_example.c:75: Medium: Unchecked buffer copy
```

**For Format String Vulnerability (CWE-134)**:
```
examples/security_test_example.c:82: High: Format string vulnerability detected
```

**For Use After Free (CWE-416)**:
```
examples/security_test_example.c:102: High: Use after free detected
```

**For Weak Cryptography (CWE-326, CWE-338)**:
```
examples/security_test_example.c:125: Medium: Weak random number generation
examples/security_test_example.c:126: Medium: Predictable seed used
```

### Security Scanner Integration

**Example GitHub Actions Security Workflow**:
```yaml
name: Security Scan
on: [push, pull_request]
jobs:
  security-scan:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - name: Run Semgrep
        uses: returntocorp/semgrep-action@v1
        with:
          config: auto
      - name: Run CodeQL
        uses: github/codeql-action/init@v2
        with:
          languages: c
      - name: Run CodeQL Analysis
        uses: github/codeql-action/analyze@v2
```

**Example SonarQube Integration**:
```yaml
sonar-project.properties:
sonar.projectKey=open-pru
sonar.sources=examples/
sonar.c.file.suffixes=.c,.h
sonar.security.hotspots.enable=true
sonar.security.review.enable=true
```

## Production Impact

These vulnerabilities represent **CRITICAL SECURITY RISKS** because:

1. **Data Breach**: Hardcoded credentials can lead to unauthorized access
2. **Code Execution**: Buffer overflows can be exploited for arbitrary code execution
3. **Information Disclosure**: Format string vulnerabilities can leak sensitive data
4. **Denial of Service**: Integer overflows can cause system crashes
5. **Memory Corruption**: Use-after-free can lead to unpredictable behavior
6. **Authentication Bypass**: Weak authentication can be easily circumvented
7. **Predictable Behavior**: Weak cryptography makes systems vulnerable to attacks
8. **System Compromise**: Path traversal can allow access to unauthorized files
9. **Race Conditions**: Can lead to privilege escalation or data corruption
10. **Input Validation**: Can lead to various injection attacks

## Remediation Examples

### Secure Credential Management
```c
// FIXED VERSION - Use secure credential storage
#include "secure_storage.h"  // Hardware security module or secure storage

int authenticate_user(const char* username, const char* password) {
    char stored_hash[64];
    if (secure_storage_get_password_hash(username, stored_hash) != 0) {
        return 0;  // User not found
    }
    
    char input_hash[64];
    if (compute_secure_hash(password, input_hash) != 0) {
        return 0;  // Hash computation failed
    }
    
    // Constant-time comparison to prevent timing attacks
    return secure_compare(stored_hash, input_hash, 64);
}
```

### Secure Buffer Operations
```c
// FIXED VERSION - Safe string operations
int process_user_command(const char* user_input) {
    char local_buffer[32];
    
    if (user_input == NULL) {
        return -1;  // Invalid input
    }
    
    size_t input_len = strlen(user_input);
    if (input_len >= sizeof(local_buffer)) {
        return -1;  // Input too long
    }
    
    strncpy(local_buffer, user_input, sizeof(local_buffer) - 1);
    local_buffer[sizeof(local_buffer) - 1] = '\0';  // Ensure null termination
    
    DebugP_log("Processing command: %s\n", local_buffer);
    return 0;
}
```

### Secure Random Number Generation
```c
// FIXED VERSION - Cryptographically secure random generation
#include "hardware_rng.h"  // Hardware random number generator

uint32_t generate_session_token() {
    uint32_t token;
    if (hardware_rng_get_bytes((uint8_t*)&token, sizeof(token)) != 0) {
        // Fallback to entropy pool if hardware RNG fails
        return entropy_pool_get_random();
    }
    return token;
}
```

## Testing Suite Integration

### Automated Security Testing Pipeline
```bash
#!/bin/bash
echo "Running security vulnerability scan..."

# Check for intentional vulnerabilities (should be removed before production)
if grep -r "INTENTIONAL SECURITY VULNERABILITY" examples/; then
    echo "ERROR: Intentional security vulnerabilities found - remove before production"
    exit 1
fi

# Run static analysis security tools
echo "Running static analysis security scan..."
semgrep --config=auto --error examples/
cppcheck --enable=all --addon=cert --error-exitcode=1 examples/

# Run dynamic analysis
echo "Running dynamic analysis..."
if [ -f "./security_test_example" ]; then
    valgrind --tool=memcheck --error-exitcode=1 ./security_test_example
fi

echo "Security vulnerability scan completed"
```

### CI/CD Security Gates
```yaml
# Example security gate configuration
security_gates:
  static_analysis:
    - tool: "semgrep"
      fail_on: "high,critical"
    - tool: "sonarqube"
      quality_gate: "security_gate"
  
  dynamic_analysis:
    - tool: "addresssanitizer"
      fail_on: "any_violation"
    - tool: "valgrind"
      fail_on: "memory_leak,use_after_free"
```

## Conclusion

The inserted security vulnerabilities serve as:
- **Test cases** for security analysis tools
- **Training examples** for developers
- **Validation** that security measures are working
- **Demonstration** of common embedded security issues

These should be **immediately detected and blocked** by any comprehensive security testing suite before code reaches production.

**Important**: These vulnerabilities are intentionally inserted for testing purposes and must be removed before any production deployment. They represent real security risks that could compromise system security if left in production code.