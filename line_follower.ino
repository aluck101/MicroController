    
#define L1 5
#define L2 6
#define R1 10
#define R2 11

#define leftSensor 4
#define rightSensor 7

int leftSensorVal = 0;
int rightSensorVal = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(L1, OUTPUT);
pinMode(L2, OUTPUT);
pinMode(R1, OUTPUT);
pinMode(R2, OUTPUT);
pinMode(leftSensor, INPUT);
pinMode(rightSensor, INPUT);
stopMotor();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  leftSensorVal=digitalRead(leftSensor);
  rightSensorVal=digitalRead(rightSensor);

  if(leftSensorVal==LOW && rightSensorVal==LOW)
  {
   forwardMovement();
  }
  if(leftSensorVal==LOW && rightSensorVal==HIGH)
  {
   moveRight();
  }
  if(leftSensorVal==HIGH && rightSensorVal==LOW)
  {
   moveLeft();
  }
  if(leftSensorVal==HIGH && rightSensorVal==HIGH)
  {
   stopMotor();
  }
  
}

void backwardMovement() {
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW); 
}

void forwardMovement() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH); 
}

void moveRight() {
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH); 
}

void moveLeft() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW); 
}

void stopMotor() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW); 
}
