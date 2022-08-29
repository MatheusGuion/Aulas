#include <LiquidCrystal.h>

// Defines the pins that will be used for the display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Design do dinossauro e Árvore
byte dino [8]
{ B00000,
  B00111,
  B00101,
  B10111,
  B11100,
  B11111,
  B01101,
  B01100,
};

//character for the tree
byte tree [8]
{
  B00011,
  B11011,
  B11011,
  B11011,
  B11011,
  B11111,
  B01110,
  B01110
};
//Funções que foi dado os nomes, tanto o dino e as árvores
const int BUTTON_ENTER = 8;
const int BUTTON_SELECT = 9;

const int MENU_SIZE = 2;
const int LCD_COLUMN = 16;

const int TREE_CHAR = 6;
const int DINO_CHAR = 7;
//Alfabeto que vai ser alterado, pontuação e menu na tela
const String ALPHABET[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };

boolean isPlaying = false;
boolean isShowScore = false;
boolean isDinoOnGround = true;

int currentIndexMenu = 0;
int score = 0;
int scoreListSize = 0;
String scoreList[20];

//Portas de energia, e cada função nomeada
void setup() {
  lcd.begin(16, 2);
  lcd.createChar(DINO_CHAR, dino);
  lcd.createChar(TREE_CHAR, tree);

  Serial.begin(9600);
  pinMode(BUTTON_ENTER, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
}

//Função para criar um loop, dentro do lcd
void loop() {
  lcd.clear();
  handleMenu();

  delay(300);
}
//Função que controla o que aparce no menu
void handleMenu() {
  String menu[MENU_SIZE] = { "START", "SCORE" };

  for (int i = 0; i < MENU_SIZE; i++) {
    if (i == currentIndexMenu) {
      lcd.setCursor(0, i);
      lcd.print("-> ");
    }

    lcd.setCursor(3, i);
    lcd.print(menu[i]);
  }

  if (digitalRead(BUTTON_SELECT) == LOW) {
    currentIndexMenu = currentIndexMenu == 0 ? 1 : 0;
  }

  if (digitalRead(BUTTON_ENTER) == LOW) {
    currentIndexMenu == 0 ? startGame() : showScore();
  }
}
//Determina a função que mostra o menu, e cria a função dos botões para iniciar o jogo
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
//Linguagem que da a pontuação do jogador
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
//Função para iniciar o jogo
void startGame () {
  isPlaying = true;

  while (isPlaying) {
    handleGame();
  }
}
//
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