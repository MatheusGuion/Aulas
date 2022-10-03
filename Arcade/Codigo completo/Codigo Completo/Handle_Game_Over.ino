//Aparecer o game over na tela
void handleGameOver () {
  lcd.clear();
  lcd.print("GAME OVER");

  lcd.setCursor(0, 1);
  lcd.print("SCORE: ");
  lcd.print(score);

  delay(2000);
  saveScore();
}
