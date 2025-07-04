#pragma once
#include "Manufacturer.hpp"
#include "Builder.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define CLEAR_SCREEN "\033[H\033[2J"

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
    virtual void entry(ManufacturerInfo_t& rInfo) = 0;
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

    ManufacturerInfo_t _manufacturer_info;
protected:
    char _buf[100];
    int _answer;

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
};

class StageCarType : public Stage {
public:
    void entry(ManufacturerInfo_t& rInfo) override {
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
        if (_answer == 1) {
            printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
            _manufacturer_info._type = SEDAN;
        }
        if (_answer == 2) {
            printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
            _manufacturer_info._type = SUV;
        }
        if (_answer == 3) {
            printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
            _manufacturer_info._type = TRUCK;
        }

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
    void entry(ManufacturerInfo_t& rInfo) override {
        _manufacturer_info = rInfo;
        printf(CLEAR_SCREEN);
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }

    void exit() override {
        if (_answer == 1) {
            printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
            _manufacturer_info._brake = MFR_MANDO;
        }
        if (_answer == 2) {
            printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
            _manufacturer_info._brake = MFR_CONTINENTAL;
        }
        if (_answer == 3) {
            _manufacturer_info._brake = MFR_BOSCH;
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        }

        delay(800);
    }

    StageResult_e validate() override {
        if (_answer == 0) {
            return RET_INIT;
        }

        if (_answer < 0 || _answer > 3)
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
    void entry(ManufacturerInfo_t& rInfo) override {
        _manufacturer_info = rInfo;
        printf(CLEAR_SCREEN);
        printf("� ������ ž���ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. ���峭 ����\n");
    }

    void exit() override {
        if (_answer == 1) {
            printf("GM ������ �����ϼ̽��ϴ�.\n");
            _manufacturer_info._engine = MFR_GM;
        }
        if (_answer == 2) {
            printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
            _manufacturer_info._engine = MFR_TOYOTA;
        }
        if (_answer == 3) {
            printf("WIA ������ �����ϼ̽��ϴ�.\n");
            _manufacturer_info._engine = MFR_WIA;
        }
        if (_answer == 4) {
            _manufacturer_info._engine = MFR_BROKEN;
        }

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
    void entry(ManufacturerInfo_t& rInfo) override {
        _manufacturer_info = rInfo;

        printf(CLEAR_SCREEN);
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }

    void exit() override {
        
        if (_answer == 1) {
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
            _manufacturer_info._steering = MFR_BOSCH;
        }

        if (_answer == 2) {
            printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
            _manufacturer_info._steering = MFR_MOBIS;
        }

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
    void entry(ManufacturerInfo_t& rInfo) override {
        _manufacturer_info = rInfo;

        printf(CLEAR_SCREEN);
        printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
        printf("� ������ �ұ��?\n");
        printf("0. ó�� ȭ������ ���ư���\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }

    void exit() override {
        Car car(_manufacturer_info);
        if (_answer == 1)
        {
            car.Build(_manufacturer_info);
            delay(2000);
        }
        else if (_answer == 2)
        {
            printf("Test...\n");
            delay(1500);
            car.TestBuild(_manufacturer_info);
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