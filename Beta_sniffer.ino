/*Oled display*/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define with 128
#define high 64
#define OLED_RESET 4

Adafruit_SSD1306 display(with,high, &Wire,OLED_RESET);

/*pote*/
int pote = analogRead(A0);

/*button*/
int button = 16;
int buttonState =0;

void setup() {
  /*Oled display*/
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  /*button*/
  pinMode(button,INPUT);
  
  /*Logo*/
  display.clearDisplay();
  LSLogo();
}

void loop() {
  
  int val = map(pote, 0, 1023, 0, 3);
  display.clearDisplay();
  
  while(StateMenuOne(buttonState,val) == false &&StateMenuTwo() == false){
    ShowMenu(val);
  }
  
}
