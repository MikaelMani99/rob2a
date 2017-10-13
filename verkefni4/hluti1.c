/*
DESCRIPTION:
this program is suppose to drive around by it self until the kill switch is pushed.
how it drives around is that it checks if the light is on, then checks if there is something in front of it
then it drives forward 10 cm.
*/
#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Sensor, dgtl8,  sonarSensor,         sensorSONAR_cm)
#pragma config(Sensor, in8,    lightSensor,         sensorReflection)
#include "../headers/vex.h"
#include "../robotfunctions/functions.c"

task keyraMedanLeifir()
{
	while(true)
	{
		if((SensorValue(lightSensor)) < 400)
		{
			if(SensorValue(sonarSensor) > 40 || SensorValue(sonarSensor) == -1){
				drive(0.1, 1);
			}
			else{

				stop(1);
				turn(90);
			}
		}
		else
		{
			stopMotors(1);
		}
	}
}

task main()
{
	StartTask(keyraMedanLeifir);
	while(vexRT[Btn7D] != 1){
	}
	StopAllTasks();
}
