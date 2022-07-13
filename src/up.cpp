#include <iostream>
#include "pca9685.h"
#include "motor.h"
#include "pca9685.cpp"
#include "motor.cpp"


using namespace std;

Motor m2;
void go_up() {
	m2.SetMotorMode1(2000, 2000, 2000, 2000);
}