#include QMK_KEYBOARD_H
#include "french-unicode.h"
 
// Définition du keymap 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer DEFAULT - Configuration Ergo-L de base
    [_DEFAULT] = LAYOUT_split_3x6_3_ex2(
    //----------------*-------------*-------------*-------------*----------*----------|      |----------*-----------*-------------*-------------*-------------*-------------|
        QK_GESC,        FR_Q,         FR_C,         FR_O,         FR_P,         FR_W,    KC_LEFT,  KC_UP,     FR_J,    FR_M,    FR_D,    OSL(_SYMBOLES), FR_Y,    KC_HOME,
        LSFT_T(KC_TAB), LGUI_T(FR_A), LALT_T(FR_S), LSFT_T(FR_E), LCTL_T(FR_N), FR_F,    KC_RIGHT, KC_DOWN,   FR_L,    RCTL_T(FR_R),     RSFT_T(FR_T),   RALT_T(FR_I), RGUI_T(FR_U),    KC_BSPC,
        KC_LCTL,        FR_Z,         FR_X,         FR_MINS,      FR_V,         FR_B,               FR_DOT,  FR_H,    FR_G,    FR_COMM,        FR_K,    KC_END,
    //----------------*-------------*-------------*-------------*----------*----------|      |----------*----------*-------------*-------------*-------------*-------------|
    //                                      |------------*----------*--------|   |--------*--------------*-------------|

                                                KC_LGUI,   MO(_MOUSE), LALT_T(KC_SPC),  LT(_CODE, KC_ENT), MO(_NUMBERS), TT(_NAVIGATION)
    //                                      |------------*----------*--------|   |--------*--------------*-------------|
    ),  

    // Layer NAVIGATION - Symboles de navigation0189715617
    [_NAVIGATION] = LAYOUT_split_3x6_3_ex2(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,              KC_HOME, KC_PGUP,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, KC_VOLU, KC_BRIU, XXXXXXX, XXXXXXX, KC_PSCR,            KC_END,  KC_PGDN,   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______,
        _______, KC_VOLD, KC_BRID, XXXXXXX, XXXXXXX, TAP_LAYER_GAME,                         TAP_LAYER_BOOT, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                   _______, _______, _______,                        KC_ENT, QK_GESC, TT(_NAVIGATION)
    ),

    // Layer BOOT - Configuration, reset et RGBdvhg1849
    [_BOOT] = LAYOUT_split_3x6_3_ex2(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        _______, RGB_HUI, KC_SLEP, RGB_SAI, RGB_VAI, XXXXXXX,            XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, RM_VALU, KC_BRIU, KC_VOLU,
        _______, RGB_HUD, RGB_TOG, RGB_SAD, RGB_VAD, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, RM_VALD, KC_BRID, KC_VOLD,
                                   _______, _______, _______,                        XXXXXXX, XXXXXXX, TAP_LAYER_RESET
    ),

    // Layer SYMBOLES - Accents et caractères spéciaux français
    [_SYMBOLES] = LAYOUT_split_3x6_3_ex2(
        QK_GESC,        UC(A_CIRC), FR_CCED, UC(O_E), UC(O_CIRC), FR_EURO,     KC_HOME, KC_PGUP,   FR_AT, FR_DLR,    FR_UNDS,    XXXXXXX,    UC(U_CIRC), KC_HOME,
        LSFT_T(KC_TAB), FR_AGRV,    FR_EACU, FR_EGRV, UC(E_CIRC), UC(YEN),     KC_END,  KC_PGDN,   FR_LPRN, FR_RPRN,    UC(I_CIRC), UC(I_UML),  FR_UGRV,    KC_BSPC,
        KC_LCTL,        UC(A_E),    XXXXXXX, FR_MINS, FR_UNDS,    FR_UNDS,                         XXXXXXX, XXXXXXX,    XXXXXXX,    FR_DOT,     XXXXXXX,    KC_END,
                                    _______,  MO(_MOUSE), LALT_T(KC_SPC),                 XXXXXXX, _______, RALT_T(KC_ENT)
    ),

    // Layer CODE - Symboles de programmation
    [_CODE] = LAYOUT_split_3x6_3_ex2(
        _______, FR_CIRC, FR_LABK, FR_RABK, FR_DLR,  FR_PERC,            KC_HOME, KC_PGUP,   FR_AT,   FR_AMPR, FR_ASTR, FR_QUOT, FR_GRV,  _______,
        _______, FR_LCBR, FR_LPRN, FR_RPRN, FR_RCBR, FR_EQL,             KC_END,  KC_PGDN,   FR_BSLS, FR_PLUS, FR_MINS, FR_SLSH, FR_DQUO, _______,
        _______, FR_TILD, FR_LBRC, FR_RBRC, FR_UNDS, FR_HASH,                                FR_PIPE, FR_EXLM, FR_SCLN, FR_COLN, FR_QUES, _______,
                                   _______, _______, LALT_T(KC_SPC),                XXXXXXX, _______, RALT_T(KC_ENT)
    ),

    // Layer MOUSE - Contrôle de souris
    [_MOUSE] = LAYOUT_split_3x6_3_ex2(
        _______, C(FR_X),        KC_MS_WH_UP, KC_MS_WH_DOWN, C(FR_C),      C(FR_V),        KC_HOME, KC_PGUP,   XXXXXXX,     KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, XXXXXXX, _______,
        _______, KC_MS_LEFT,    KC_MS_UP,    KC_MS_DOWN,    KC_MS_RIGHT, C(FR_Z),      KC_END,  KC_PGDN,   XXXXXXX,      KC_LEFT,      KC_DOWN,      KC_UP,        KC_RIGHT, _______,
        _______, KC_BSPC,       S(KC_TAB),   KC_TAB,        KC_DEL,  TAP_LAYER_BOOT,                          XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX, _______, 
                                              XXXXXXX,      _______, TAP_LAYER_GAME,                KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2
    ),

    // Layer pour le Game
    [_GAME] = LAYOUT_split_3x6_3_ex2(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,              KC_HOME, KC_PGUP,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    QK_GESC,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,              KC_END,  KC_PGDN,   KC_H,    KC_J,    KC_K,    KC_L,    KC_VOLU, KC_BSPC,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_VOLD, KC_END,
                                      KC_I, MO(_NUMBERS), KC_SPC,                    KC_ENT, XXXXXXX, TAP_LAYER_RESET
    ),

    // Layer NUM - Chiffres et contrôles de navigation
    [_NUMBERS] = LAYOUT_split_3x6_3_ex2(
        FR_1,    FR_2,    FR_3,    FR_0,   FR_PLUS,FR_MINS,           KC_HOME, KC_PGUP,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
        FR_4,    FR_5,    FR_6,    FR_0,   FR_ASTR,  FR_SLSH,           KC_END,  KC_PGDN,   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______,
        FR_7,    FR_8,    FR_9,   KC_DOT, FR_EQL, FR_PERC,                              XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                   XXXXXXX, XXXXXXX, _______,                      KC_ENT, XXXXXXX, XXXXXXX
    ),
};