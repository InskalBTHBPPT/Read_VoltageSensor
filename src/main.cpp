#include <Arduino.h> //You can comment this line if you use Arduino IDE

#define analogInPin 36  //ESP32 GPIO 36 (ADC 0)

int sensorValue = 0;  // value read from the ADC0

void setup() {
  // initialize serial communication at 115200
  Serial.begin(115200);
}


float read_analogvolt()
{
  // read the analog in value
  sensorValue = analogRead(analogInPin);
  
  //3.328 is voltage reference value
  //4095 is ESP32 ADC resolution
  float temp = (sensorValue*3.328)/4095.0; 
  
  /*
  Because this voltage sensor is using voltage divider then
  R1 = 30k
  R2 = 7.5k
  */
  
  float Vin = temp / (7500.0/(30000.0+7500.0));
  Vin= Vin*0.9704 + 0.622; //Corection or calibration factor with power supply voltmeter indicator
  
  return Vin;
}

void loop() {
  
  Serial.println(read_analogvolt());

  delay(1000);
}
