/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
// Settings
#define PLOOPY_DRAGSCROLL_MULTIPLIER 0.1
#define PLOOPY_DRAGSCROLL_INVERT
#define LAYER_STATE_8BIT // Limit layers to 8 to save space

// Disable unused features
#undef LOCKING_SUPPORT_ENABLE 
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
