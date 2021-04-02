#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    MOUSE,
    ADJUST,
};

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _MOUSE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // QWERTY
    [_QWERTY] = LAYOUT(                                                                                                    //
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, XXXXXXX,                      //
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,                     //
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_PSCR, KC_PSCR, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,                 //
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_QUOT, KC_SCLN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,            //
        KC_ESC, ADJUST, KC_LGUI, KC_LALT, LOWER, KC_BSPC, KC_SPC, KC_ENT, KC_DEL, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT  //
        ),

    // LOWER
    [_LOWER] = LAYOUT(                                                                                                              //
        XXXXXXX, XXXXXXX, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,  //
        _______, XXXXXXX, KC_F7, KC_F8, KC_F9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7, KC_8, KC_9, KC_PPLS, XXXXXXX,              //
        _______, XXXXXXX, KC_F4, KC_F5, KC_F6, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4, KC_5, KC_6, KC_PCMM, XXXXXXX,              //
        _______, XXXXXXX, KC_F1, KC_F2, KC_F3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1, KC_2, KC_3, KC_PEQL, XXXXXXX,              //
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0, XXXXXXX, XXXXXXX, XXXXXXX   //
        ),

    // RAISE
    [_RAISE] = LAYOUT(                                                                                                                 //
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  //
        _______, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,    //
        _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END, XXXXXXX, XXXXXXX,   //
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  //
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   //
        ),

    // MOUSE
    [_MOUSE] = LAYOUT(                                                                                                                 //
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX,  //
        _______, XXXXXXX, XXXXXXX, KC_MS_U, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,  //
        _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_WH_D, KC_BTN2, XXXXXXX, XXXXXXX,  //
        _______, XXXXXXX, DM_REC1, DM_RSTP, DM_PLY1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,  //
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   //
        ),

    // ADJUST
    [_ADJUST] = LAYOUT(                                                                                                                //
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  //
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  //
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  //
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  //
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   //
        )};

static bool     lower_pressed      = false;
static uint16_t lower_pressed_time = 0;
static bool     raise_pressed      = false;
static uint16_t raise_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                lower_pressed      = true;
                lower_pressed_time = record->event.time;

                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _MOUSE);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _MOUSE);

                if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) {
                    register_code(KC_MHEN);
                    unregister_code(KC_MHEN);
                }
                lower_pressed = false;
            }
            return false;
            break;

        case RAISE:
            if (record->event.pressed) {
                raise_pressed      = true;
                raise_pressed_time = record->event.time;

                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _MOUSE);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _MOUSE);

                if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
                    register_code(KC_HENK);
                    unregister_code(KC_HENK);
                }
                raise_pressed = false;
            }
            return false;
            break;

        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;

        default:
            if (record->event.pressed) {
                lower_pressed = false;
                raise_pressed = false;
            }
            break;
    }
    return true;
}
