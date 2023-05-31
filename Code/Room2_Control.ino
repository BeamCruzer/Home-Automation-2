#define BLYNK_TEMPLATE_ID "TMPLeKFBNU8k"
#define BLYNK_DEVICE_NAME "Room Control"

//After connecting with the same wifi, search "192.168.1.69/update" to update code
//MAC Address "bc:ff:4d:cf:b2:56"

#define light D6
#define fan D7

bool lightState = 0;
bool fanState = 0;

#define BLYNK_FIRMWARE_VERSION        "1.1.1"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

BLYNK_WRITE(V6)
{
  lightState = param.asInt();
  digitalWrite(light, lightState);
}

BLYNK_WRITE(V7)
{
  fanState = param.asInt();
  digitalWrite(fan, fanState);
}

BLYNK_CONNECTED()
{
  Blynk.virtualWrite(V6, LOW);
  Blynk.virtualWrite(V7, LOW);
}

void setup()
{
  pinMode(light, OUTPUT);
  pinMode(fan, OUTPUT);
  
  digitalWrite(light, LOW);
  digitalWrite(fan, LOW);
  
  Serial.begin(9600);
  delay(100);
  BlynkEdgent.begin();
  AsyncElegantOTA.begin(&server2);
  server2.begin();
}

void loop() 
{
  BlynkEdgent.run();
}
