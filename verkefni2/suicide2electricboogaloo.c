#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)

void drive(int dist){
		SensorValue[rightEncoder] = 0;
		while(SensorValue[rightEncoder] < dist)  // While less than 5 rotations on the leftEncoder...
  	{
    //...Move Forward
  	//circumference = 31.41592654
  	//wheel has to spin 1.591549431 times
  		motor[rightMotor] = 63;
    	motor[leftMotor] = 63;
  	}
  	SensorValue[rightEncoder] = 0;
  	while(SensorValue[rightEncoder] > -dist)
  	{
  		motor[rightMotor] = -63;
  		motor[leftMotor] = -63;
  	}

}
task main()
{
	int counter = 1;
	while(counter < 5){
		SensorValue[rightEncoder] = 0;
		int distance = 573 * counter;
		drive(distance);
		counter+= 1;
	}

}
