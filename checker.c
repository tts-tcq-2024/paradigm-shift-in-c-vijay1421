#include <stdio.h>
#include <assert.h>

int batteryTemp(float temperature) {
  if (temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 1; // Error
  } else {
    printf("Temperature is OK\n");
    return 0; // OK
  }
}
int checkSOC(float soc) {
   if (soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 1; // Error
   } else {
    printf("State of Charge is OK\n");
    return 0; // OK
   }
}

int chargeRateCheck(float chargeRate) {
  if (chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 1; // Error
  } else {
    printf("Charge Rate is OK\n");
    return 0; // OK
  }
}

// Simplified main function to check all battery conditions
int batteryIsOk(float temperature, float soc, float chargeRate) {
  int tempError = batteryTemp(temperature);
  int socError = checkSOC(soc);
  int chargeRateError = chargeRateCheck(chargeRate);

  // Combine all errors into a single decision point
  if (tempError || socError || chargeRateError) {
    return 1; // Error occurred
  }
  return 0; // All checks passed
}

int main() {
  // Test cases
  assert(batteryIsOk(25, 70, 0.7)); 
  assert(batteryIsOk(50, 85, 0)); 
  return 0;
}
