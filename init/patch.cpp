#pragma XOD error_raise enable
#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_INIT

struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_INIT>(ctx))
        return;

    // Get a pointer to the `Adafruit_SSD1306` class instance
    auto display = getValue<input_DEV>(ctx);

    // Attempt to initialize display module; if attempt fails raise error
    auto address = getValue<input_ADDRESS>(ctx);
    if (!display->begin(SSD1306_SWITCHCAPVCC, address)) {
      raiseError(ctx);
      return;
    }

    emitValue<output_DONE>(ctx, 1);
}
