#ifndef NEXEFFECT_H
#define NEXEFFECT_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Load effect:
 * 0-load
 * 1-top fly into
 * 2-bottom fly into
 * 3-left fly into
 * 4-right fly into
 * 5-top left fly into
 * 6-top right fly into
 * 7-bottom left fly into
 * 8-bottom right fly into
 * 9-fade into the gradual change
 * 10-middle zoom in
 * 
 */
typedef enum _Nex_effect{
    NEX_EFFECT_LOAD                         = 0,
    NEX_EFFECT_TOP_FLY_INTO                 = 1,
    NEX_EFFECT_BOTTOM_FLY_INTO              = 2,
    NEX_EFFECT_LEFT_FLY_INTO                = 3,
    NEX_EFFECT_RIGHT_FLY_INTO               = 4,
    NEX_EFFECT_TOP_LEFT_FLY_INTO            = 5,
    NEX_EFFECT_TOP_RIGHT_FLY_INTO           = 6,
    NEX_EFFECT_BOTTOM_LEFT_FLY_INTO         = 7,
    NEX_EFFECT_BOTTOM_RIGHT_FLY_INTO        = 8,
    NEX_EFFECT_FADE_INTO_THE_GRADUAL_CHANGE = 9,
    NEX_EFFECT_MIDDLE_ZOOM_IN               = 10,
    NEX_EFFECT_NONE                         = -1
} Nex_effect;

#ifdef __cplusplus
}
#endif

#endif /*NEXEFFECT_H*/