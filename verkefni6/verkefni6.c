#pragma config(Sensor, dgtl3,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl1,  leftEncoder,         sensorQuadEncoder)
#pragma config(Sensor, in6,    potentiometer,   sensorPotentiometer)
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
/*
	what this program should do is make the robot follow a distict path, pick up a ball with its claw and then take
	the ball back to its starting point
*/
/*
	Sonar Sensor = 20 at the end of the claw, so when sensor is less than 20 claw should try to pick up
*/
bool pickup = true;
task followLine() {

	while(true)
	{
		int threshold = 200;
		if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      motor[leftMotor]  = THIRDPOWER;
      motor[rightMotor] = 0;
    }

    else if(SensorValue(lineFollowerCENTER) > threshold)
    {
      motor[leftMotor]  = THIRDPOWER;
      motor[rightMotor] = THIRDPOWER;
    }

    else if(SensorValue(lineFollowerLEFT) > threshold)
    {
      motor[leftMotor]  = 0;
      motor[rightMotor] = THIRDPOWER;
    }
	}

}

task pickUpBall() {
	while(true){
		if(SensorValue(sonarSensor) < 25 && pickup)
		{
			StopTask(followLine);
			stopMotors(1);
			openClaw();
			stopMotors(1);
			clawDown();
			stopMotors(1);
			drive(0.2, 1);
			stopMotors(1);
			closeClaw();
			stopMotors(1);
			clawUp();
			stopMotors(1);
			turn(150);
			stopMotors(1);
			drive(0.1, 1);
			stopMotors(1);
			pickup = false;
			StartTask(followLine);
		}
		else if(SensorValue(sonarSensor) < 15 && pickup == false)
	  {
	  	openClaw();
	  	StopAllTasks();
	  }

	}



}

task main()
{

	StartTask(followLine);
	StartTask(pickUpBall);


	while(vexRT[Btn7D] != 1){

	}
	StopAllTasks();
}
