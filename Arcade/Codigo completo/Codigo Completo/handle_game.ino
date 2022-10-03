void handleGame() {
  lcd.clear();

  int buttonPressedTimes = 0;

  // Generate two random distances for the space between the trees
  int secondPosition = random(4, 9);
  int thirdPosition = random(4, 9);
  int firstTreePosition = LCD_COLUMN;

  const int columnValueToStopMoveTrees = -(secondPosition + thirdPosition);

  // this loop is to make the trees move, this loop waiting until
  // all the trees moved
  for (; firstTreePosition >= columnValueToStopMoveTrees; firstTreePosition--) {

    lcd.setCursor(13, 0);
    lcd.print(score);

    defineDinoPosition();

    int secondTreePosition = firstTreePosition + secondPosition;
    int thirdTreePosition = secondTreePosition + thirdPosition;

    showTree(firstTreePosition);
    showTree(secondTreePosition);
    showTree(thirdTreePosition);

    if (isDinoOnGround) {
      if (firstTreePosition == 1 || secondTreePosition == 1 || thirdTreePosition == 1) {
        handleGameOver();
        delay(5000);
        break;
      }
      buttonPressedTimes = 0;

    } else {
      if (buttonPressedTimes > 3) {
        score -= 3;
      }

      buttonPressedTimes++;
    }

    score++;
    delay(500);
  }
}
