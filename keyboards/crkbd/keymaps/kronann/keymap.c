#include QMK_KEYBOARD_H
#include "french-unicode.h"
//#include "quantum/rgblight/rgblight.h"

// Define keymap layers
enum layers {
    _DEFAULT,
    _NUMBERS,
    _NAVIGATION,
    _BOOT,
    _SYMBOLES,
    _CODE,
    _JAP
};


#ifdef RGB_MATRIX_ENABLE

bool rgb_matrix_indicators_user(void) {
    switch(get_highest_layer(layer_state)) {
        case _DEFAULT:
            // orange pour la couche par défaut
            rgb_matrix_set_color_all(0, 0, 0);
            // rgb_matrix_set_color_all(153, 245, 255);
            break;
        case _NUMBERS:
            // Vert pour la couche numérique
            rgb_matrix_set_color_all(0, 204, 0);
            break;
        case _NAVIGATION:
            // Bleu pour la couche de navigation
            rgb_matrix_set_color_all(102, 178, 255);
            break;
        case _SYMBOLES:
            // Magenta pour la couche de symboles
            rgb_matrix_set_color_all(128, 0, 32);
            break;
        case _CODE:
            // Jaune pour la couche de code
            rgb_matrix_set_color_all(255, 255, 0);
            break;
        case _BOOT:
            rgb_matrix_set_color_all(255, 0, 0);
            break;
        case _JAP:
            rgb_matrix_set_color_all(0, 100, 255);
            break;
        default:
            // Blanc pour toute autre couche
            rgb_matrix_set_color_all(255, 255, 255);
            break;
    }
    return false;
}

#endif

// Définition du keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    // Layer DEFAULT - Configuration Ergo-L de base
    [_DEFAULT] = LAYOUT_split_3x6_3_ex2(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,    FR_Q,    FR_C,    FR_O,    FR_P,    FR_W,    KC_HOME, KC_PGUP,   FR_J,    FR_M,    FR_D, OSL(_SYMBOLES), FR_Y, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,   FR_A,    FR_S,    FR_E,    FR_N,    FR_F,    KC_END,  KC_PGDN,   FR_L,    FR_R,    FR_T,    FR_I,    FR_U,   KC_ENT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,   FR_Z,    FR_X,    FR_MINS, FR_V,    FR_B,                        FR_DOT,  FR_H,    FR_G,    FR_COMM, FR_K,   QK_GESC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LGUI, TG(_NAVIGATION), LALT_T(KC_SPC),     MO(_CODE), MO(_NAVIGATION), MO(_NUMBERS)
                                //`--------------------------'  `--------------------------'
    ),

    // Layer NUM - Chiffres et contrôles de navigation
    [_NUMBERS] = LAYOUT_split_3x6_3_ex2(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,    FR_1,    FR_2,    FR_3,    FR_4,    FR_5,    KC_HOME, KC_PGUP,   FR_6,    FR_7,    FR_8,    FR_9,    FR_0,   KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_END,  KC_PGDN,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_ENT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END, QK_GESC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LGUI, _______, LALT_T(KC_SPC),            XXXXXXX, MO(_NAVIGATION), KC_RALT
                                //`--------------------------'  `--------------------------'
    ),

    // Layer NAV - Symboles de navigation
    [_NAVIGATION] = LAYOUT_split_3x6_3_ex2(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_HOME, KC_PGUP,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_PRINT_SCREEN, KC_END, KC_PGDN, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_ENT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END, QK_GESC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    MO(_BOOT), TG(_NAVIGATION), LALT_T(KC_SPC),   XXXXXXX, _______, KC_RALT
                                //`--------------------------'  `--------------------------
    ),

    // Layer BOOT - Configuration, reset et RGB
    [_BOOT] = LAYOUT_split_3x6_3_ex2(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_TOG, RGB_HUI, KC_SYSTEM_SLEEP, RGB_VAI, RGB_SAI, XXXXXXX, KC_END,  KC_PGDN,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRIGHTNESS_UP, KC_AUDIO_VOL_UP,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_MOD, RGB_HUD, XXXXXXX, RGB_VAD, RGB_SAD, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRIGHTNESS_DOWN, KC_AUDIO_VOL_DOWN,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LGUI, _______, LALT_T(KC_SPC),            XXXXXXX, _______, KC_RALT
                                //`--------------------------'  `--------------------------'
    ),

    // Layer SYM - Accents et caractères spéciaux français
    [_SYMBOLES] = LAYOUT_split_3x6_3_ex2(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,  UC(A_CIRC), FR_CCED, UC(O_E), UC(O_CIRC), XXXXXXX, KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX, FR_UNDS, XXXXXXX, UC(U_CIRC), KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, FR_AGRV, FR_EACU, FR_EGRV, UC(E_CIRC), XXXXXXX, KC_END, KC_PGDN, FR_LPRN, FR_RPRN, UC(I_CIRC), UC(I_UML), FR_UGRV, KC_ENT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, UC(A_E), XXXXXXX, FR_MINS, FR_UNDS, FR_UNDS,                      XXXXXXX, XXXXXXX, XXXXXXX, FR_DOT,  XXXXXXX, QK_GESC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LGUI, _______, LALT_T(KC_SPC),            XXXXXXX, _______, KC_RALT
                                //`--------------------------'  `--------------------------'
    ),

    // Layer CODE - Symboles de programmation additionnels
    [_CODE] = LAYOUT_split_3x6_3_ex2(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,  FR_CIRC, FR_LABK, FR_RABK, FR_DLR,  FR_PERC, KC_HOME, KC_PGUP,   FR_AT,   FR_AMPR, FR_ASTR, FR_QUOT, FR_GRV,  KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, FR_LCBR, FR_LPRN, FR_RPRN, FR_RCBR, FR_EQL,  KC_END,  KC_PGDN,   FR_BSLS, FR_PLUS, FR_MINS, FR_SLSH, FR_DQUO, KC_ENT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, FR_TILD, FR_LBRC, FR_RBRC, FR_UNDS, FR_HASH,                     FR_PIPE, FR_EXLM, FR_SCLN, FR_COLN, FR_QUES, QK_GESC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LGUI, _______, LALT_T(KC_SPC),            XXXXXXX, _______, KC_RALT
                                //`--------------------------'  `--------------------------'
    ),

    // Layer JAP - Configuration japonaise
    [_JAP] = LAYOUT_split_3x6_3_ex2(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_HOME, KC_PGUP,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_END,  KC_PGDN,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, QK_GESC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LGUI, MO(_NAVIGATION), LALT_T(KC_SPC),    MO(_CODE), MO(_NUMBERS), DF(_DEFAULT)
                                //`--------------------------'  `--------------------------'
    )
};

// Initialisation du clavier
void keyboard_post_init_user(void) {
}

const key_override_t question_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_MINS, FR_EXLM);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, FR_SCLN);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_F12, KC_BSPC);
const key_override_t mute_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE);

// _NUMBERS override
const key_override_t one_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_1, FR_EURO);
const key_override_t two_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_2, UC(FR_LDAQ));
const key_override_t three_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_3, UC(FR_RDAQ));
const key_override_t four_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_4, FR_DLR);
const key_override_t five_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_5, FR_PERC);
const key_override_t six_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_6, FR_CIRC);
const key_override_t seven_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_7, FR_AMPR);
const key_override_t eight_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_8, FR_ASTR);
const key_override_t nine_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_9, FR_HASH);
const key_override_t zero_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_0, FR_AT);


// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &question_key_override,
    &dot_key_override,
    &comma_key_override,
    &delete_key_override,
    &one_key_override,
    &backspace_key_override,
    &mute_key_override,
    &two_key_override,
    &three_key_override,
    &four_key_override,
    &five_key_override,
    &six_key_override,
    &seven_key_override,
    &eight_key_override,
    &nine_key_override,
    &zero_key_override
};

/*
 COMBOS
*/
enum combo_events {
    RALT_LGUI_S_SLEEP,  // SLEEP
};

const uint16_t PROGMEM sleep_combo[] = {KC_LCTL, KC_LSFT, KC_S, QK_GESC, COMBO_END};

combo_t key_combos[] = {
    [RALT_LGUI_S_SLEEP] = COMBO(sleep_combo, KC_SYSTEM_SLEEP),
};


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
