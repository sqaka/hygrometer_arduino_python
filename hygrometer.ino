/*
  parts used:
  - higrometer YL-69 / HC-38 (WINGONEER)
  - Bluetooth4.0 BLE-module SH-HC-08 (DSD TECH)
*/

int sampleData = 0;
int ledPin = 13;
const int sensorPin = A0;
const float baselineTemp = 25.0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    sampleData = Serial.read();
    if (sampleData == '1')
    {
      digitalWrite(ledPin, HIGH);
      Serial.println("ON");
    }
    else if (sampleData == '0')
    {
      digitalWrite(ledPin, LOW);
      Serial.println("OFF");
    }
  }

  int sensorVal = analogRead(sensorPin);
  Serial.print("sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  float temperature = (voltage - .5) * 100;
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  delay(1000);
}
