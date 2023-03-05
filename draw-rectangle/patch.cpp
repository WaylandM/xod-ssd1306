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
    auto w = getValue<input_W>(ctx);
    auto h = getValue<input_H>(ctx);
    auto colour = getValue<input_COLOUR>(ctx);
    auto fill = getValue<input_FILL>(ctx);

    if (fill){
        display->fillRect(x, y, w, h, colour);
    }else{
        display->drawRect(x, y, w, h, colour);
    }

    emitValue<output_DONE>(ctx, 1);
}
