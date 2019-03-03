
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_INIT>(ctx))
        return;

    // Get a pointer to the `Adafruit_SSD1306` class instance
    auto display = getValue<input_DEV>(ctx);

    // Attempt to initialize display module; if attempt fails emit pulse from error port
    auto address = getValue<input_ADDRESS>(ctx);
    if (!display->begin(SSD1306_SWITCHCAPVCC, address)) {
        emitValue<output_ERR>(ctx, 1);
        return;
    }

    // Pulse that module initialized successfully
    emitValue<output_OK>(ctx, 1);
}
