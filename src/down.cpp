#include <iostream>
#include "pca9685.h"
#include "motor.h"

using namespace std;

Motor m2;
void go_down() {
	m2.SetMotorMode1(-2000, -2000, -2000, -2000);
}