#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#include "../../headers/vex.h"

void stop(int time){
		motor[rightMotor] = 0;
		motor[leftMotor] = 0;
		wait1Msec(1000 * time);
}
void drive(float dist, int direction){
	float fixd = dist * 100;
	float turns = (fixd/WHEELBASELARGE) * 360 * direction;
	SensorValue[rightEncoder] = 0;
	if(direction > 0){
		while(SensorValue[rightEncoder] < turns && vexRT[Btn7D] != 1)
		{
		motor[rightMotor] = 63;
		motor[leftMotor] = 63;
  	}
 	}
	else{
		while(SensorValue[rightEncoder] > turns && vexRT[Btn7D] != 1)
		{
		motor[rightMotor] = -63;
		motor[leftMotor] = -63;
  	}
	}
}
void turn(int deg){
	float d = 360 / deg;
	float l = ROTATE360DEG / d;
	SensorValue[rightEncoder] = 0;
	if(l > 0 ){
		while(SensorValue[rightEncoder] < l && vexRT[Btn7D] != 1)
  	{
 			motor[rightMotor] = -63;
    	motor[leftMotor] = 63;
 		}
	}
	else{
	 	while(SensorValue[rightEncoder] > l && vexRT[Btn7D] != 1)
  	{
 			motor[rightMotor] = 63;
    	motor[leftMotor] = -63;
 		}
	}

}

task main()
{
	for(int i = 0; i < 4; i++){
		drive(0.5, 1);
		stop(1);
		if(i == 0){
			turn(-90);
		}
		else if(i < 3){
			turn(90);
		}
		stop(1);
	}
}
