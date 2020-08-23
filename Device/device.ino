#include "neopixel.h"

#define NUMBER_OF_LED 72 // This is the number of LEDs in your strip
#define LED_PIN 16 // This is the pin you plugged the data wire into

static NeoPixel *neopixel = NULL;
static int test = 0;
static bool runTest = false;

void setup(){
    neopixel = new NeoPixel(LED_PIN, NUMBER_OF_LED);
    runTest = neopixel->init();
}

void loop(){

    if (runTest){
        switch (test % 3){

        case 0:
            Serial.println("Rainbow...");
            neopixel->showRainbowCycle(60, 25, 20, 200);
            neopixel->showColor(0, 0, 0);
            break;

        case 1:
            Serial.println("Theatre-style crawling lights...");
            neopixel->showTheaterChase(236, 19, 122, 500);
            neopixel->showColor(0, 0, 0);
            break;

        case 2:
            Serial.println("Detonate...");
            neopixel->showDetonate(236, 19, 122, 800);
            neopixel->showColor(0, 0, 0);
            break;

        }
        test++;
    }
    wait_ms(2000);
}
