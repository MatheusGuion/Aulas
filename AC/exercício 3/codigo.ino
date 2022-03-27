void setup()
{
  pinMode(1, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(1, HIGH);
  delay(2000); 
  digitalWrite(7, HIGH);
  delay(2000);
  digitalWrite(9, HIGH);
  delay(2000);
  digitalWrite(10, HIGH);
  delay(2000);
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(1, LOW);
  delay(2000);
  digitalWrite(7, LOW);
  delay(2000);
  digitalWrite(9, LOW);
  delay(2000);
  digitalWrite(10, LOW);
  delay(2000);
  digitalWrite(13, LOW);
  delay(2000);
}
