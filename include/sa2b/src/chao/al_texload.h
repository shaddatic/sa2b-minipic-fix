/*
*   Sonic Adventure Mod Tools (SA2B) - '/src/chao/al_texload.h'
*
*   Contains enums, structs, data, and functions related to Chao World's texture loading engine.
*
*   Contributors:
*   -   SEGA - Sonic Team,
*   -   Shaddatic
*
*   Only for use with Sonic Adventure 2 for PC.
*/
#ifndef _SA2B_CHAO_TEXLOAD_H_
#define _SA2B_CHAO_TEXLOAD_H_

/************************/
/*  Includes            */
/************************/
#include <sa2b/ninja/njcommon.h>

/************************/
/*  Enums               */
/************************/
enum 
{ 
    TEX_LEV_COMMON,
    TEX_LEV_STAGE,
    TEX_LEV_LAND,
    TEX_LEV_OTHER,
    NB_TEX_LEV,
};

/************************/
/*  Structures          */
/************************/
typedef struct 
{
    char* filename;
    NJS_TEXLIST* pTexlist;
}
LOADED_TEX_INFO;

/************************/
/*  Data                */
/************************/
#define TexEntry        DataAry(LOADED_TEX_INFO, 0x01DCD600, [4][256])

/************************/
/*  Functions           */
/************************/
EXTERN_START
/** Load textures at a given level **/
int32_t    AL_LoadTex(const char* filename, NJS_TEXLIST* pTexlist, uint16_t lev);
/** Release all textures at the given level **/
int32_t    AL_ReleaseTex(uint16_t lev);

EXTERN_END

/************************/
/*  Function Ptrs       */
/************************/
#ifdef SAMT_INCLUDE_FUNC_PTRS
/** User-Function ptrs **/
EXTERN const void* const AL_LoadTex_p;
EXTERN const void* const AL_ReleaseTex_p;

#endif /* SAMT_INCLUDE_FUNC_PTRS */

#endif /* _SA2B_CHAO_TEXLOAD_H_ */
