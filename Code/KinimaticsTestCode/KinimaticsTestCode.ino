void setup() {

}

void loop() {
  // put your main code here, to run repeatedly:
  // Wheel radius in MilliMeters
  float R = 20;
  
  // The distance in mm from the centre of the base to a wheel in the x direction
  float Lx = 1200; //test value
  // The distance in mm from the centre of the base to a wheel in the y direction
  float Ly = 600; //test value
  
  // Velocities in mm/s, positive Vx is forwards, Positive Vy is left strafe
  float Vx = 10; //test
  float Vy = 10; //test
  
  // Angular rotation of robot in milli radians per sec, positive is CCW.
  float W = 10; //test

  
  float WheelLeftFront  = (Vx + Vy - (Lx + Ly)*W)/R;
  float WheelRightFront = (Vx - Vy + (Lx + Ly)*W)/R;
  float WheelLeftBack   = (Vx - Vy - (Lx + Ly)*W)/R;
  float WheelRightBack  = (Vx + Vy + (Lx + Ly)*W)/R;
}
