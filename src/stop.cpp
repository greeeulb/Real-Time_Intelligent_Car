#include <iostream>
#include "pca9685.h"
#include "motor.h"
#include "pca9685.cpp"
#include "motor.cpp"


using namespace std;

Motor m2;
void stop() {
	m2.SetMotorMode1(0,0,0,0);
}