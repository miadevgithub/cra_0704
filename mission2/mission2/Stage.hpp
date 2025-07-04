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

        // ���� ���๮�� ����
        char* context = nullptr;
        strtok_s(_buf, "\r", &context);
        strtok_s(_buf, "\n", &context);

        char* checkNumber;
        _answer = strtol(_buf, &checkNumber, 10);
        // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
        if (*checkNumber != '\0')
        {
            printf("ERROR :: ���ڸ� �Է� ����\n");
            delay(800);
            return RET_ERROR;
        }

        if (!strcmp(_buf, "exit"))
        {
            printf("���̹���\n");
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
        printf("� ���� Ÿ���� �����ұ��?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }

    void exit() override {
        if (_answer == 1)
            printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
        if (_answer == 2)
            printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
        if (_answer == 3)
            printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");

        delay(800);
    }

    StageResult_e validate() override {
        if (_answer < 1 || _answer > 3)
        {
            printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
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
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }

    void exit() override {
        if (_answer == 1)
            printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
        if (_answer == 2)
            printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
        if (_answer == 3)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");

        delay(800);
    }

    StageResult_e validate() override {
        if (_answer == 0) {
            return RET_INIT;
        }

        if (_answer < 0 || _answer < 3)
        {
            printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
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
        printf("� ������ ž���ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. ���峭 ����\n");
    }

    void exit() override {
        if (_answer == 1)
            printf("GM ������ �����ϼ̽��ϴ�.\n");
        if (_answer == 2)
            printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
        if (_answer == 3)
            printf("WIA ������ �����ϼ̽��ϴ�.\n");

        delay(800);
    }

    StageResult_e validate() override {
        if (_answer == 0) {
            return RET_INIT;
        }

        if (_answer < 0 || _answer > 4)
        {
            printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
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
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }

    void exit() override {
        if (_answer == 1)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        if (_answer == 2)
            printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");

        delay(800);
    }

    StageResult_e validate() override {
        if (_answer == 0) {
            return RET_INIT;
        }

        if (_answer < 0 || _answer > 2)
        {
            printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
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
        printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
        printf("� ������ �ұ��?\n");
        printf("0. ó�� ȭ������ ���ư���\n");
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
            printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
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
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
    }
    else
    {
        if (stack[Engine_Q] == 4)
        {
            printf("������ ���峪�ֽ��ϴ�.\n");
            printf("�ڵ����� �������� �ʽ��ϴ�.\n");
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

            printf("�ڵ����� ���۵˴ϴ�.\n");
        }
    }
}

void testProducedCar()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == MFR_CONTINENTAL)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == MFR_TOYOTA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == MFR_WIA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MFR_MANDO)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
    }
    else if (stack[brakeSystem_Q] == MFR_BOSCH && stack[SteeringSystem_Q] != MFR_BOSCH)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
    }
    else
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
}
*/