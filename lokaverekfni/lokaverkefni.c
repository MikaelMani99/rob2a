#pragma config(Sensor, dgtl3,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl1,  leftEncoder,         sensorQuadEncoder)
#pragma config(Sensor, in6,    potentiometer,   sensorPotentiometer)
#pragma config(Sensor, in8,    lightSensor,         sensorReflection)
#pragma config(Sensor, dgtl8,  sonarSensor,         sensorSONAR_cm)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port6,           armMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor, port5, 						clawMotor, 		tmotorServoContinuousRotation, openLoop)
#pragma config(Sensor, in3,    lineFollowerRIGHT,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in1,    lineFollowerLEFT,    sensorLineFollower)
#include "../headers/vex.h"
#include "../robotfunctions/functions.c"
#include "tasks.c"


/*
	This program compiles all of our previous programs and lets us run through each program one by one by pressing buttons on the controller
*/
void stopTasks(){
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	StopTask(verkefni2hlutur1);
	StopTask(verkefni2hlutur2);
	StopTask(verkefni2hlutur3);
	StopTask(verkefni3hlutur1);
	StopTask(verkefni3hlutur2);
	StopTask(verkefni4);
	StopTask(verkefni5);
	StopTask(verkefni6);
	StopTask(suicide1);
	StopTask(suicide2);
	StopTask(puzzle);
	StopTask(driveRobot);
	StopTask(driveEndlessly);
	StopTask(followLineTask);
	StopTask(pickUpBallTask);
}



task main()
{
	while(vexRT[Btn7L] != 1){
		if(vexRT[Btn5D] == 1){
			stopTasks();
			StartTask(verkefni2hlutur1);
		}
		else if(vexRT[Btn5U] == 1){
			stopTasks();
			StartTask(verkefni2hlutur2);
		}
		else if(vexRT[Btn6D] == 1){
			stopTasks();
			StartTask(verkefni2hlutur3);
		}
		else if(vexRT[Btn6U] == 1){
			stopTasks();
			StartTask(verkefni3hlutur1);
		}
		else if(vexRT[Btn8D] == 1){
			stopTasks();
			StartTask(verkefni3hlutur2);
		}
		else if(vexRT[Btn8L] == 1){
			stopTasks();
			StartTask(verkefni4);
		}
		else if(vexRT[Btn8U] == 1){
			stopTasks();
			StartTask(verkefni5);
		}
		else if(vexRT[Btn8R] == 1){
			stopTasks();
			StartTask(verkefni6);
		}
	}
	StopAllTasks();
}
