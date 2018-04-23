/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/
#include "DHT.h"

const int sensorPinT = 2;
const int typeT = DHT11;
float humidityT, temperatureT;
String resultSerialT;

DHT dhtT(sensorPinT, typeT);

void setup() {
  Serial.begin(9600);
  dhtT.begin();
}

void loop() {
  delay(2000);
  humidityT = dhtT.readHumidity();
  temperatureT = dhtT.readTemperature();
  if (isnan(humidityT) || isnan(temperatureT)) {
    Serial.println("No es posible obtener datos del sensor DHT");
    return;
  }
  resultSerialT = "Temperatura: " + String(temperatureT) + " || Humedad: " + String(humidityT);
  Serial.println(resultSerialT);
}
