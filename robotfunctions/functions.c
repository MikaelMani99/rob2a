int power = HALFPOWER;
void stop(int time){
		motor[rightMotor] = 0;
		motor[leftMotor] = 0;
		wait1Msec(1000 * time);
}
void drive(float dist, int direction){
	float fixd = dist * 100;
	float turns = (fixd/WHEELBASELARGE) * 360 * direction;
	SensorValue[rightEncoder] = 0;
	if(direction > 0){
		while(SensorValue[rightEncoder] < turns)
		{
		motor[rightMotor] = power;
		motor[leftMotor] = power;
  	}
 	}
	else{
		while(SensorValue[rightEncoder] > turns)
		{
		motor[rightMotor] = -power;
		motor[leftMotor] = -power;
  	}
	}
}
void turn(int deg){
	float d = 360 / deg;
	float l = ROTATE360DEG / d;
	SensorValue[rightEncoder] = 0;
	if(l > 0 ){
		while(SensorValue[rightEncoder] < l)
  	{
 			motor[rightMotor] = -power;
    	motor[leftMotor] = power;
 		}
	}
	else{
	 	while(SensorValue[rightEncoder] > 1)
  	{
 			motor[rightMotor] = power;
    	motor[leftMotor] = -power;
 		}
	}

}
