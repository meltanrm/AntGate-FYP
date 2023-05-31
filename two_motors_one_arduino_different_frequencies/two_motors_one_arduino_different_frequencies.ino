
//**********************************************************************************
// This is code attempting to use one arduino to
// turn two motors at different frequencies and intervals 
// This code is modified from 
// https://www.tommycoolman.com/2021/07/31/control-two-independent-stepper-motors-with-an-arduino/
//**********************************************************************************

#define PUL1_PIN    9
#define DIR1_PIN    8
#define PUL2_PIN    5
#define DIR2_PIN    2
  
class stepperMotor{
  public:
     
  void stop(void){
    enable = 0;
  }
  
  void start(void){
    enable = 1;
  }
  
  void init(int _pulsePin, int _dirPin, unsigned long _delayTime, bool _direction){
    pulsePin      = _pulsePin;
    dirPin        = _dirPin;
    delayTime     = _delayTime;
    direction     = _direction;
      
    togglePulse   = LOW;
    enable        = 0;
      
    pinMode(pulsePin, OUTPUT);
    pinMode(dirPin, OUTPUT);
  }
  
  void control(void){
    currentTime = micros();
    digitalWrite(dirPin, direction);
    if(enable == 1){
      if( (currentTime - deltaTime) > delayTime ){
        pulseCount++;
 
        // Each HIGH or LOW is a "pulse"
        // But each step of the motor requires two "pulses"
        if(pulseCount % 2 == 0){
          stepCount++;
        }
  
        togglePulse = togglePulse == LOW ? HIGH : LOW;
        digitalWrite(pulsePin, togglePulse);
        deltaTime = currentTime;
      }
    }
  }
  
  void changeDirection(bool _direction){
    direction = _direction;
  }
  
  unsigned long steps(void){
    return stepCount;
  }
  
  void changeSpeed(unsigned long _speed){
    delayTime = _speed;
  }
    
  private:
  unsigned long delayTime, deltaTime, currentTime;
  unsigned long pulseCount = 0;
  unsigned long stepCount = 0;
  int pulsePin, dirPin;
  bool direction, togglePulse, enable;
};
  
stepperMotor stepperOne, stepperTwo;
  
void setup() {
  stepperOne.init(PUL1_PIN,DIR1_PIN,1000,HIGH);
  stepperTwo.init(PUL2_PIN,DIR2_PIN,1000,HIGH);
  stepperOne.start();
  stepperTwo.start();
}
  
void loop() {
  stepperOne.control();
  stepperTwo.control();
  
  if(stepperOne.steps() == 2000){
    stepperOne.changeDirection(LOW);
    stepperOne.changeSpeed(600);
  }
}
