#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <vector>
#include "Stage.hpp"

int main()
{
    Stage* STAGE[STAGE_MAX] = { nullptr, };
    STAGE[STAGE_CARTYPE] = new StageCarType;
    STAGE[STAGE_ENGINE] = new StageEngine;
    STAGE[STAGE_BRAKE] = new StageBrake;
    STAGE[STAGE_STEERING] = new StageSteering;
    STAGE[STAGE_RUN] = new StageRun;

    int index = STAGE_CARTYPE;
    ManufacturerInfo_t info{ SEDAN, MFR_MAX, MFR_MAX, MFR_MAX };
    while (1) {
        STAGE[index]->entry(info);
        StageResult_e ret = STAGE[index]->execute();

        if (ret == RET_EXIT) {
            break;
        }

        if (ret == RET_INIT) {
            index = STAGE_CARTYPE;
            continue;
        }

        if (ret == RET_SUCCESS) {
            STAGE[index]->exit();
            index = (index == STAGE_RUN) ? index : index + 1;
        }
    }
}

#endif