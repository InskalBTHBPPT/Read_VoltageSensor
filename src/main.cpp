#include <Arduino.h>

#define analogInPin 36

int sensorValue = 0;  // value read from the pot

void setup() {
  // initialize serial communication at 115200
  Serial.begin(115200);
}


float read_analogvolt()
{
  // read the analog in value
  sensorValue = analogRead(analogInPin);
  //Serial.print(String(sensorValue)+"  ");

  //3.328 adalah reference value
  //4095 adalah resolusi ADC ESP32
  float temp = (sensorValue*3.328)/4095.0; 
  //Serial.print(String(temp)+"  ");

  float VSense = temp / (7500.0/(30000.0+7500.0));
  VSense = VSense*0.9704 + 0.622; //koreksi atau kalibrasi dengan pembacaan Voltmeter
  //Serial.println (VSense);
  return VSense;
}

void loop() {
  
  Serial.println(read_analogvolt());

  delay(1000);
}
