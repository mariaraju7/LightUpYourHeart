#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h>
#endif

#define PIN        6
#define NUMPIXELS 30

LiquidCrystal_I2C lcd(0x27, 16, 2);


const int PulseWire = 0;      
const int LED13 = 13;          
int Threshold = 550;

PulseSensorPlayground pulseSensor;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int valDelay;


void setup(void) {

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  
  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED13);
  //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);
  pulseSensor.begin();
  pixels.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  }


void pixelDesign(){
  
  pixels.clear();
  
  for(int i=0; i<NUMPIXELS; i++) { 

    int myBPM = pulseSensor.getBeatsPerMinute();
    lcd.print("BPM: ");
    lcd.print(myBPM); 



void coolerColorWipe(uint32_t color,uint32_t color2) {
  //0,128,128 =  teal
  for(int i=0; i<30; i++) { // For each pixel in strip...
    if (i%2==1){
      pixels.setPixelColor(i, color);         //  Set pixel's color (in RAM)
      pixels.show(); 
    }
    else if(i%2==0){
      pixels.setPixelColor(i,color2);
      pixels.show();
    }
    delay(valDelay);                           //  Pause for a moment
  }
}


if (myBPM >= 0 && myBPM <= 20){
      valDelay =700;
      pixels.setPixelColor(i, pixels.Color(255,255,255));
    }
    else if(myBPM > 20 && myBPM <= 40){
      valDelay = 500;
      pixels.setPixelColor(i, pixels.Color(255,165,0));
    }
    else if(myBPM > 40 && myBPM <= 60){
      valDelay = 300;
      pixels.setPixelColor(i, pixels.Color(255,255,0));
    }
    else if(myBPM > 60 && myBPM <= 80){
      valDelay = 100;
      pixels.setPixelColor(i, pixels.Color(0,255,0));
    }
    else if(myBPM > 90 && myBPM <= 120){
      valDelay = 70;
      pixels.setPixelColor(i, pixels.Color(0,0,255));
    }
    else if(myBPM > 120 && myBPM <= 150){
      valDelay = 40;
      pixels.setPixelColor(i, pixels.Color(128,0,128));
    }
    else{
      valDelay = 20;
      pixels.setPixelColor(i, pixels.Color(255,0,0));
    }  
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    
    delay(valDelay);
    pixels.show(); 

    lcd.clear();
  } 
}

void loop(void) {
  pixelDesign();

}
