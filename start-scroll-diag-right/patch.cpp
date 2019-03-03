
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_SSD1306` class instance
    auto display = getValue<input_DEV>(ctx);
    auto start = getValue<input_START>(ctx);
    auto stop = getValue<input_STOP>(ctx);

    display->startscrolldiagright(start, stop);

    emitValue<output_DONE>(ctx, 1);

}
