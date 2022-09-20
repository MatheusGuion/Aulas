
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


SoftwareSerial mySoftwareSerial(10, 11); 
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup() 
{
  mySoftawareSerial.begin(9600);
  Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini"));
  Serial.println(F("Initializing DFPlayer ...(May take 3~5seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Unable to begin"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert de SD card!")):
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeout(500);

  myDFPlayer.volume(10);
  myDFPlayer.volumeUP();
  myDFPlayer.volumeDown();

  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);

  myDFPlayer.outputdevice(DFPLAYER_DEVICE_SD);

  myDFPlayer.play(1);

  Serial.println(myDFPlayer.readState());
  Serial.println(myDFPlayer.readeVolume());
  Serial.println(myDFPlayer.readEQ());
  Serial.println(myDFPlayer.readFileCounts());
  Serial.println(myDFPlayer.readCurrentFileNumber());
  Serial.println(myDFPlayer.readFileCountsInFolder(3));
