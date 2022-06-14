#define temp A0

void setup(){
  pinMode(temp, INPUT);
  Serial.begin(9600);
}

void loop(){
  int RawValue = analogRead(temp);
  
  float Voltage = (RawValue / 1023.0) * 5000; //5000 to get milli
  float tempC = (Voltage-500) * 0.1; //500 is the offset
  
  
  Serial.print("Temperature in C = ");
  Serial.println(tempC,1);
  
  int humidity = analogRead(temp);
  Serial.print("Humidity: ");
  Serial.print(map(humidity, 0, 1023, 10, 70));
  Serial.println("%");
  
  Serial.println("-----------------------");
  
  delay(1000);
  
}