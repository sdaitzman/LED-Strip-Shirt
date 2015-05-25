# An LED Strip shirt for nerds who want to look some combination of cute, glowy and/or futuristic
Work in progress.


## Requirements:
- a shirt that fits you
- Adafruit Neopixel-compatible LEDs in two equal strips
- A working Arduino (tested with Uno R3, an Uno knockoff or any pretty-standard hardware should work just fine)

## Instructions:
Not finished.

## Notes:
Stolen from the NeoPixel SourceCode:
```
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic ‘v1’ (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
```

Recommended but not strictly needed (also from NeoPixel):
```
// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel’s data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit…if you must, connect GND first.
```