void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(12);
  Serial.println(sensorValue);
  analogWrite(3,map(sensorValue,0,1023,0,255));
  // put your main code here, to run repeatedly:

}
