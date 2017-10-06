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
		if(SensorValue(lightSensor) < 200)
		{
			if(SensorValue(sonarSensor) > 20 || SensorValue(sonarSensor) == -1){
				drive(0.5, 1);
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
