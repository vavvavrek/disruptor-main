

const int echopin01 = A0;
const int echopin02 = A1;
const int echopin04 = A2;
const int echopin03 = A3;
const int powpin01 = 12;


void setup() {
  // put your setup code here, to run once:
 pinMode(echopin01, INPUT);
 pinMode(powpin01, OUTPUT);
 pinMode(echopin02, INPUT);
 pinMode(echopin03, INPUT);
 pinMode(echopin04, INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(powpin01, HIGH);

  int cm = analogRead(A0);
  int duration = analogRead(A1);
  int deeelay = analogRead(A3);
  int adjust = analogRead(A2);
  int brightness01 = map(cm, 1023, 0, 120, 255);
  int sounding01 = map(cm, 1023, 0, -1, 521);
  int duration01 = map(duration, 1023, 0, 0, 24);
  int duration02 = map(deeelay, 1023, 0, 1000, -10);
  int adjustment = map(adjust, 1023, 0, -100, 420);
  tone(3, (duration02 + adjustment), sounding01);
  Serial.print(deeelay);
 
  analogWrite(13, brightness01);  //set led to mapped brightness of inverted distance
  delay(duration01);
 
}
