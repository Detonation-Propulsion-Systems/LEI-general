#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE    DHT11     // DHT 11
#define DHTPIN 2

DHT_Unified dht(DHTPIN, DHTTYPE);
int ledPin = 4;

void setup() {
  
  Serial.begin(9600);
  dht.begin();
  sensor_t sensor;

  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  Serial.print(F("Temperature: "));
  Serial.print(event.temperature);
  Serial.println(F("°C"));

  if (event.temperature >= 25) {
    
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  
  delay(10);
}
