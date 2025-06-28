#include QMK_KEYBOARD_H
 
const key_override_t question_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_MINS, FR_QUES);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_DOT, FR_SCLN);
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
    &zero_key_override,
};

