/************************/
/*  Source              */
/************************/
/****** Core Toolkit ****************************************************************/
#include <sa2b/core.h>          /* core                                             */
#include <sa2b/init.h>          /* init                                             */
#include <sa2b/writeop.h>       /* write operation                                  */

/****** Game ************************************************************************/
#include <sa2b/sonic/task.h>    /* task                                             */
#include <sa2b/sonic/set.h>     /* set items                                        */
#include <sa2b/sonic/minimal.h> /* minimal                                          */

/************************/
/*  Source              */
/************************/
/****** Static **********************************************************************/
static void
ObjectPickUpMinimalSpawn(task* tp)
{
    const taskwk*  twp = tp->twp;
    OBJ_CONDITION* ocp = tp->ocp;

    if (!ocp || ocp->ssCondition & 0x20)
        return;

    ocp->ssCondition |= 0x20;

    const int kind = (int)twp->scl.x;

    if (!kind)
        return;

    Minimal_JumpOut((kind - 1) % 3, twp->pos.x, twp->pos.y + 5.0f, twp->pos.z);
}

__declspec(naked)
static void
___ObjectPickUpMinimalSpawn(void)
{
    __asm
    {
        push esi
        call ObjectPickUpMinimalSpawn
        pop esi
        retn
    }
}

/************************/
/*  DLL Exports         */
/************************/
/****** Mod Init ********************************************************************/
EXPORT_DLL
void __cdecl
Init(const char* path, const HelperFunctions* pHelpFuncs)
{
    WriteNOP( 0x006BC741, 0x006BC756);
    WriteCall(0x006BC741, ___ObjectPickUpMinimalSpawn);
}

/****** Mod Info ********************************************************************/
EXPORT_DLL
ModInfo SA2ModInfo = { ML_VERSION };
