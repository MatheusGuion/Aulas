//Salvar a pontuação 
void saveScore () {
  lcd.clear();

  String nick = "";
  int nameSize = 0;
  int alphabetCurrentIndex = 0;

  lcd.print("TYPE YOUR NAME");

  while (nameSize != 3) {
    lcd.setCursor(nameSize, 1);
    lcd.print(ALPHABET[alphabetCurrentIndex]);

    if (digitalRead(BUTTON_SELECT) == LOW) {
      alphabetCurrentIndex = alphabetCurrentIndex != 25 ? alphabetCurrentIndex + 1 : 0;
    }

    if (digitalRead(BUTTON_ENTER) == LOW) {
      nick += ALPHABET[alphabetCurrentIndex];

      nameSize++;
      alphabetCurrentIndex = 0;
    }

    delay(300);
  }

  scoreList[scoreListSize] =  nick + " " + score;
  scoreListSize++;

  isPlaying = false;
  score = 0;
}
