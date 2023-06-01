//**********************************************************************************
// This code tests the operation of a single stepper motor
// For connecting with Arduino UNOs, the stepPin must be connected to Arduino ~ PWM pins
//**********************************************************************************

// Connections to A4988
const int dirPin = 2;  // Direction
const int stepPin = 5; // Step ~

// Motor steps per rotation (full rotation = 200) 
const int STEPS_PER_REV = 25; // 45 degrees 
 
void setup() {
  // Setup the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  // Set motor direction clockwise
  digitalWrite(dirPin,HIGH); 
  
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(4000); // note: at delay of 2000, ants get flung off the bridge
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(4000); 
  }
  
  delay(8000);

  // Set motor direction anticlockwise
  digitalWrite(dirPin,LOW); 
  
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(4000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(4000); 
  }
   
  delay(8000);
  
}
