#include "keymap_french.h"
//#include "keymap_japanese.h"

enum unicode_names {
    A_ACUTE  = 0x00E0,   // à
    A_CIRC  = 0x00E2,   // â
    E_ACUTE = 0x00E9,   // é
    E_GRAVE = 0x00E8,   // è
    E_CIRC  = 0x00EA,   // ê
    I_CIRC  = 0x00EE,   // î
    O_CIRC  = 0x00F4,   // ô
    U_GRAVE = 0x00F9,   // ù
    U_CIRC  = 0x00FB,   // û
    C_CED  = 0x00E7,   // ç
    I_UML   = 0x00EF,   // ï
    A_E     = 0x00E6,   // æ
    O_E     = 0x0153,   // œ
    FR_LDAQ = 0x00AB,   // «
    FR_RDAQ = 0x00BB,   // »
    FR_EXCL = 0x38,
    YEN     = 0x00A5,
    EURO    = 0x20AC
};


// Define keymap layers
enum layers {
    _DEFAULT,
    _NAVIGATION,
    _BOOT,
    _SYMBOLES,
    _CODE,
    _MOUSE,
    _GAME,
    _NUMBERS
};

/*
 TAP LAYER
*/
enum custom_keycodes {
    TAP_LAYER_GAME = SAFE_RANGE,
    TAP_LAYER_BOOT,
    TAP_LAYER_RESET,
    OSL_SYM_EXCL
};
typedef struct {
    uint8_t count;
    uint16_t last_time;
} tap_counter_t;
