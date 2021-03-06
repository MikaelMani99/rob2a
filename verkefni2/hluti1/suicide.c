#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
task main()
{
	double counter = 1;
	while(counter < 6 ){
		motor[rightMotor] = 127;
		motor[leftMotor]	= 127;
		wait1Msec(1000 * counter);

		motor[leftMotor]	= 0;
		motor[rightMotor] = 0;
		wait1Msec(1000);

		motor[rightMotor] = -127;
		motor[leftMotor]	= -127;
		wait1Msec(1000 * counter);

		motor[leftMotor]	= 0;
		motor[rightMotor] = 0;
		wait1Msec(1000);

		counter += 1;
	}


}
