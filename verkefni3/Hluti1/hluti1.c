/*
DESCRIPTION:
Connects to the remote to the robot and lets the control control the robot
*/

#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           clawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorServoContinuousRotation, openLoop)


task main()
{
	int x = 0;
	int y = 0;
	int threshold = 10;

	while(true){
				x = vexRT[Ch1];
				y = vexRT[Ch2];

				if((abs(x) > threshold) && (abs(y) > threshold) && (y > 0)){
					motor[leftMotor] = (y + x)/2;
					motor[rightMotor] = (y - x)/2;
				}

				else if((abs(x) > threshold) && (abs(y) > threshold) && (y<0)){
					motor[leftMotor] = (y - x)/2;
					motor[rightMotor] = (y + x)/2;
				}

				else if((abs(x) > threshold) && (abs(y) < threshold)){
					motor[leftMotor]  = x;
      		motor[rightMotor] = (-1 * x);
				}

				else{
					motor[leftMotor] = 0;
					motor[rightMotor] = 0;
				}


				if(vexRT[Btn8D] == 1){
					motor[armMotor] = 60;
				}
				else if(vexRT[Btn8U] == 1) {
					motor[armMotor] = -60;
				}
				else{
					motor[armMotor] = 0;
				}

				if(vexRT[Btn8L] == 1){
					motor[clawMotor] = 60;
				}
				else if(vexRT[Btn8R] == 1) {
					motor[clawMotor] = -60;
				}
				else{
					motor[clawMotor] = 0;
				}
		}
}
