#include <stdio.h>
#include <assert.h>

//A function to check the temperature of battery
int batteryTemp(float Temp){
  if(Temp < 0 || Temp > 45) {
    printf("Temperature out of range!\n");
    return 1;
  }
  else{
    printf("Temperature is OK\n");
    return 0;
  }
}

int checkSOC(float soc) {
   if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 1;
   }
    else{
      printf("State of Charge is OK\n");
      return 0;
    }
}

int chargeRateCheck(float chargeRate){
  if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 1;
  }
  else{
    printf("Charge Rate is OK\n");
    return 0;
  }
}


int batteryIsOk(float temperature, float soc, float chargeRate) {
  if(batteryTemp(temperature)) return 1;
  if(checkSOC(soc)) return 1;
  if(chargeRateCheck(chargeRate)) return 1;
  return 0;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
