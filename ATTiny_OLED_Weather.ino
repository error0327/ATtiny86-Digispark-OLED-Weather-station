
#include "SSD1306_minimal.h"
#include <dht.h>
#include <avr/pgmspace.h>

SSD1306_Mini oled;
dht DHT;

// Pins Used :  for the DHT11 i am using PIN 3 , and for the screen SDA on PIN 0 and forh SL i use PIN 2
#define DHT11_PIN 3


void PrintData() {
 oled.startScreen();
 oled.clear(); // Clears the display

 int chk = DHT.read11(DHT11_PIN);

 oled.cursorTo(0, 0); // x:0, y:0
 oled.printString("HomeWeatherStation");
 oled.cursorTo(0, 15); // x:0, y:23
 oled.printStringInt("Temperature : ",DHT.temperature);
 oled.cursorTo(0, 20); // x:0, y:23
 oled.printStringInt("Humidity : ",DHT.humidity);
 delay(5000);
 
}


void setup()
{
  Serial.begin(9600); // we need this for the DHT11
  oled.init(0x3c);  //oled address .
  
  oled.clear();
  delay(1000);
}
 
void loop()
{
 PrintData();
} 
