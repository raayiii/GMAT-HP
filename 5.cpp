#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct SensorData {
    char id[10];      
    int error_code;   
    int hours;        
    int minutes;      
    int seconds;      
    double altitude;  
    double longitude; 
    double latitude;  
};

void serializeData(const SensorData& data, char* outputBuffer, size_t bufferSize) {
    snprintf(outputBuffer, bufferSize,
             "%s;%d;%d;%d;%d;%.4f;%.6f;%.6f;",
             data.id,
             data.error_code,
             data.hours,
             data.minutes,
             data.seconds,
             data.altitude,
             data.longitude,
             data.latitude);
}

void deserializeData(const char* concatenatedString, SensorData& targetData) {
    
    int result = sscanf(concatenatedString,
                        "%[^;];%d;%d;%d;%d;%lf;%lf;%lf;",
                        targetData.id,
                        &targetData.error_code,
                        &targetData.hours,
                        &targetData.minutes,
                        &targetData.seconds,
                        &targetData.altitude,
                        &targetData.longitude,
                        &targetData.latitude);
    }

int main() {
    const size_t BUFFER_SIZE = 128; 
    char concatenated_string[BUFFER_SIZE];
    SensorData originalData = {
        "385635",
        9,
        2,
        30,
        12,
        120.8276,
        -7.795580,
        110.369492
    };

    serializeData(originalData, concatenated_string, BUFFER_SIZE);
    cout << "concatenated_string: string = \"" << concatenated_string << "\"" << endl;
    cout << endl;

    SensorData parsedData = {}; 
    const char* input_string = "12345;4;5;23;45;130.6723;-4.124345;78.292737;";
    deserializeData(input_string, parsedData);
    printf("id: \"%s\"\n", parsedData.id);
    printf("error_code: %d\n", parsedData.error_code);
    printf("hours: %d\n", parsedData.hours);
    printf("minutes: %d\n", parsedData.minutes);
    printf("seconds: %d\n", parsedData.seconds);
    printf("altitude: %.4f\n", parsedData.altitude);
    printf("longitude: %.6f\n", parsedData.longitude);
    printf("latitude: %.6f\n", parsedData.latitude);
    
    return 0;
}