
// Below layout is based upon /u/That-Canadian's planck layout

#include "eco.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 2
#define _RAISE 3

#define _FUNCTION 15
#define _ADJUST 16

enum eco_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define MD_PLAY KC_MEDIA_PLAY_PAUSE
#define MD_PREV KC_MEDIA_PREV_TRACK
#define MD_NEXT KC_MEDIA_NEXT_TRACK
#define VOL_DWN KC_AUDIO_VOL_DOWN
#define VOL_UP  KC_AUDIO_VOL_UP
#define VOL_MUT KC_AUDIO_MUTE
#define TMP_ESC CTL_T(KC_ESC)
#define COLON S(KC_SCLN)
#define PLUS S(KC_EQL)
#define LBRKT S(KC_LBRC)
#define RBRKT S(KC_RBRC)
#define PIPE S(KC_BSLS)
#define S_INS S(KC_INS)

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_LPRN, KC_RPRN, KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS},
  {TMP_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_LBRC, KC_RBRC, KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LCBR, KC_RCBR, KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT},
  {_______, _______, KC_LGUI, KC_LALT, KC_F23, LOWER,  KC_SPC,  KC_SPC,  RAISE, XXXXXXX, XXXXXXX, S_INS,   KC_DEL,  KC_BSPC}

},
[_LOWER] = {
  {_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______},
  {KC_GRV,  KC_F24,  MD_PREV, MD_NEXT, MD_PLAY, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  _______, _______},
  {_______, _______, VOL_DWN, VOL_UP,  VOL_MUT, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},
[_RAISE] = {
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {KC_GRV,  KC_LBRC, KC_RBRC, COLON,   KC_BSLS, PIPE,    _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, LBRKT,   RBRKT,   KC_LPRN, KC_RPRN, KC_EQL,  _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},
[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_F7,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, RESET,   _______, _______, _______, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Function
 * ,-------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
[_FUNCTION] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______},
  {KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_SONG(tone_startup);
}

void shutdown_user()
{
    PLAY_SONG(tone_goodbye);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
