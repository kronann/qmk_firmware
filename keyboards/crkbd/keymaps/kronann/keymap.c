#include QMK_KEYBOARD_H
#include "french-unicode.h"

// Définition du keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer DEFAULT - Configuration Ergo-L de base
    [_DEFAULT] = LAYOUT_split_3x6_3_ex2(
    //----------------*-------------*-------------*-------------*-------------*-------*__________|      |__________*--------*-------------*-------------*--------------*-------------*-------------|
        QK_GESC,        KC_Q,         KC_C,         KC_O,         KC_P,         KC_W,   KC_LEFT,          KC_UP,     KC_J,   KC_M,         KC_D,         OSL(_SYMBOLES), KC_Y,         KC_HOME,
        LSFT_T(KC_TAB), LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_E), LCTL_T(KC_N), KC_F,   KC_RIGHT,         KC_DOWN,   KC_L,   RCTL_T(KC_R), RSFT_T(KC_T), RALT_T(KC_I),   RGUI_T(KC_U), KC_BSPC,
        KC_LCTL,        KC_Z,         KC_X,         KC_MINS,      KC_V,         KC_B,                                KC_DOT, KC_H,         KC_G,         KC_COMM,        KC_K,         KC_END,
    //----------------*-------------*-------------*-------------*-------------*-------*__________|      |__________*--------*-------------*-------------*--------------*-------------*-------------|
    //                                                |---------*-------------*------------------|      |-------------------*-------------*----------------|
                                                        KC_LGUI,  MO(_MOUSE),   LALT_T(KC_SPC),           LT(_CODE, KC_ENT),  MO(_NUMBERS), TT(_NAVIGATION)
    //                                                |---------*-------------*------------------|      |-------------------*-------------*----------------|
    ),

    // Layer NAVIGATION - Symboles de navigation 0189715617
    [_NAVIGATION] = LAYOUT_split_3x6_3_ex2(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_HOME,      KC_PGUP,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, KC_VOLU, KC_BRIU, XXXXXXX, XXXXXXX, KC_PSCR,                       KC_END,       KC_PGDN,   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______,
        _______, KC_VOLD, KC_BRID, XXXXXXX, XXXXXXX, TAP_LAYER_GAME,                                         TAP_LAYER_BOOT, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                                  _______, _______, _______,                                 KC_ENT, QK_GESC, TT(_NAVIGATION)
    ),

    // Layer BOOT - Configuration, reset et RGB
    [_BOOT] = LAYOUT_split_3x6_3_ex2(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX,      XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        _______, RGB_HUI, KC_SLEP, RGB_SAI, RGB_VAI, XXXXXXX,                       XXXXXXX,      XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, RM_VALU, KC_BRIU, KC_VOLU,
        _______, RGB_HUD, RGB_TOG, RGB_SAD, RGB_VAD, XXXXXXX,                                                XXXXXXX,   XXXXXXX, XXXXXXX, RM_VALD, KC_BRID, KC_VOLD,
                                                  XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, XXXXXXX, TAP_LAYER_RESET
    ),

    // Layer SYMBOLES - Accents et caractères spéciaux français
    [_SYMBOLES] = LAYOUT_split_3x6_3_ex2(
        QK_GESC, UC(A_CIRC),  UC(C_CED), UC(O_E), UC(O_CIRC), UC(YEN),              KC_HOME,      KC_PGUP,   KC_LBRC, KC_RBRC,   KC_UNDS,  XXXXXXX, UC(U_CIRC), KC_HOME,
        _______, UC(A_ACUTE), UC(E_GRAVE), UC(E_ACUTE), UC(E_CIRC), XXXXXXX,        KC_END,       KC_PGDN,   KC_LEFT_PAREN, KC_RIGHT_PAREN,    UC(I_CIRC), UC(I_UML),  UC(U_GRAVE),    KC_BSPC,
        _______, UC(A_E),     XXXXXXX, KC_MINS, KC_UNDS,    KC_UNDS,                                         XXXXXXX,   XXXXXXX,    XXXXXXX,    KC_DOT,     KC_INTERNATIONAL_4,    KC_END,
                                       _______,  MO(_MOUSE), LALT_T(KC_SPC),                                 XXXXXXX, _______, RALT_T(KC_ENT)
    ),

    // Layer CODE - Symboles de programmation
    [_CODE] = LAYOUT_split_3x6_3_ex2(
        _______, KC_LBRC, KC_LT, KC_GT, KC_DLR,  KC_PERC,                           KC_HOME,      KC_PGUP,   KC_AT,   KC_AMPR, KC_ASTR, KC_QUOT, KC_GRV,  _______,
        _______, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_EQL,                        KC_END,       KC_PGDN,   KC_BSLS, KC_PLUS, KC_MINS, KC_SLSH, KC_DQUO, _______,
        _______, KC_TILD, KC_LBRC, KC_RBRC, KC_UNDS, KC_HASH,                                                KC_PIPE, KC_EXLM, KC_SCLN, KC_COLN, KC_QUES, _______,
                                           _______, _______, LALT_T(KC_SPC),                                 XXXXXXX, _______, RALT_T(KC_ENT)
    ),

    // Layer MOUSE - Contrôle de souris
    [_MOUSE] = LAYOUT_split_3x6_3_ex2(
        QK_GESC, C(KC_X),  KC_MS_WH_UP, KC_MS_WH_DOWN, C(KC_C),  C(KC_V),           KC_HOME,      KC_PGUP,  XXXXXXX,    KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, XXXXXXX, _______,
        KC_LSFT, KC_MS_LEFT, KC_MS_UP,  KC_MS_DOWN, KC_MS_RIGHT, C(KC_Z),           KC_END,       KC_PGDN,  XXXXXXX,    KC_LEFT,      KC_DOWN,      KC_UP,        KC_RIGHT, _______,
        KC_LCTL, KC_BSPC,  S(KC_TAB),   KC_TAB,     KC_DEL,  XXXXXXX,                                       XXXXXXX,    S(KC_LEFT),   S(KC_DOWN),   S(KC_UP),     S(KC_RIGHT), _______,
                                           XXXXXXX, XXXXXXX, XXXXXXX,                                       KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2
    ),

    // Layer pour le Game
    [_GAME] = LAYOUT_split_3x6_3_ex2(
        KC_TAB,  KC_A,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_HOME,      KC_PGUP,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    QK_GESC,
        KC_LSFT, KC_Q,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_END,       KC_PGDN,   KC_H,    KC_J,    KC_K,    KC_L,    KC_VOLU, KC_BSPC,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_VOLD, KC_END,
                                                 KC_I, MO(_NUMBERS), KC_SPC,                                 KC_ENT, KC_LGUI, TAP_LAYER_RESET
    ),

    // Layer NUM - Chiffres et contrôles de navigation
    [_NUMBERS] = LAYOUT_split_3x6_3_ex2(
        KC_1,    KC_2,    KC_3,    KC_0,   KC_PLUS, KC_MINS,                        KC_HOME,      KC_PGUP,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
        KC_4,    KC_5,    KC_6,    KC_0,   KC_ASTR,  KC_SLSH,                       KC_END,       KC_PGDN,   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______,
        KC_7,    KC_8,    KC_9,    KC_DOT, KC_EQL, KC_PERC,                                                  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                                           KC_LGUI, XXXXXXX, LALT_T(KC_SPC),                                 KC_ENT, XXXXXXX, XXXXXXX
    ),
};
