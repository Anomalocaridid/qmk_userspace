# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

# Enable desired features
DYNAMIC_MACRO_ENABLE = yes # Enable Dynamic Macros
LTO_ENABLE = yes           # Enable Link Time Optimization
RGB_MATRIX_ENABLE = yes    # Enable RGB Matrix
SWAP_HANDS_ENABLE = yes    # Enable Swap Hands
CAPS_WORD_ENABLE = yes     # Enable Caps Word

# Disable unused features
COMMAND_ENABLE = no        # Disable debugging commands
EXTRAKEY_ENABLE = no       # Disable system and audio control keys
MUSIC_ENABLE = no          # Disable audio (unsupported)
UNICODE_ENABLE = no        # Disable Unicode support
MAGIC_ENABLE = no          # Disable magic keycodes
