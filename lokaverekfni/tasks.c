//Breyta
bool pickup = true;

task suicide1(){ //Verkefni 2 Hluti 1
			double counter = 1;
			while(counter < 6 ){
			motor[rightMotor] = FULLPOWER;
			motor[leftMotor]	= FULLPOWER;
			wait1Msec(1000 * counter);

			motor[leftMotor]	= 0;
			motor[rightMotor] = 0;
			wait1Msec(1000);

			motor[rightMotor] = -FULLPOWER;
			motor[leftMotor]	= -FULLPOWER;
			wait1Msec(1000 * counter);

			motor[leftMotor]	= 0;
			motor[rightMotor] = 0;
			wait1Msec(1000);

			counter += 1;
	}
}
task suicide2() { //Verkefni 2 Hluti 2
	int counter = 1;
	while(counter < 5){
		SensorValue[rightEncoder] = 0;
		int distance = 573 * counter;
		if(counter % 2 == 0){
			drive(distance, -1);
		}
		else {
			drive(distance, 1);
		}
		counter+= 1;
	}
}


task puzzle() { //Verkefni 2 Hluti 3 og Verkefni 3 hlutur 2
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

task driveRobot() { //Verkefni 3 Hlutur 1
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


				if(vexRT[Btn7U] == 1){
					motor[armMotor] = HALFPOWER;
				}
				else if(vexRT[Btn7R] == 1) {
					motor[armMotor] = -HALFPOWER;
				}
				else{
					motor[armMotor] = 0;
				}

		}
	}

task driveEndlessly() { //Verkefni 4
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

task followLineTask() { //Verkefni 5 og Verkefni 6
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


task pickUpBallTask(){ //Verkefni 6
	while(true){
		if(SensorValue(sonarSensor) < 25 && pickup)
		{
			StopTask(followLineTask);
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
			StartTask(followLineTask);
		}
		else if(SensorValue(sonarSensor) < 15 && pickup == false)
	  {
	  	openClaw();

	  }

	}
}




task verkefni2hlutur1() {
		StartTask(suicide1);
		while(vexRT[Btn7D] != 1){

		}
}

task verkefni2hlutur2() {
	StartTask(suicide2);
	while(vexRT[Btn7D] != 1){

	}

}

task verkefni2hlutur3() {
	StartTask(puzzle);
	while(vexRT[Btn7D] != 1){

	}

}

task verkefni3hlutur1() {
	StartTask(driveRobot);
	while(vexRT[Btn7D] != 1){

	}

}

task verkefni3hlutur2() {
	StartTask(puzzle);
	while(vexRT[Btn7D] != 1){

	}

}

task verkefni4() {
	StartTask(driveEndlessly);
	while(vexRT[Btn7D] != 1){

	}

}


task verkefni5(){
	StartTask(followLineTask);
	while(vexRT[Btn7D] != 1){
	}

}

task verkefni6() {
	StartTask(followLineTask);
	StartTask(pickUpBallTask);
	while(vexRT[Btn7D] != 1){

	}

}
