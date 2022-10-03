//Fazer a árvore aparecer, e definir a posição 
void showTree (int position) {
  lcd.setCursor(position, 1);
  lcd.write(TREE_CHAR);

  // clean the previous position
  lcd.setCursor(position + 1, 1);
  lcd.print(" ");
}
//Definir a posição do dinossauro
void defineDinoPosition () {
  int buttonState = digitalRead(BUTTON_ENTER);
  buttonState == HIGH ? putDinoOnGround() : putDinoOnAir();
}
//Criar a função do dinossauro no chão
void putDinoOnGround () {
  lcd.setCursor(1, 1);
  lcd.write(DINO_CHAR);
  lcd.setCursor(1, 0);
  lcd.print(" ");

  isDinoOnGround = true;
}
//Definir a função de pulo do dinossauro
void putDinoOnAir () {
  lcd.setCursor(1, 0);
  lcd.write(DINO_CHAR);
  lcd.setCursor(1, 1);
  lcd.print(" ");

  isDinoOnGround = false;
