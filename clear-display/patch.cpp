
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_SSD1306` class instance
    auto display = getValue<input_DEV>(ctx);

    display->clearDisplay();
    display->display();
    // Draw a single pixel in white
    display->drawPixel(10, 10, WHITE);
    display->drawPixel(20, 20, WHITE);
    display->display();
    display->drawPixel(30, 30, WHITE);
    display->drawPixel(40, 40, WHITE);
    delay(2000);
    display->display();
    display->invertDisplay(true);
    delay(1000);
    display->invertDisplay(false);
    delay(1000);

    emitValue<output_DONE>(ctx, 1);
}
