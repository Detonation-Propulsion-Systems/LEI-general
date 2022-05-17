int TTL_in = 7;
int TTL_out = 4;
float duty = 30;  //Duty cycle in %. DO NOT EXCEED 40.
int trigger = 0; //Value of trigger signal.
int dwell = 3; //Dwell time in ms. DO NOT EXCEED 9.
int through; //Low time in ms.
int count = 100; //Number of sparks to generate.
int num = 0;

void setup() {

  pinMode(TTL_in, INPUT);
  pinMode(TTL_out, OUTPUT);

  through = ceil(dwell * 100 / duty - dwell);
}

void loop() {

  trigger = digitalRead(TTL_in);

  if (trigger) {

    while (num < count) {

      digitalWrite(TTL_out, HIGH);
      
      delay(dwell);
      
      digitalWrite(TTL_out, LOW);
      
      delay(through);
      
      num ++;
    }
    delay(4000);
  }
}
