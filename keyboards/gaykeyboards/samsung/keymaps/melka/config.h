#pragma once

#define AUDIO_PIN B6
#define NO_MUSIC_MODE
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_MIN AUDIO_CLICKY_FREQ_DEFAULT
#define AUDIO_CLICKY_FREQ_MAX AUDIO_CLICKY_FREQ_DEFAULT
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.0f

#if defined __has_include
#    if __has_include("passwd.h")
#        include "passwd.h"
#    endif  // if file exists
#endif      // __GNUC__
