// Basic demo for accelerometer readings from Adafruit LIS3DH

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

#include <EEPROM.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int EEPROMSIZE=1024;

// software SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH_CLK);
// hardware SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS);
// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();
bool isBended = false;
int bendCount = 0;

float startTime = millis();
float startNeckX;
float startNeckY;
float startNeckZ;

float bendValue;


#if defined(ARDUINO_ARCH_SAMD)
// for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
   #define Serial SerialUSB
#endif

void setup(void) {
#ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("LIS3DH test!");
  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("LIS3DH found!");
  
  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!
  
  Serial.print("Range = "); Serial.print(2 << lis.getRange());  
  Serial.println("G"); 

  clearEeprom();
  lis.read();
}

void loop() {
  //lis.read();      // get X Y and Z data at once
  // Then print out the raw data
  //Serial.print("X:  "); Serial.print(lis.x); 
  //Serial.print("  \tY:  "); Serial.print(lis.y); 
  //Serial.print("  \tZ:  "); Serial.print(lis.z); 
  int index; 
  if ((isBended==0) && (lis.x > -4500)) {
    Serial.println("You have bended");
    isBended=true;
    bendCount = EEPROM.read(0);
    EEPROM.write(0, bendCount + 1);

    bendValue = map(sqrt(pow(lis.x - startNeckX, 2) + pow(lis.y - startNeckY, 2) + pow(lis.y - startNeckY, 2)), 0, 32768, 0, 255);
    //Serial.println(bendValue);
  
    index = EEPROM.read(0);
    EEPROM.write(index, bendValue);
  }

  if ( (isBended==true) && (lis.x < -5200) ) {
    Serial.println("You are no longer bending");
    //Serial.println("You are no longer bending ");
    isBended = false;
    //currentTimeBending = millis() - startBendTime + EEPROM.read(1);
    //Serial.println(EEPROM.read(0));
  }
  
  sensors_event_t event; 
  lis.getEvent(&event);
 
  delay(200); 

  if (millis() - startTime > 20000) {
    Serial.print("# ");
    Serial.println(EEPROM.read(0));
    //Serial.print("Max Bend "); Serial.println(maxBend());
    Serial.print("Avg "); Serial.print(averageBend(EEPROM.read(0)));
    //Serial.println(averageBend());
    exit(0);
  }
}

void clearEeprom() {
  for (int i = 0; i < EEPROMSIZE; i++) {
    EEPROM.write(i, 0);
  }
}

float maxBend() {
  float value = 0.0;
  float maxBendValue = 0.0;
  for (int i = 1; i < EEPROMSIZE; i++) {
    value = EEPROM.read(i);
    //Serial.println(value);
    if (value > maxBendValue) {
      maxBendValue = value;
      }
  }

  return maxBendValue;
  }

float averageBend(int num_bends) {
  float value = 0.0;
  float totalBend = 0.0;
  for (int i = 1; i < EEPROMSIZE; i++) {
    value = EEPROM.read(i);
    totalBend = value + totalBend;
  }

  return totalBend/num_bends;
  }
