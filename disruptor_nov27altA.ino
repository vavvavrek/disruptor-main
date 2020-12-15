

const int echopin01 = A0;
const int echopin02 = A1;
const int echopin03 = A3;
const int echopin04 = A2;
const int highfreqecho = A4;
const int lowfreqecho = A5;

const int powpin01 = 12;


void setup() {
  // put your setup code here, to run once:
 pinMode(echopin01, INPUT);
 pinMode(echopin04, INPUT);
 pinMode(echopin02, INPUT);
 pinMode(echopin03, INPUT);
 
 pinMode(highfreqecho, INPUT);
 pinMode(lowfreqecho, INPUT);
 pinMode(powpin01, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(powpin01, HIGH);

  int cm = analogRead(A0);
  int duration = analogRead(A1);
  int deeelay = analogRead(A3);
  int deeelay02 = analogRead(A2);
  int hiway = analogRead(A4);
  int loway = analogRead(A5);
  int brightness01 = map(cm, 1023, 0, 144, 255);
  int lolimit = map(loway, 0, 1023, 100, -100);
  int hilimit = map(hiway, 0, 1023, 777, 8);
  int sounding01 = map(cm, 1023, 0, lolimit, hilimit);
  int duration01 = map(duration, 1023, 0, 0, 24);
  int duration02 = map(deeelay, 1023, 0, 0, 500);
  int duration03 = map(deeelay02, 1023, 0, 0, 60);
  tone(3, sounding01, duration01);
 
  analogWrite(13, brightness01);  //set led to mapped brightness of inverted distance
  delay(duration02);
  delay(duration03);
 
}
