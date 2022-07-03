#include <iostream>
#include "pca9685.h"
#include "motor.h"

using namespace std;

Motor m2;
void go_left() {
	m2.SetMotorMode1(-500, -500, 2000, 2000);
}