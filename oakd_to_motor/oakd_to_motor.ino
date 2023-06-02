//**********************************************************************************
// Test code to take input from the cameras, and output to the motors 
// Not doing weight classification at the moment, just recognising the insect's presence
// motor turns when ant is in frame

// Modified from code by Annie Szeto and Lok Lau
//**********************************************************************************
const int dirPin = 8;  // Direction
const int stepPin = 9; // Step ~

String inString = "";
int inChar;

// Motor steps per rotation (full rotation = 200) 
const int STEPS_PER_REV = 30; // 54 degrees
// 
void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  
  Serial.begin(115200);

}

void loop() {
  while (Serial.available()) {
    if (Serial.available() > 0) {
      int inChar = Serial.read();
  
      if (isDigit(inChar)) {
        inString = (char)inChar;
      }
    }
  }
  
  if (inString == "1")
  {
    digitalWrite(dirPin,LOW); 

    for(int x = 0; x < STEPS_PER_REV; x++) {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(1000); // note: at delay of 2000, my boi got flung off the stick onto the ground 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(1000); 
    }
    // waits for 2 seconds
    delay(3000);
  } 
}
