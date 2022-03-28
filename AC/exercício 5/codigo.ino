int LED = 2;
int BOTAO = 3;
int ESTADO_BOTAO = 0;
int VAR = 0;
int VAR2 = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT);
}
void loop()
{
  VAR = digitalRead(BOTAO);
  if (VAR == 1 && VAR2 == 0)
  {
ESTADO_BOTAO = 1 - ESTADO_BOTAO;
  delay(20);
  }
 VAR2=VAR;
  if(ESTADO_BOTAO ==1){
  digitalWrite(LED, 0);
  }
  else{
    digitalWrite(LED, 1);
  }
  
  
}
