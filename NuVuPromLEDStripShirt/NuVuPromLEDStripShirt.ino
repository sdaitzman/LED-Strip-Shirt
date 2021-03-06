#include <Adafruit_NeoPixel.h>

#define leftPin  8
#define rightPin 9

#define LEDs 14

// initialize LED Strips
Adafruit_NeoPixel leftStrip =  Adafruit_NeoPixel(LEDs, leftPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel rightStrip = Adafruit_NeoPixel(LEDs, rightPin, NEO_GRB + NEO_KHZ800);

void setup() {
	// initialize Serial
	Serial.begin(9600);

	// initialize LED Strips
	leftStrip.begin();
	rightStrip.begin();
}

void loop() {
	// whiteLight(0, 20, 35);
	rainbowCycle(10);
}



// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
	uint16_t i, j;

for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
	for(i=0; i<LEDs; i++) {
		leftStrip.setPixelColor(i, leftWheel(((i * (256) / leftStrip.numPixels()) + j) & 255));
		rightStrip.setPixelColor(i, rightWheel(((i * (256) / leftStrip.numPixels()) + j) & 255));
	}
	leftStrip.show();
	rightStrip.show();
	delay(wait);
	}
}

// fade in and out white light at specified min, max, fadeInOut time length
void whiteLight(int minBrightness, int maxBrightness, int fadeInOut) {
	Serial.println(millis());
	for(int i = minBrightness;i<=maxBrightness;i++) {
		leftStrip.show();
		rightStrip.show();
		for(int j = 0;j<LEDs;j++) {
			leftStrip.setPixelColor(j, leftStrip.Color(i, i, i));
			rightStrip.setPixelColor(j, rightStrip.Color(i, i, i));
			delay(fadeInOut / (LEDs * 2));
			Serial.println(fadeInOut / (LEDs * 2));
		}
	}
	for(int i = maxBrightness;i>=minBrightness;i--) {
		leftStrip.show();
		rightStrip.show();
		for(int j = 0;j<LEDs;j++) {
			leftStrip.setPixelColor(j, leftStrip.Color(i, i, i));
			rightStrip.setPixelColor(j, rightStrip.Color(i, i, i));
			delay(fadeInOut / (LEDs * 2));
		}
	}
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t leftWheel(byte WheelPos) {
	if(WheelPos < 85) {
		return leftStrip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
	} else if(WheelPos < 170) {
		WheelPos -= 85;
		return leftStrip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
	} else {
		WheelPos -= 170;
		return leftStrip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
	}
}

uint32_t rightWheel(byte WheelPos) {
	if(WheelPos < 85) {
		return rightStrip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
	} else if(WheelPos < 170) {
		WheelPos -= 85;
		return rightStrip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
	} else {
		WheelPos -= 170;
		return rightStrip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
	}
}
