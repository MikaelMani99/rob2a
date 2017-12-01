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
	StopTask(project2part1);
	StopTask(project2part2);
	StopTask(project2part3);
	StopTask(project3part1);
	StopTask(project3part2);
	StopTask(project4);
	StopTask(project5);
	StopTask(project6);
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
			StartTask(project2part1);
		}
		else if(vexRT[Btn5U] == 1){
			stopTasks();
			StartTask(project2part2);
		}
		else if(vexRT[Btn6D] == 1){
			stopTasks();
			StartTask(project2part3);
		}
		else if(vexRT[Btn6U] == 1){
			stopTasks();
			StartTask(project3part1);
		}
		else if(vexRT[Btn8D] == 1){
			stopTasks();
			StartTask(project3part2);
		}
		else if(vexRT[Btn8L] == 1){
			stopTasks();
			StartTask(project4);
		}
		else if(vexRT[Btn8U] == 1){
			stopTasks();
			StartTask(project5);
		}
		else if(vexRT[Btn8R] == 1){
			stopTasks();
			StartTask(project6);
		}
	}
	StopAllTasks();
}
