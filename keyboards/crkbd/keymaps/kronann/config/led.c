#include QMK_KEYBOARD_H
#include "french-unicode.h"

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
        case _GAME:
            rgb_matrix_set_color_all(255, 217, 0);
            break;
        default:
            // Blanc pour toute autre couche
            rgb_matrix_set_color_all(255, 255, 255);
            break;
    }
    return false;
}

#endif