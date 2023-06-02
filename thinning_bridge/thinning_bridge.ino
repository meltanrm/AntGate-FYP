
//**********************************************************************************
// Code to operate stepper motor controlling bridge that deposits one ant at 
// a time on the imaging platform.
// The bridge should wait at the nest platform for 6 seconds, rotate to the 
// imaging platform and deposit the ant before rotating back to the nest platform
//**********************************************************************************

// Define constants 
const int dirPin = 2;  // Direction
const int stepPin = 5; // Step ~

// Motor steps per rotation (full rotation = 200) 
const int STEPS_PER_REV = 50; // 90 degrees


void setup() {
// Setup the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}

void loop() {
  // LOW rotates anticlockwise
  // HIGH rotates clockwise
  digitalWrite(dirPin,LOW); 

  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); // note: at delay of 2000 or less, ants get flung off the bridge
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }

  // waits for 6 seconds
  delay(6000);

  // rotates 90˚ anticlockwise
  digitalWrite(dirPin,HIGH); 
  
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }
  
  // waits for 6 seconds
  delay(3000);
}
