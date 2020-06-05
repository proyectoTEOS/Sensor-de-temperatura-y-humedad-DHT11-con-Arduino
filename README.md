# Sensor de temperatura y humedad DHT11
Obtén la temperatura y humedad relativa del sensor DHT22 con Arduino.

### Requisitos
- Tener el IDE de [Arduino](https://www.arduino.cc/en/Main/Software) (o el de tu preferencia) con la versión más actual
- Tener el material para hacer el proyecto
- Contar con la librería [DHT](https://github.com/adafruit/DHT-sensor-library)

### Código
**[Aquí](https://github.com/proyectoTEOS/Sensor-de-temperatura-y-humedad-DHT11-con-Arduino/blob/master/Sensor-de-temperatura-y-humedad-DHT11-con-Arduino.ino)** podrás obtener el link del código, también dejaremos una vista previa aquí abajo.

```c++
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

```

### Diagrama
El siguiente esquemático muestra como se debe conectar todos los componentes con la placa.
![](https://github.com/proyectoTEOS/Sensor-de-temperatura-y-humedad-DHT11-con-Arduino/blob/master/Sensor-de-temperatura-y-humedad-DHT11-con-Arduino.jpg)
