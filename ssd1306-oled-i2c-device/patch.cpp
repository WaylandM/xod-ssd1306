#pragma XOD error_raise enable

// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_SSD1306"
#pragma XOD require "https://github.com/adafruit/Adafruit-GFX-Library"
#pragma XOD require "https://github.com/adafruit/Adafruit_BusIO"

//Include C++ libraries
{{#global}}
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
{{/global}}

// Adafruit_SSD1306 class wants to know I2C bus in the moment of instantiation
// but we don't know them at this moment.
// Therefore, we reserve memory to store an instance of the class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(Adafruit_SSD1306)];
};

// Define our custom type as a pointer on the class instance.
using Type = Adafruit_SSD1306*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);
    auto wire = getValue<input_I2C>(ctx);
    auto width = getValue<input_WIDTH>(ctx);
    auto height = getValue<input_HEIGHT>(ctx);
    auto reset_pin = getValue<input_RESET_PIN>(ctx);

    // Create a new object in the memory area reserved previously.
    Type display = new (state->mem) Adafruit_SSD1306(width, height, wire, reset_pin);

    // Attempt to initialize display module; if attempt fails raise error
    auto address = getValue<input_ADDRESS>(ctx);
    if (!display->begin(SSD1306_SWITCHCAPVCC, address)) {
      raiseError(ctx);
      return;
    }

    emitValue<output_DEV>(ctx, display);
}
