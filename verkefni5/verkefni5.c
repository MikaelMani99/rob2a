#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Sensor, in3,    lineFollowerRIGHT,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in1,    lineFollowerLEFT,    sensorLineFollower)
/*
DESCRIPTION:
This program drives around after a dark line on the ground, three sensor under the robot detect if the surface
is darker and drives around the line
*/
#include "../headers/vex.h"
#include "../robotfunctions/functions.c"

task keyraEftirLinu() {
	while(true)
	{
		int threshold = 2500;
		if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      motor[leftMotor]  = 70;
      motor[rightMotor] = 15;
    }

    else if(SensorValue(lineFollowerCENTER) > threshold)
    {
      motor[leftMotor]  = 63;
      motor[rightMotor] = 63;
    }

    else if(SensorValue(lineFollowerLEFT) > threshold)
    {
      motor[leftMotor]  = 15;
      motor[rightMotor] = 70;
    }
	}
}

task main()
{
	StartTask(keyraEftirLinu);
	while(vexRT[Btn7D] != 1){
	}
	StopAllTasks();
}
