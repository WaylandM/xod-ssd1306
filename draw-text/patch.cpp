
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_SSD1306` class instance
    auto display = getValue<input_DEV>(ctx);
    auto cursor_x = getValue<input_X>(ctx);
    auto cursor_y = getValue<input_Y>(ctx);
    auto xString = getValue<input_TEXT>(ctx);
    auto font_size = getValue<input_SIZE>(ctx);
    auto colour = getValue<input_COLOUR>(ctx);
    auto wrap = getValue<input_WRAP>(ctx);

    // `length` returns the number of characters and you need an extra one to keep the
    // terminal NUL-character used in C string representation. Initialize to 0’s to
    // ensure the last char is indeed NUL
    // The following line worked on Arduino, but would not compile for esp8266:
    // char cString[length(xString) + 1] = { 0 };
    // Bug fixed by the following four lines provided by Martin Brader:
    int N=length(xString) + 1;
    char cString[N];
    for(int i=0;i<N;i++)
    cString[i]=0;
    // move the data from XString to the plain C string
    dump(xString, cString);

    // Use full 256 char 'Code Page 437' font
    display->cp437(true);
    display->setTextWrap(wrap);
    display->setCursor(cursor_x, cursor_y);
    display->setTextSize(font_size);
    display->setTextColor(colour);
    display->println(cString);

    emitValue<output_DONE>(ctx, 1);
}
