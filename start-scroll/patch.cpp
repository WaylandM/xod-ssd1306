
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_SSD1306` class instance
    auto display = getValue<input_DEV>(ctx);
    auto first = getValue<input_FIRST>(ctx);
    auto last = getValue<input_LAST>(ctx);
    auto direction = getValue<input_DIR>(ctx);

    switch (direction) {
        case 0:
            display->startscrollleft(first, last);
            break;
        case 1:
            display->startscrollright(first, last);
            break;
        case 2:
            display->startscrolldiagleft(first, last);
            break;
        case 3:
            display->startscrolldiagright(first, last);
            break;
    }

    emitValue<output_DONE>(ctx, 1);

}
