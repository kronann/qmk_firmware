SRC += config/custom.c
SRC += config/led.c

INTROSPECTION_KEYMAP_C = override_keymap.c

RGB_MATRIX_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes 
EXTRAKEY_ENABLE = yes  

# Désactiver les fonctionnalités inutilisées
UNICODE_ENABLE = yes         
UNICODE_COMMON = yes
UNICODEMAP_ENABLE = no       
CONSOLE_ENABLE = no
ENCODER_ENABLE = no
COMBO_ENABLE = no

RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
OLED_ENABLE = no
LTO_ENABLE = no

