
//**********************************************************************************
// Code to operate two motors
// Motor A functions as connector bridge to limit number of ants on the set up
// Motor B functions as selector bridge to direct ants towards sort bin 
//**********************************************************************************

// Define constants
const int dirPin_A = 8;  // Direction
const int stepPin_A = 9; // Step ~
const int dirPin_B = 2;  // Direction
const int stepPin_B = 5; // Step ~

// Motor steps per rotation (full rotation = 200) 
const int steps_A = 40; // 10 degrees
const int steps_B = 30; // 

void setup() {
  pinMode(stepPin_A,OUTPUT); 
  pinMode(dirPin_A,OUTPUT);
  pinMode(stepPin_B,OUTPUT); 
  pinMode(dirPin_B,OUTPUT);
}

void loop() {
  // LOW rotates anticlockwise
  // HIGH rotates clockwise
  digitalWrite(dirPin_A,HIGH);
  digitalWrite(dirPin_B,HIGH); 

  for(int x = 0; x < steps_A; x++) {
    digitalWrite(stepPin_A,HIGH); 
    delayMicroseconds(1000); // note: at delay of 2000, my boi got flung off the stick onto the ground 
    digitalWrite(stepPin_A,LOW); 
    delayMicroseconds(1000); 
  }

  for(int x = 0; x < steps_B; x++) {
    digitalWrite(stepPin_B,HIGH); 
    delayMicroseconds(1000); // note: at delay of 2000, my boi got flung off the stick onto the ground 
    digitalWrite(stepPin_B,LOW); 
    delayMicroseconds(1000); 
  }

  // waits for 2 seconds
  delay(6000);

  // changes direction
  digitalWrite(dirPin_A,LOW);
  digitalWrite(dirPin_B,LOW); 
  
  for(int x = 0; x < steps_A; x++) {
    digitalWrite(stepPin_A,HIGH);
    delayMicroseconds(1000); 
    digitalWrite(stepPin_A,LOW);
    delayMicroseconds(1000); 
  }

  for(int x = 0; x < steps_B; x++) {
    digitalWrite(stepPin_B,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin_B,LOW); 
    delayMicroseconds(1000); 
  }

  // waits for 1 seconds
  delay(6000);
}
