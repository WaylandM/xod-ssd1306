
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_SSD1306` class instance
    auto display = getValue<input_DEV>(ctx);

    auto x0 = getValue<input_X>(ctx);
    auto y0 = getValue<input_Y>(ctx);
    auto radius = getValue<input_RAD>(ctx);
    auto fill = getValue<input_FILL>(ctx);

    if (fill){
        
    }

    display->drawLine(x0, y0, x1, y1, WHITE);

    emitValue<output_DONE>(ctx, 1);
}
