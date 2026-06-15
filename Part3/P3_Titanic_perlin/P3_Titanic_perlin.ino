#include <FastLED.h>

#define PIN_SW_COLOR 2
#define PIN_SW_MODE 4
#define PIN_LED 6       // LED 스트립 연결 핀

#define NUM_LEDS 20     // LED 개수
#define BRIGHTNESS 255  // 밝기 (0~255)

CRGB leds[NUM_LEDS];

void setup() {
  pinMode(PIN_SW_COLOR, INPUT_PULLUP);
  pinMode(PIN_SW_MODE, INPUT_PULLUP);

  FastLED.addLeds<WS2812B, PIN_LED, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  FastLED.clear();
  FastLED.show();
}

void loop() {
  if( digitalRead(PIN_SW_MODE) == LOW) {
    for(int i = 0; i < NUM_LEDS; i++) {
      if(digitalRead(PIN_SW_COLOR) == LOW) leds[i] = CRGB(255, 255, 255);
      else leds[i] = CRGB(255, 127, 13);
    }
  }
  
  else {
    for(int i = 0; i < NUM_LEDS; i++) {
      int Noise = inoise8(i*100, millis()/6);
      Noise = constrain(Noise*2-200, 0, 255);

      if(digitalRead(PIN_SW_COLOR) == LOW) leds[i] = CRGB(Noise, Noise, Noise);
      else leds[i] = CRGB(Noise, Noise * 0.5, Noise * 0.05);
    }
  }

  FastLED.show(); 
  delay(10);
}
//Elehobby3 Coding P3 Titanic_V1.5 2025.05.25 By CJ Park, Fin code edited 26.04.20