#include QMK_KEYBOARD_H
#include "french-unicode.h"
#include "print.h"   

// void debug_layer_state(void) {
//     uprintf("\n=== LAYER STATE DEBUG ===\n");
//     uprintf("Default layer: %u\n", get_highest_layer(default_layer_state));
//     uprintf("Current highest layer: %u\n", get_highest_layer(layer_state));
    
//     // Afficher tous les layers actifs
//     uprintf("Active layers: ");
//     for (uint8_t i = 0; i < 8; i++) {
//         if (IS_LAYER_ON(i)) {
//             switch(i) {
//                 case _DEFAULT:    uprintf("DEFAULT "); break;
//                 case _NUMBERS:    uprintf("NUMBERS "); break;
//                 case _NAVIGATION: uprintf("NAVIGATION "); break;
//                 case _BOOT:       uprintf("BOOT "); break;
//                 case _SYMBOLES:   uprintf("SYMBOLES "); break;
//                 case _CODE:       uprintf("CODE "); break;
//                 case _MOUSE:      uprintf("MOUSE "); break;
//                 case _GAME:       uprintf("GAME "); break;
//             }
//         }
//     }
//     uprintf("\n");
    
//     // Afficher l'état binaire des layers
//     uprintf("Layer state binary: 0b");
//     for (int8_t i = 7; i >= 0; i--) {
//         uprintf("%d", IS_LAYER_ON(i) ? 1 : 0);
//     }
//     uprintf(" (0x%02X)\n", (uint8_t)layer_state);
//     uprintf("======================\n\n");
// }

static tap_counter_t tap_counters[3] = {0};  // Un pour chaque keycode personnalisé

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    int idx = keycode - TAP_LAYER_GAME;  // Index dans le tableau
    
 if (record->event.pressed) {
        uprintf("\n[KEY PRESS] Keycode: %u", keycode);
        
        switch(keycode) {
            case MO(_NUMBERS):     uprintf(" (MO_NUMBERS)"); break;
            case MO(_CODE):        uprintf(" (MO_CODE)"); break;
            case MO(_MOUSE):       uprintf(" (MO_MOUSE)"); break;
            case LT(_CODE, KC_ENT): uprintf(" (LT_CODE_ENT)"); break;
            case TT(_NAVIGATION):  uprintf(" (TT_NAVIGATION)"); break;
            case OSL(_SYMBOLES):   uprintf(" (OSL_SYMBOLES)"); break;
        }
        uprintf("\n");
        
        // debug_layer_state();
    }

    if (keycode >= TAP_LAYER_GAME && keycode <= TAP_LAYER_RESET && record->event.pressed) {
        tap_counter_t *counter = &tap_counters[idx];
        
        if (timer_elapsed(counter->last_time) < 500) {
            counter->count++;
        } else {
            counter->count = 1;
        }
        
        counter->last_time = timer_read();
        
        if (counter->count >= 3) {
            switch (keycode) {
                case TAP_LAYER_GAME:
                    layer_on(_GAME);
                    break; 
                case TAP_LAYER_BOOT:                
                    layer_clear();
                    layer_on(_BOOT);
                    break;
                case TAP_LAYER_RESET:
                    layer_clear();
                    layer_on(_DEFAULT);
                    break;
            }
            counter->count = 0;
        }
        return false;
    } else {
        if (keycode == OSL(_SYMBOLES)) {
            if (record->event.pressed) {
                // shift mod
                if (get_mods() & MOD_MASK_SHIFT) {
                    // Envoyer ! au lieu d'activer le layer
                    send_unicode_string("!"); 
                    return false;
                } 
            }
        }
    }
    return true;
}
