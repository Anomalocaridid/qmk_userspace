# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

# Enable desired features
ENCODER_MAP_ENABLE = yes # TODO: remove when this becomes default
LTO_ENABLE = yes         # Enable Link Time Optimization
MOUSEKEY_ENABLE = yes    # Enable mouse keys

# Disable unused features
COMMAND_ENABLE = no      # Disable debugging commands
UNICODE_ENABLE = no      # Disable Unicode support
SPACE_CADET_ENABLE = no  # Disable Space Cadet shift
GRAVE_ESC_ENABLE = no    # Disable Grave Escape
MAGIC_ENABLE = no        # Disable magic keycodes
MUSIC_ENABLE = no        # Disable music mode

