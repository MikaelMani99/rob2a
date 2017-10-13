/*
DESCRIPTION:
Drives the puzzle from project 1, but has a kill switch now
*/


#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#include "../../headers/vex.h"
#include "../../robotfunctions/functions.c"

task thraut(){
		for(int i; i < 4; i++){
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



task main()
{
	StartTask(thraut);
	while(vexRT[Btn7D] != 1){

	}
	StopAllTasks();
}
