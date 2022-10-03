void setup() {
  lcd.begin(20, 4);
  lcd.createChar(DINO_CHAR, dino);
  lcd.createChar(TREE_CHAR, tree);

  Serial.begin(9600);
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  pinMode(BUTTON_D, INPUT_PULLUP);
}
