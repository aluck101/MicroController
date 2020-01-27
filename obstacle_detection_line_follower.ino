  
#define L1 5
#define L2 6
#define R1 10
#define R2 11
#define leftTrigPin 12
#define leftEchoPin 13
#define rightTrigPin 9 
#define rightEchoPin 8
#define midTrigPin 2
#define midEchoPin 3

#define leftSensor 4
#define rightSensor 7

int leftSensorVal = 0;
int rightSensorVal = 0;
int midDistance, rightDistance, leftDistance;
long midDuration, rightDuration, leftDuration;
long maxMidDistance = 30.00;
long maxLeftDistance = 25.00;
long maxRightDistance = 25.00;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(leftEchoPin, INPUT);
  pinMode(leftTrigPin, OUTPUT);
  pinMode(midEchoPin, INPUT);
  pinMode(midTrigPin, OUTPUT);
  pinMode(rightEchoPin, INPUT);
  pinMode(rightTrigPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  
  leftSensorVal=digitalRead(leftSensor);
  rightSensorVal=digitalRead(rightSensor);

  if(leftSensorVal==HIGH && rightSensorVal==HIGH)
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
  if(leftSensorVal==LOW && rightSensorVal==LOW)
  {
   // stopMotor();
  } 

  midDistanceCheck();
  if(midDistance < maxMidDistance) {
    Serial.println("Front Object too close");
    delay(100);
    leftDistanceCheck();
    delay(100);
    rightDistanceCheck();
    delay(100);
    if(leftDistance < rightDistance) {
      stopMotor();
      moveRight();
      Serial.println("Moving Right");
  } else if(leftDistance > rightDistance) {
      stopMotor();
      moveLeft();
      Serial.println("Moving Left");
    }
  } else {
    Serial.println("Ok");
    forwardMovement();
  }

  leftDistanceCheck();
  if(leftDistance < maxLeftDistance) {
  Serial.println("Left Object too close");
  delay(100);
  leftDistanceCheck();
  delay(100);
  rightDistanceCheck();
  delay(100);
    if(leftDistance > rightDistance) {
      stopMotor();
      forwardMovement();
  } else if(leftDistance < rightDistance) {
      stopMotor();
      moveRight();
      Serial.println("Moving Right");
    }
  }
   rightDistanceCheck();
  if(rightDistance < maxRightDistance) {
    Serial.println("Right Object too close");
    delay(100);
    rightDistanceCheck();
    delay(100);
    leftDistanceCheck();
    delay(100);
    if(rightDistance > leftDistance) {
      forwardMovement();
  } else if(rightDistance < leftDistance) {
      moveLeft();
      Serial.println("Moving Left");
    }
  }
 
}

void leftDistanceCheck() {
  digitalWrite(leftTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(leftTrigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(leftTrigPin, LOW);
  leftDuration = pulseIn(leftEchoPin, HIGH);
  leftDistance = leftDuration * 10 / 292 /2;
   if(leftDistance > 1000) {
    leftDistance = 0;
  }

  Serial.print("Left distance: ");
  Serial.print(leftDistance);
  Serial.println(" cm");    
}

void rightDistanceCheck() {
  digitalWrite(rightTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(rightTrigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(rightTrigPin, LOW);
  rightDuration = pulseIn(rightEchoPin, HIGH);
  rightDistance = rightDuration * 10 / 292 /2;
  if(rightDistance > 1000) {
    rightDistance = 0;
  }
  Serial.print("Right distance: ");
  Serial.print(rightDistance);
  Serial.println(" cm");
}  

void midDistanceCheck() {
  digitalWrite(midTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(midTrigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(midTrigPin, LOW);
  midDuration = pulseIn(midEchoPin, HIGH);
  midDistance = midDuration * 10 / 292 /2;
   if(midDistance > 1000) {
    midDistance = 0;
  }
  Serial.print("Front distance: ");
  Serial.print(midDistance);
  Serial.println(" cm");
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
