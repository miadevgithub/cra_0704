#ifndef _DEBUG

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

    Stage* current = STAGE[STAGE_CARTYPE];
    StageResult_e ret = RET_SUCCESS;
    while (1) {
        current->entry();
        ret = current->execute();
        switch (ret) {
        case RET_SUCCESS:
            current->exit();
            break;

        case RET_ERROR:
            break;

        case RET_INIT:
            current = STAGE[STAGE_CARTYPE];
            break;

        case RET_EXIT:
            break;
        }
    }
}

#endif