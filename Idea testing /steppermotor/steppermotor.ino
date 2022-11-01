
// Define Constants

// Connections to A4988
const int dirPin = 2;  // Direction
const int stepPin = 5; // Step ~

// Motor steps per rotation
const int STEPS_PER_REV = 25;
 
void setup() {
  
  // Setup the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  
  // Set motor direction clockwise
  digitalWrite(dirPin,HIGH); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(4000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(4000); 
  }
  
  // Pause for one second
  delay(8000);

  // Set motor direction anticlockwise
  digitalWrite(dirPin,LOW); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(4000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(4000); 

    // at delay microseconds 20000 just watched my boi get flung off onto the ground
  }
  
  // Pause for one second
  delay(8000);
}
