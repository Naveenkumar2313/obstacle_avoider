const int trigPin = 3;
const int echoPin = 5;
const int m1p1 = 6;
const int m1p2 = 7;
const int m2p1 = 8;
const int m2p2 = 9;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(m1p1,OUTPUT);
  pinMode(m1p2,OUTPUT);
  pinMode(m2p1,OUTPUT);
  pinMode(m2p2,OUTPUT);
}

void loop() {
  digitalWrite(m1p1,HIGH);
  digitalWrite(m2p1,HIGH);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);

  if(distance>30){
  digitalWrite(m1p1,HIGH);
  digitalWrite(m2p1,HIGH);
  digitalWrite(m1p2,LOW);
  digitalWrite(m2p2,LOW);
  } 
  
  else{
  digitalWrite(m1p1,LOW);
  digitalWrite(m2p1,LOW);
  digitalWrite(m1p2,HIGH);
  digitalWrite(m2p2,HIGH);
  }  
}
