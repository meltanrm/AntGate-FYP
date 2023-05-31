//**********************************************************************************
// Code to operate stepper motor controlling connector bridge

// there is a front end of the bridge (F) that points to the sort bin
// back end (B) that comes from the nest 
// assuming that ants rush off the bridge towards B when the motor starts to move,
// the code should spin the bridge such that B points towards the appropriate sort bin 

// this is being tested with 2 sort bins, total range of motion = 70˚
// assume start position is neutral, in between both sort bins 
// final position should be sort bin on the left --> needs to rotate clockwise by 110˚
//**********************************************************************************

// Define constants 
const int dirPin = 2;  // Direction
const int stepPin = 5; // Step ~

// Motor steps per rotation (full rotation = 200) 
const int STEPS_PER_REV = 61; // 110 degrees 

void setup() {
// Setup the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}

void loop() {
  // rotates clockwise
  digitalWrite(dirPin,HIGH); 

  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); // note: at delay of 2000 or less, ants get flung off the bridge
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }

  delay(3000);
}
