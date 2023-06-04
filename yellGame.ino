#include <Adafruit_CircuitPlayground.h>

float value;
float midi[127];
int A_four = 440;
int lightLevel, aLightLevel, bLightLevel;
const byte switchPin = 7;
const byte aButton = 4;
const byte bButton = 5;
bool switchVal = 0;
volatile bool aFlag = 0;
volatile bool bFlag = 0;

int good[3][2] = {
  {69, 75}, 
  {72, 75}, 
  {76, 75}
  };

int bad[3][2] = {
    {47, 75},  
    {43, 75}, 
    {40, 75}
  };

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  generateMIDI();
  switchVal = digitalRead(switchPin);
  attachInterrupt(digitalPinToInterrupt(aButton), aPress, RISING);
  attachInterrupt(digitalPinToInterrupt(bButton), bPress, RISING);
}

void loop() {
  switchVal = digitalRead(switchPin);

  if (switchVal) {
    Serial.println("Singleplayer Mode");
    singleplayer();
  } else if (!switchVal) {
    Serial.println("Multiplayer Mode");
    multiplayer();
  }
}

void singleplayer() {
  int target;
  target = random(1, 10);
  for (int i = 0; i < 4; i++) {
    CircuitPlayground.setPixelColor(target, 0, 255, 0);
    delay(250);
    CircuitPlayground.clearPixels();
    delay(250);
  }
  rSG();
  int playerLevel;
  int playerScore = 0;
  for (int i = 0; i < 40; i++) {
    playerLevel = CircuitPlayground.mic.soundPressureLevel(10);
    lightLevel = map(playerLevel, 58, 110, 0, 10);
    soundScore(lightLevel);
    if (lightLevel > playerScore) {
      playerScore = lightLevel;
    }
    delay(90);
  }
  if (playerScore == (target+1)) {
    Serial.println("Target Matched!");
    Serial.println("Next Round");
    win();
  } else {
    Serial.println("Target Missed!");
    Serial.println("Game Over");
    lose();
  }
  delay(3000);
}

void multiplayer() {
  if (aFlag) {
    rSG();
    int aPlayerLevel;
    int aPlayerScore = 0;
    for (int i = 0; i < 40; i++) {
      aPlayerLevel = CircuitPlayground.mic.soundPressureLevel(10);
      aLightLevel = map(aPlayerLevel, 58, 110, 0, 10);
      soundScore(aLightLevel);
      if (aLightLevel > aPlayerScore) {
        aPlayerScore = aLightLevel;
      }
      delay(90); 
    }
    for (int i = 0; i < 4; i++) {
      CircuitPlayground.setPixelColor(aPlayerScore, 0, 255, 0);
      delay(250);
      CircuitPlayground.clearPixels();
      delay(250);
    }
    delay(4000);
    rSG();
    int bPlayerLevel;
    int bPlayerScore = 0;
    for (int i = 0; i < 40; i++) {
      bPlayerLevel = CircuitPlayground.mic.soundPressureLevel(10);
      bLightLevel = map(bPlayerLevel, 58, 110, 0, 10);
      soundScore(bLightLevel);
      if (bLightLevel > bPlayerScore) {
        bPlayerScore = bLightLevel;
      }
      delay(90); 
    }
    for (int i = 0; i < 4; i++) {
      CircuitPlayground.setPixelColor(bPlayerScore, 0, 255, 0);
      delay(250);
      CircuitPlayground.clearPixels();
      delay(250);
    }
    if (aPlayerScore > bPlayerScore) {
      aWin();
    } else if (aPlayerScore == bPlayerScore) {
      tie();
    } else {
      aLose();
    }
    aFlag = 0;
  } else if (bFlag) {
    rSG();
    int bPlayerLevel;
    int bPlayerScore = 0;
    for (int i = 0; i < 40; i++) {
      bPlayerLevel = CircuitPlayground.mic.soundPressureLevel(10);
      bLightLevel = map(bPlayerLevel, 58, 110, 0, 10);
      soundScore(bLightLevel);
      if (bLightLevel > bPlayerScore) {
        bPlayerScore = bLightLevel;
      }
      delay(90); 
    }
    for (int i = 0; i < 4; i++) {
      CircuitPlayground.setPixelColor(bPlayerScore, 0, 255, 0);
      delay(250);
      CircuitPlayground.clearPixels();
      delay(250);
    }
    delay(4000);
    rSG();
    int aPlayerLevel;
    int aPlayerScore = 0;
    for (int i = 0; i < 40; i++) {
      aPlayerLevel = CircuitPlayground.mic.soundPressureLevel(10);
      aLightLevel = map(aPlayerLevel, 58, 110, 0, 10);
      soundScore(aLightLevel);
      if (aLightLevel > aPlayerScore) {
        aPlayerScore = aLightLevel;
      }
      delay(90); 
    }
    for (int i = 0; i < 4; i++) {
      CircuitPlayground.setPixelColor(aPlayerScore, 0, 255, 0);
      delay(250);
      CircuitPlayground.clearPixels();
      delay(250);
    }
    if (aPlayerScore > bPlayerScore) {
      aWin();
    } else if (aPlayerScore == bPlayerScore) {
      tie();
    } else {
      aLose();
    }
    bFlag = 0;
  } else {
    Serial.println("Waiting");
  }
}

void aPress() {
  aFlag = 1;
}

void bPress() {
  bFlag = 1;
}

void soundScore(int lightLevel) {
  if (lightLevel == 1) {
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
  }
  else if (lightLevel == 2){
    for (int i = 0; i < 2; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
  }
  else if (lightLevel == 3){
    for (int i = 0; i < 3; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
  }
  else if (lightLevel == 4){
    for (int i = 0; i < 4; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
  }
  else if (lightLevel == 5){
    for (int i = 0; i < 5; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
  }
  else if (lightLevel == 6){
    for (int i = 0; i < 6; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
  }
  else if (lightLevel == 7){
    for (int i = 0; i < 7; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
  }
  else if (lightLevel == 8){
    for (int i = 0; i < 8; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
  }
  else if (lightLevel == 9){
    for (int i = 0; i < 9; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
  }
  else if (lightLevel == 10){
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
  }
  else {
    CircuitPlayground.clearPixels();
  }
}

void win() {
  int arraySize;
  arraySize = sizeof(good) / sizeof(good[0]);
  playPhrase(good, arraySize);
  for (int i = 0; i < 4; i++) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 0, 255, 0);
    }
    delay(200);
    CircuitPlayground.clearPixels();
    delay(200);
  }
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 0, 255, 0);
  }
  delay(750);
  CircuitPlayground.clearPixels();
}

void aWin() {
  int arraySize;
  arraySize = sizeof(good) / sizeof(good[0]);
  playPhrase(good, arraySize);
  for (int i = 0; i < 5; i++) {
    CircuitPlayground.setPixelColor(i, 0, 255, 0);
  }
  for (int i = 5; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 255, 0, 0);
  }
  delay(2000);
  CircuitPlayground.clearPixels();
}

void lose() {
  int arraySize;
  arraySize = sizeof(bad) / sizeof(bad[0]);
  playPhrase(bad, arraySize);
  for (int i = 0; i < 4; i++) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, 255, 0, 0);
    }
    delay(200);
    CircuitPlayground.clearPixels();
    delay(200);
  }
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 255, 0, 0);
  }
  delay(750);
  CircuitPlayground.clearPixels();
}

void aLose() {
  int arraySize;
  arraySize = sizeof(bad) / sizeof(bad[0]);
  playPhrase(bad, arraySize);
  for (int i = 0; i < 5; i++) {
    CircuitPlayground.setPixelColor(i, 255, 0, 0);
  }
  for (int i = 5; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 0, 255, 0);
  }
  delay(2000);
  CircuitPlayground.clearPixels();
}

void tie() {
  int arraySize;
  arraySize = sizeof(good) / sizeof(good[0]);
  playPhrase(good, arraySize);
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 0, 255, 0);
  }
  delay(2000);
  CircuitPlayground.clearPixels();
}

void rSG() {
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 255, 0, 0);
  }
  delay(1000);
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 127, 127, 0);
  }
  delay(1000);
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 0, 255, 0);
  }
  delay(750);
  CircuitPlayground.clearPixels();
}

void generateMIDI() {
  for (int x = 0; x < 127; ++x) {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}

void playPhrase(int a[][2], int size) {
    for(int i = 0; i < size; i++) {
      CircuitPlayground.playTone(midi[a[i][0]], a[i][1]);
      Serial.println(midi[a[i][0]]);
      delay(1);
    }
}
