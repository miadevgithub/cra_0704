#pragma once
#include "Types.hpp"
#include "Manufacturer.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define CLEAR_SCREEN "\033[H\033[2J"

void delay(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}

enum StageType_e
{
    STAGE_CARTYPE,
    STAGE_ENGINE,
    STAGE_BRAKE,
    STAGE_STEERING,
    STAGE_RUN,
    STAGE_MAX,
};

enum StageResult_e {
    RET_SUCCESS,
    RET_ERROR,
    RET_INIT,
    RET_EXIT,
};

class Stage {
public:
    virtual void entry() = 0;
    virtual void exit() = 0;
    virtual StageResult_e validate() = 0;

    virtual StageResult_e execute()
    {
        printf("INPUT > ");
        fgets(_buf, sizeof(_buf), stdin);

        // 엔터 개행문자 제거
        char* context = nullptr;
        strtok_s(_buf, "\r", &context);
        strtok_s(_buf, "\n", &context);

        char* checkNumber;
        _answer = strtol(_buf, &checkNumber, 10);
        // 입력받은 문자가 숫자가 아니라면
        if (*checkNumber != '\0')
        {
            printf("ERROR :: 숫자만 입력 가능\n");
            delay(800);
            return RET_ERROR;
        }

        if (!strcmp(_buf, "exit"))
        {
            printf("바이바이\n");
            return RET_EXIT;
        }

        StageResult_e ret = validate();
        if (ret != RET_SUCCESS) {
            return ret;
        }

        return RET_SUCCESS;
    }

protected:
    char _buf[100];
    int _answer;
};

class StageCarType : public Stage {
public:
    void entry() override {
        printf(CLEAR_SCREEN);

        printf("        ______________\n");
        printf("       /|            | \n");
        printf("  ____/_|_____________|____\n");
        printf(" |                      O  |\n");
        printf(" '-(@)----------------(@)--'\n");
        printf("===============================\n");
        printf("어떤 차량 타입을 선택할까요?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }

    void exit() override {
        if (_answer == 1)
            printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
        if (_answer == 2)
            printf("차량 타입으로 SUV을 선택하셨습니다.\n");
        if (_answer == 3)
            printf("차량 타입으로 Truck을 선택하셨습니다.\n");

        delay(800);
    }

    StageResult_e validate() override {
        if (_answer < 1 || _answer > 3)
        {
            printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
            delay(800);
            return RET_ERROR;
        }
        return RET_SUCCESS;
    }
};

class StageBrake : public Stage {
public:
    void entry() override {
        printf(CLEAR_SCREEN);
        printf("어떤 제동장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }

    void exit() override {
        if (_answer == 1)
            printf("MANDO 제동장치를 선택하셨습니다.\n");
        if (_answer == 2)
            printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
        if (_answer == 3)
            printf("BOSCH 제동장치를 선택하셨습니다.\n");

        delay(800);
    }

    StageResult_e validate() override {
        if (_answer == 0) {
            return RET_INIT;
        }

        if (_answer < 0 || _answer < 3)
        {
            printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
            delay(800);
            return RET_ERROR;
        }
        return RET_SUCCESS;
    }
};

class StageEngine : public Stage {
public:
    void entry() override {
        printf(CLEAR_SCREEN);
        printf("어떤 엔진을 탑재할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. 고장난 엔진\n");
    }

    void exit() override {
        if (_answer == 1)
            printf("GM 엔진을 선택하셨습니다.\n");
        if (_answer == 2)
            printf("TOYOTA 엔진을 선택하셨습니다.\n");
        if (_answer == 3)
            printf("WIA 엔진을 선택하셨습니다.\n");

        delay(800);
    }

    StageResult_e validate() override {
        if (_answer == 0) {
            return RET_INIT;
        }

        if (_answer < 0 || _answer > 4)
        {
            printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
            delay(800);
            return RET_ERROR;
        }
        return RET_SUCCESS;
    }
};

class StageSteering : public Stage {
public:
    void entry() override {
        printf(CLEAR_SCREEN);
        printf("어떤 조향장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }

    void exit() override {
        if (_answer == 1)
            printf("BOSCH 조향장치를 선택하셨습니다.\n");
        if (_answer == 2)
            printf("MOBIS 조향장치를 선택하셨습니다.\n");

        delay(800);
    }

    StageResult_e validate() override {
        if (_answer == 0) {
            return RET_INIT;
        }

        if (_answer < 0 || _answer > 2)
        {
            printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
            delay(800);
            return RET_ERROR;
        }

        return RET_SUCCESS;
    }
};

class StageRun : public Stage {
public:
    void entry() override {
        printf(CLEAR_SCREEN);
        printf("멋진 차량이 완성되었습니다.\n");
        printf("어떤 동작을 할까요?\n");
        printf("0. 처음 화면으로 돌아가기\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }

    void exit() override {
        if (_answer == 1)
        {
            //runProducedCar();
            delay(2000);
        }
        else if (_answer == 2)
        {
            printf("Test...\n");
            delay(1500);
            //testProducedCar();
            delay(2000);
        }
    }

    StageResult_e validate() override {
        if (_answer < 0 || _answer > 2)
        {
            printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
            delay(800);
            return RET_ERROR;
        }
        return RET_SUCCESS;
    }
};
/*
int isValidCheck()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == MFR_CONTINENTAL)
    {
        return false;
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == MFR_TOYOTA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == MFR_WIA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MFR_MANDO)
    {
        return false;
    }
    else if (stack[brakeSystem_Q] == MFR_BOSCH && stack[SteeringSystem_Q] != MFR_BOSCH)
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("자동차가 동작되지 않습니다\n");
    }
    else
    {
        if (stack[Engine_Q] == 4)
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            if (stack[CarType_Q] == 1)
                printf("Car Type : Sedan\n");
            if (stack[CarType_Q] == 2)
                printf("Car Type : SUV\n");
            if (stack[CarType_Q] == 3)
                printf("Car Type : Truck\n");
            if (stack[Engine_Q] == 1)
                printf("Engine : GM\n");
            if (stack[Engine_Q] == 2)
                printf("Engine : TOYOTA\n");
            if (stack[Engine_Q] == 3)
                printf("Engine : WIA\n");
            if (stack[brakeSystem_Q] == 1)
                printf("Brake System : Mando");
            if (stack[brakeSystem_Q] == 2)
                printf("Brake System : Continental\n");
            if (stack[brakeSystem_Q] == 3)
                printf("Brake System : Bosch\n");
            if (stack[SteeringSystem_Q] == 1)
                printf("SteeringSystem : Bosch\n");
            if (stack[SteeringSystem_Q] == 2)
                printf("SteeringSystem : Mobis\n");

            printf("자동차가 동작됩니다.\n");
        }
    }
}

void testProducedCar()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == MFR_CONTINENTAL)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == MFR_TOYOTA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == MFR_WIA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MFR_MANDO)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
    }
    else if (stack[brakeSystem_Q] == MFR_BOSCH && stack[SteeringSystem_Q] != MFR_BOSCH)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
    }
    else
    {
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
    }
}
*/