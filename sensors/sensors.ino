#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  float ppm = analogRead(A0);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print(ppm);
  Serial.print(",");
  Serial.print(temperature);
  Serial.print(",");
  Serial.print(humidity);
  Serial.println();

  delay(60000); 
}
