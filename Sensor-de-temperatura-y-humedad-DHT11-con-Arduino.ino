/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://www.proyecto-teos.com/
*/

#include "DHT.h" //https://github.com/adafruit/DHT-sensor-library
const uint8_t sensorPinT = 2, typeT = DHT11;

DHT dhtT(sensorPinT, typeT);

void setup() {
  Serial.begin(9600);
  dhtT.begin();
}

void loop() {
  delay(2000);
  char toCharTempT[5], toCharHumidityT[5], resultSerialT[25];

  float temperatureT = dhtT.readTemperature();
  float humidityT = dhtT.readHumidity();

  if (isnan(temperatureT) || isnan(humidityT)) {
    Serial.println(F("No es posible obtener datos del sensor DHT"));
    return;
  }

  dtostrf(temperatureT, 3, 1, toCharTempT);
  dtostrf(humidityT, 3, 1, toCharHumidityT);

  strcpy(resultSerialT, toCharTempT);
  strcat(resultSerialT, "°C || ");
  strcat(resultSerialT, toCharHumidityT);
  strcat(resultSerialT, "%H");

  Serial.println(resultSerialT);
}
