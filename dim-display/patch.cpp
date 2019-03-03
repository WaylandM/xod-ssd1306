
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_SSD1306` class instance
    auto display = getValue<input_DEV>(ctx);

    auto dim_display = getValue<input_DIM>(ctx);

    display->dim(dim_display);

    emitValue<output_DONE>(ctx, 1);
}
