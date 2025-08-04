SRC += anomalocaridid.c

# Enable desired features
LTO_ENABLE = yes         # Enable Link Time Optimization

# Disable unused features
COMMAND_ENABLE = no        # Disable debugging commands
MUSIC_ENABLE = no          # Disable audio (unsupported)
UNICODE_ENABLE = no        # Disable Unicode support
MAGIC_ENABLE = no          # Disable magic keycodes
