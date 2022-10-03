void showScore () {
  isShowScore = true;
  delay(200);

  int currentIndex = 0;
  const int lastIndex = scoreListSize - 1;

  printScore(currentIndex, lastIndex);

  while (isShowScore) {
    if (digitalRead(BUTTON_SELECT) == LOW) {
      currentIndex = currentIndex < lastIndex ? currentIndex + 1 : 0;
      printScore(currentIndex, lastIndex);
    }

    if (digitalRead(BUTTON_ENTER) == LOW) {
      isShowScore = false;
    }

    delay(200);
  }
}
