#include <stdio.h>
#include <assert.h>
 
int checkValueRange(float value, float min, float max, const char* message) {
    if (value < min || value > max) {
        printf("%s\n", message);
        return 0;
    }
    return 1;
}
int checkChargeRate(float value, float max, const char* message)
{
    if (value > max) {
        printf("%s\n", message);
        return 0;
    }
    return 1;
}
 
 
int isTempOutOfRange(float temperature) {
	return checkValueRange(temperature, 0, 45, "Temperature is out of range");
}
 
int isSocOutOfRange(float soc) {
	return checkValueRange(soc, 20, 80, "State of Charge is out of range");
}
 
int isChargeRateOutOfRange(float chargeRate) {
	return checkValueRange(chargeRate,0.8, "Charge Rate is grater than the value !");
}
 
int batteryIsOk(float temperature, float soc, float chargeRate) {
	return (isTempOutOfRange(temperature) && isSocOutOfRange(soc) && isChargeRateOutOfRange(chargeRate));
 
}
 
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(batteryIsOk(1, 21, 0.4)); //lower boundary condition values of temperature and Soc
  assert(batteryIsOk(44, 79, 0.79)); //higher boundary condition values of temperature and Soc
  assert(!batteryIsOk(50, 65, 0.5)); //temperature out of range
  assert(!batteryIsOk(35, 85, 0.5)); //soc out of range
}
