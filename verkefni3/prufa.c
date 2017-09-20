#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
task main ()
{
  int joy_x;            // will hold the X value of the analog stick (choices below)
  int joy_y;            // will hold the Y value of the analog stick (choices below)
  int threshold = 10;   // helps to eliminate 'noise' from a joystick that isn't perfectly at (0,0)

  while(1 == 1)
  {
    joy_x = vexRT[Ch1];   // This is the RIGHT analog stick.  For LEFT, change 'Ch1' to 'Ch4'.
    joy_y = vexRT[Ch2];   // This is the RIGHT analog stick.  For LEFT, change 'Ch2' to 'Ch3'.

    // Forward, and swing turns: (both abs(X) and abs(Y) are above the threshold, and Y is POSITIVE)
    if((abs(joy_x) > threshold) && (abs(joy_y) > threshold) && (joy_y > 0))
    {
      motor[leftMotor]  = (joy_y + joy_x)/2;
      motor[rightMotor] = (joy_y - joy_x)/2;
    }
    // Backwards and swing turns: (both abs(X) and abs(Y) are above the threshold, and Y is NEGATIVE)
    else if((abs(joy_x) > threshold) && (abs(joy_y) > threshold) && (joy_y < 0))
    {
      motor[leftMotor]  = (joy_y - joy_x)/2;
      motor[rightMotor] = (joy_y + joy_x)/2;
    }
    // Turning in place: (abs(X) is above the threshold, abs(Y) is below the threshold)
    else if((abs(joy_x) > threshold) && (abs(joy_y) < threshold))
    {
      motor[leftMotor]  = joy_x;
      motor[rightMotor] = (-1 * joy_x);
    }
    // Standing still: (both abs(X) and abs(Y) are below the threshold)
    else
    {
      motor[leftMotor]  = 0;
      motor[rightMotor] = 0;
    }
  }
}
