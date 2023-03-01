#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_kcfirst(
        KC_F13,   KC_F14,   KC_F15,
        KC_F16,   KC_F17,   KC_F18,   KC_F21,
        KC_F19,   KC_F20,   QK_BOOTLOADER
    )
};

void keyboard_post_init_user(void) {
    // If console is enabled, enable debug
    #ifdef CONSOLE_ENABLE
        debug_enable=true;
        debug_matrix=true;
    #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
    #ifdef CONSOLE_ENABLE
        dprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif
    return true;
}