#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_SSD1306` class instance
    auto display = getValue<input_DEV>(ctx);

    auto x = getValue<input_X>(ctx);
    auto y = getValue<input_Y>(ctx);
    auto colour = getValue<input_COLOUR>(ctx);

    display->drawPixel(x, y, colour);

    emitValue<output_DONE>(ctx, 1);
}
