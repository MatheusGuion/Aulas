const int Button_A = 4;
const int Button_B = 5;
const int Button_C = 7; 
const int Button_D = 8; 
void setup();{
  Serial.begin(9600);
  pinMode(Button_A, INPUT);
  pinMode(Button_B, INPUT);
  pinMode(Button_C, INPUT);
  pinMode(Button_D, INPUT);
}

void loop(){
  if (Serial.available()){
  char Button = Serial.read();
  switch(Button){  
  case '1':
  
}
