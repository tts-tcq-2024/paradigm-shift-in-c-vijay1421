#include <stdio.h>
#include <assert.h>

int batteryTemp(float temperature) {
  if (temperature < 0 || temperature > 45) return 1;
  return 0; // Temperature Ok
}

int checkSOC(float soc) {
   if (soc < 20 || soc > 80) return 2;
    return 0; // soc OK
   }
}

int chargeRateCheck(float chargeRate) {
  if (chargeRate > 0.8) return 3;
  return 0; // Charge rate OK
}

// Simplified main function to check all battery conditions
int batteryIsOk(float temperature, float soc, float chargeRate) {
    int status;

    status = batteryTemp(temperature);
    if (status != 0) return status;

    status = checkSOC(soc);
    if (status != 0) return status;

    status = chargeRateCheck(chargeRate);
    return status;
}

void printErrorMessage(int code) {
    switch (code) {
        case 1: printf("Temperature out of range!\n"); break;
        case 2: printf("State of Charge out of range!\n"); break;
        case 3: printf("Charge Rate out of range!\n"); break;
        default: break; // No message for code 0 (BATTERY_OK)
    }
}

int main() {
  int status;
  status = assert(batteryIsOk(25, 70, 0.7));
  printErrorMessage(status);
  status = assert(batteryIsOk(50, 85, 0)); 
  printErrorMessage(status);
  return 0;
}
