
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_SSD1306` class instance
    auto display = getValue<input_DEV>(ctx);
    auto x0 = getValue<inputX0>(ctx);
    auto y0 = getValue<inputY0>(ctx);
    auto x1 = getValue<inputX1>(ctx);
    auto y1 = getValue<inputY1>(ctx);
    auto x2 = getValue<inputX2>(ctx);
    auto y2 = getValue<inputY2>(ctx); 
    auto colour = getValue<input_COLOUR>(ctx);
    auto fill = getValue<input_FILL>(ctx);

    if (fill){
        display->fillTriangle(x0, y0, x1, y1, x2, y2, colour);
    }else{
        display->drawTriangle(x0, y0, x1, y1, x2, y2, colour);
    }

    emitValue<output_DONE>(ctx, 1);
}
