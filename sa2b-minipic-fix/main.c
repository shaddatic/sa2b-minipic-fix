#include <sa2b/core.h>
#include <sa2b/init.h>
#include <sa2b/writeop.h>

/** Source **/
#include <sa2b/sonic/task.h>
#include <sa2b/sonic/set.h>
#include <sa2b/sonic/minimal.h>

static void
ObjectPickUpMinimalSpawn(TASK* tp)
{
    TASKWK*        const twp = tp->twp;
    OBJ_CONDITION* const ocp = tp->ocp;

    if (!ocp || ocp->ssCondition & 0x20)
        return;

    ocp->ssCondition |= 0x20;

    const int kind = (int)twp->scl.x;

    if (!kind)
        return;

    Minimal_JumpOut(kind - 1, twp->pos.x, twp->pos.y + 5.0f, twp->pos.z);
}

__declspec(naked)
static void
__ObjectPickUpMinimalSpawn(void)
{
    __asm
    {
        push esi
        call ObjectPickUpMinimalSpawn
        pop esi
        retn
    }
}

EXPORT_DLL
void __cdecl
Init(const char* path, const HelperFunctions* pHelpFuncs)
{
    WriteNOP( 0x006BC741, 0x006BC756);
    WriteCall(0x006BC741, __ObjectPickUpMinimalSpawn);
}

EXPORT_DLL
ModInfo SA2ModInfo = { ML_VERSION };
