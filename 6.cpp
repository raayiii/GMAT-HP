#include <iostream>
#include <cstdint>
#include <string>
using namespace std;

enum class ErrorCode : uint8_t {
    ELECTRICAL = 0x01,
    I2C        = 0x02,
    UART       = 0x04,
    TELEMETRY  = 0x08,
    ACTUATOR   = 0x10
};

string getErrors(uint8_t error_code) {
    const ErrorCode errorList[] = {
        ErrorCode::ELECTRICAL,
        ErrorCode::I2C,
        ErrorCode::UART,
        ErrorCode::TELEMETRY,
        ErrorCode::ACTUATOR
    };
    const string errorNames[] = {
        "Electrical",
        "I2C",
        "UART",
        "Telemetry",
        "Actuator"
    };

    string result;

    for (int i = 0; i < 5; i++) {
        if (error_code & static_cast<uint8_t>(errorList[i])) {
            result += errorNames[i] + ";";
        }
    }
    if (result.empty())
        return ";";

    return result;
}

int main() {
    uint8_t test_values[] = {23, 0, 12, 5, 28, 32, 41};
    for (uint8_t val : test_values) {
        cout << getErrors(val) << endl;
    }

    return 0;
}