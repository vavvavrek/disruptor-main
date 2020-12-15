

const int echopin01 = A0;
const int echopin02 = A1;
const int echopin03 = A3;
const int powpin01 = 12;


void setup() {
  // put your setup code here, to run once:
 pinMode(echopin01, INPUT);
 pinMode(powpin01, OUTPUT);
 pinMode(echopin02, INPUT);
 pinMode(echopin03, INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(powpin01, HIGH);

  int cm = analogRead(A0);
  int duration = analogRead(A1);
  int deeelay = analogRead(A3);
  int brightness01 = map(cm, 1023, 0, 120, 255);
  int sounding01 = map(cm, 1023, 0, -1, 521);
  int duration01 = map(duration, 1023, 0, 0, 24);
  int duration02 = map(deeelay, 1023, 0, 9000, -10);
  tone(3, duration02, sounding01);
  Serial.print(deeelay);
 
  analogWrite(13, brightness01);  //set led to mapped brightness of inverted distance
  delay(duration01);
 
}
