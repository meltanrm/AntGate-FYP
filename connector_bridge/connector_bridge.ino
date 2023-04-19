
//**********************************************************************************
// Code to operate stepper motor controlling connector bridge
// connector bridge should rotate 90˚ and back every couple of seconds to 
// limit the number of ants allowed on the bridge set up 
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
    delayMicroseconds(1000); // note: at delay of 2000, my boi got flung off the stick onto the ground 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }

  // waits for 2 seconds
  delay(3000);

  // rotates 90˚ anticlockwise
  digitalWrite(dirPin,HIGH); 
  
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }
  
  // waits for 1 seconds
  delay(3000);
}
