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
