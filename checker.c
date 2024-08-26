#include <stdio.h>
#include <assert.h>

int batteryTemp(float temperature) {
  if (temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
  }
}
int checkSOC(float soc) {
   if (soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
   } 
}

int chargeRateCheck(float chargeRate) {
  if (chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
  }
}

// Simplified main function to check all battery conditions
int batteryIsOk(float temperature, float soc, float chargeRate) {
  batteryTemp(temperature);
  checkSOC(soc);
  chargeRateCheck(chargeRate);
  return 0; 
}

int main() {
  assert(batteryIsOk(25, 70, 0.7)); 
  assert(batteryIsOk(50, 85, 0)); 
  return 0;
}
