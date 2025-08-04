// Common settings
#define ENABLE_COMPILE_KEYCODE // Add QK_MAKE key

// Disable unused features for all my keymaps
#define LAYER_STATE_8BIT      // Limit layers to 8
#define NO_MUSIC_MODE         // Disable music mode
#undef LOCKING_RESYNC_ENABLE  // Disable lock switch support
#undef LOCKING_SUPPORT_ENABLE // Disable lock switch support

#ifdef RGB_MATRIX_ENABLE
// Disable undesired animations
#    undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#    undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    undef ENABLE_RGB_MATRIX_BAND_SAT
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    undef ENABLE_RGB_MATRIX_HUE_BREATHING
#    undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#    undef ENABLE_RGB_MATRIX_HUE_WAVE
#endif
