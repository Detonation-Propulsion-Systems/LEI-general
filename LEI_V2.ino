int TTL_in  = 5;
int TTL_out = 7;
float duty  = 30;  //duty cycle in % DO NOT EXCEED 40
int trigger = 0; //value of trigger signal
int dwell   = 3; //dwell time in ms %DO NOT EXCEED 9
int through = 10; //low time in ms
int count   = 30; //number of sparks to generate
int num     = 0;
void setup() {
  pinMode(TTL_in, INPUT);
  pinMode(TTL_out, OUTPUT);
  digitalWrite(TTL_out, LOW);
  trigger = 0;
  through = ceil(dwell*100/duty - dwell);
}

void loop() {

  trigger = digitalRead(TTL_in);
  
  if (trigger) {
    num = 0;
    while (num<count){
      digitalWrite(TTL_out,HIGH);
      delay(dwell);
      digitalWrite(TTL_out,LOW);
      delay(through);
      num++;
    }
    delay(4000);
  }
  

  
}
