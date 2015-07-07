//const int INTERRUPT = 12;
const int INTERRUPT = 2;
int preval;
int count;

void setup() {
  pinMode(INTERRUPT, INPUT);
  Serial.begin(9600);

  preval = 0;
  count = 0;
}

void loop() {
//  int val = digitalRead(INTERRUPT);
  int val = analogRead(INTERRUPT);
  int val_digi;
  
if(val > 0) {
//  Serial.println(1);
  val_digi = 1;
}else {
//  Serial.println(0);
  val_digi = 0;
}
//Serial.println(val_digi);


if(val_digi != preval) {
  count++;
//  Serial.println(count);
}

//15度 * 4 =60度回転したとき
if(count >= 4) {
//  Serial.println(1);
  Serial.write(1);
  count = 0;
}
  delay(400);

 preval = val_digi;
}
