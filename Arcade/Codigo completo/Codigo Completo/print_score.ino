void printScore(int index, int lastIndex) {
  lcd.clear();

  if (lastIndex == -1) {
    lcd.print("NO SCORE");
  }
  else {
    lcd.print(scoreList[index]);

    if (index < lastIndex) {
      lcd.setCursor(0, 1);
      lcd.print(scoreList[index + 1]);
    }
  }
}
