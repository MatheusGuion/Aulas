//Função que controla o que aparce no menu
void handleMenu() {
  String menu[MENU_SIZE] = { "START" };

    lcd.setCursor(3, i);
    lcd.print(menu[i]);
  }

  if (digitalRead(BUTTON_SELECT) == LOW) {
    currentIndexMenu = currentIndexMenu == 0 ? 1 : 0;
  }

  if (digitalRead(BUTTON_ENTER) == LOW) {
    currentIndexMenu == 0 ? startGame() : showScore();
  }
