#ifndef _MOTORTEST_H_
#define _MOTORTEST_H_

bool MotorInit();
int DutyRange(int duty1,int duty2,int duty3,int duty4);
void left_upper_wheel(int duty);
void left_lower_wheel(int duty);
void right_upper_wheel(int duty);
void right_lower_wheel(int duty);
void SetMotorMode1(int duty1,int duty2,int duty3,int duty4);

#endif
