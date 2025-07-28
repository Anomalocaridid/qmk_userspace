# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

# Enable desired features
LTO_ENABLE = yes       # Enable Link Time Optimization
ENCODER_MAP_ENABLE = yes   # Enable encoder map TODO: remove after this is made default behavior

# Disable unused features
EXTRAKEY_ENABLE = no   # Disable system control keys
MUSIC_ENABLE = no      # Disable audio (unsupported)
MAGIC_ENABLE = no      # Disable magic keycodes
