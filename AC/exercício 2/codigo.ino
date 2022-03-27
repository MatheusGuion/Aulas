void setup()
{
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  digitalWrite(3, HIGH);
  digitalWrite(8, LOW);
  delay(1000); 
  digitalWrite(3, LOW);
  digitalWrite(8, HIGH);
  delay(1000); 
}
