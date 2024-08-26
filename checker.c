#include <stdio.h>
#include <assert.h>

// Function to check the temperature of the battery
int batteryTemp(float temperature) {
  if (temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 1; // Error
  } else {
    printf("Temperature is OK\n");
    return 0; // OK
  }
}

// Function to check the state of charge
int checkSOC(float soc) {
   if (soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 1; // Error
   } else {
    printf("State of Charge is OK\n");
    return 0; // OK
   }
}

// Function to check the charge rate
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
  if (batteryTemp(temperature)) return 1; // Error
  if (checkSOC(soc)) return 1;            // Error
  if (chargeRateCheck(chargeRate)) return 1; // Error
  return 0; // All checks passed
}

int main() {
  // Test cases
  assert(batteryIsOk(25, 70, 0.7) == 0);  // All conditions are OK
  assert(batteryIsOk(50, 85, 0) == 1);   // Temperature and SOC out of range
  assert(batteryIsOk(-5, 70, 0.7) == 1);  // Temperature out of range
  assert(batteryIsOk(25, 85, 0.7) == 1);  // SOC out of range
  assert(batteryIsOk(25, 70, 0.9) == 1);  // Charge rate out of range

  return 0;
}
