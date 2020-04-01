// ===============================================
// SIMUINO_BEGIN
// ===============================================
// BOARD_TYPE:  UNO
// SKETCH_NAME: HelloWorld_UNO.ino
// SIM_LENGTH:  600
// WIN_LAYOUT:    2
// SO_DELAY:     40
//================================================
//  Scenario
//================================================
//
// SCENDIGPIN 10    1    0
// SCENDIGPIN 10   50    1
// SCENDIGPIN 10  100    0
// SCENDIGPIN 10  200    1
// SCENDIGPIN  9    1    0
// SCENDIGPIN  9   40    1
// SCENDIGPIN  9  130    0
//
// SCENANAPIN  4    1    5
// SCENANAPIN  5    1    8 
// SCENANAPIN  4   80   12
// SCENANAPIN  5  120   18 
//
//================================================
// Simuino log text customization
//================================================
// PINMODE_OUT: 11  "PIN: Led Urgent"
// PINMODE_OUT: 12  "PIN: Led Blink"

// DIGITALWRITE_LOW:  11  "Waiting"
// DIGITALWRITE_HIGH: 11  "Urgent"
// DIGITALWRITE_LOW:  12  "Led is off"
// DIGITALWRITE_HIGH: 12  "Led is on"

// DIGITALREAD:  9  "Read from nine"
// DIGITALREAD: 10  "Read from ten"


// ANALOGREAD: 4  "read analog four"
// ANALOGREAD: 5  "read analog five"

// ===============================================
// SIMUINO_END
// ===============================================
//-------- DIGITAL PIN settings ------------------
#include "EEPROM.h"
// Leds
int URGENTLED    = 11;
int BLINKLED     = 12;
int IN_PIN       = 10;
int CONTROL      =  9;
 
//-------- ANALOGUE PIN settings
int SENSOR1  = 4;
int SENSOR2  = 5;

//================================================
//  Function Declarations
//================================================

void blinkLed(int n);

//================================================
void urgent()
//================================================
{
      digitalWriteX(69,URGENTLED, HIGH); 
      delayX(70,401);
      digitalWriteX(71,URGENTLED, LOW); 
}
//================================================
void very_urgent()
//================================================
{
      digitalWriteX(77,URGENTLED, HIGH); 
      delayX(78,402);
      digitalWriteX(79,URGENTLED, LOW); 
}
//================================================
void setup()
//================================================
{
  Serial.beginX(85,9600); 
  attachInterruptX(86,0,urgent, CHANGE);
  attachInterruptX(87,1,very_urgent, RISING);
  pinModeX(88,BLINKLED,OUTPUT);   
  pinModeX(89,URGENTLED,OUTPUT);   
  pinModeX(90,IN_PIN,INPUT);
  pinModeX(91,CONTROL,INPUT);
}
	 
//================================================ 
void loop()
//================================================
{
  int value1,value2,i;

  Serial.printlnX(100,"Hello Simuino!");
  value1 = analogReadX(101,SENSOR1);
  value2 = analogReadX(102,SENSOR2);
  Serial.printX(103,"Analog 1 value read: ");
  Serial.printlnX(104,value1);
  Serial.printX(105,"Analog 2 value read: ");
  Serial.printlnX(106,value2);
  blinkLed(value1);
  value1 = digitalReadX(108,IN_PIN);
  value2 = digitalReadX(109,CONTROL);
  Serial.printX(110,"Digital IN_PIN read: ");
  Serial.printlnX(111,value1);
  Serial.printX(112,"Digital CONTROL read: ");
  Serial.printlnX(113,value2);
  
  delayX(115,1000); 
  EEPROM.writeX(116,55,120);
  int lue = EEPROM.readX(117,55);
  Serial.printX(118,"EEPROM value is: ");
  Serial.printlnX(119,lue);
}

//================================================
void blinkLed(int n)
//================================================
{
  int i;
  for(i=1;i<=10;i++)
    {
      digitalWriteX(129,BLINKLED, HIGH); 
      delayX(130,500);
      digitalWriteX(131,BLINKLED, LOW); 
    }
}
//================================================
// End of Sketch
//================================================
