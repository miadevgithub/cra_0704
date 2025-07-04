#pragma once
#include "Types.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define CLEAR_SCREEN "\033[H\033[2J"

int stack[10];

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA
};

enum brakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS
};

class Menu
{
public:
	int Run() {
        char buf[100];
        int step = CarType_Q;
        int next_step = CarType_Q;

        while (1)
        {
            displayMenu(step);

            getUserInput(buf);

            if (isUserExit(buf)) {
                break;
            }

            checkUserInput(step, buf);
            if (checkUserInput(step, buf) == false) {
                continue;
            }

            executeUserInput(step, buf);
        }

        return 0;
	}

private:
    void getUserInput(char* buf)
    {
        printf("INPUT > ");
        fgets(buf, sizeof(buf), stdin);

        // ���� ���๮�� ����
        char* context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);
    }

    bool isUserExit(char* buf)
    {
        if (!strcmp(buf, "exit"))
        {
            printf("���̹���\n");
            return true;
        }
        return false;
    }

    bool checkUserInput(int& step, char* buf)
    {
        // ���ڷ� �� ������� Ȯ��
        char* checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ
        // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
        if (*checkNumber != '\0')
        {
            printf("ERROR :: ���ڸ� �Է� ����\n");
            delay(800);
            return false;
        }

        if (step == CarType_Q && !(answer >= 1 && answer <= 3))
        {
            printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
            delay(800);
            return false;
        }

        if (step == Engine_Q && !(answer >= 0 && answer <= 4))
        {
            printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
            delay(800);
            return false;
        }

        if (step == brakeSystem_Q && !(answer >= 0 && answer <= 3))
        {
            printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
            delay(800);
            return false;
        }

        if (step == SteeringSystem_Q && !(answer >= 0 && answer <= 2))
        {
            printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
            delay(800);
            return false;
        }

        if (step == Run_Test && !(answer >= 0 && answer <= 2))
        {
            printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
            delay(800);
            return false;
        }

        // ó������ ���ư���
        if (answer == 0 && step == Run_Test)
        {
            step = CarType_Q;
            return false;
        }

        // �������� ���ư���
        if (answer == 0 && step >= 1)
        {
            step -= 1;
            return false;
        }

        return true;
    }

    void executeUserInput(int& step, char buf[100])
    {
        // ���ڷ� �� ������� Ȯ��
        char* checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ
        // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
        if (*checkNumber != '\0')
        {
            printf("ERROR :: ���ڸ� �Է� ����\n");
            delay(800);
            return;
        }

        if (step == CarType_Q)
        {
            selectCarType(answer);
            delay(800);
            step = Engine_Q;
        }
        else if (step == Engine_Q)
        {
            selectEngine(answer);
            delay(800);
            step = brakeSystem_Q;
        }
        else if (step == brakeSystem_Q)
        {
            selectbrakeSystem(answer);
            delay(800);
            step = SteeringSystem_Q;
        }
        else if (step == SteeringSystem_Q)
        {
            selectSteeringSystem(answer);
            delay(800);
            step = Run_Test;
        }
        else if (step == Run_Test && answer == 1)
        {
            runProducedCar();
            delay(2000);
        }
        else if (step == Run_Test && answer == 2)
        {
            printf("Test...\n");
            delay(1500);
            testProducedCar();
            delay(2000);
        }
    }

    void displayMenu(int step)
    {
        switch (step)
        {
        case CarType_Q:
            displayCarTypeMenu();
            break;
        case Engine_Q:
            displayEngineMenu();
            break;
        case brakeSystem_Q:
            displayBrakeMenu();
            break;

        case SteeringSystem_Q:
            displaySteeringMenu();
            break;

        case Run_Test:
            displayRunMenu();
            break;
        default:
            break;
        }
        printf("===============================\n");
    }

    void displayCarTypeMenu()
    {
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

    void displayEngineMenu()
    {
        printf(CLEAR_SCREEN);
        printf("� ������ ž���ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. ���峭 ����\n");
    }

    void displayBrakeMenu()
    {
        printf(CLEAR_SCREEN);
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }

    void displaySteeringMenu()
    {
        printf(CLEAR_SCREEN);
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }

    void displayRunMenu()
    {
        printf(CLEAR_SCREEN);
        printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
        printf("� ������ �ұ��?\n");
        printf("0. ó�� ȭ������ ���ư���\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }

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

    void selectCarType(int answer)
    {
        stack[CarType_Q] = answer;
        if (answer == 1)
            printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
        if (answer == 2)
            printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
        if (answer == 3)
            printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
    }

    void selectEngine(int answer)
    {
        stack[Engine_Q] = answer;
        if (answer == 1)
            printf("GM ������ �����ϼ̽��ϴ�.\n");
        if (answer == 2)
            printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
        if (answer == 3)
            printf("WIA ������ �����ϼ̽��ϴ�.\n");
    }

    void selectbrakeSystem(int answer)
    {
        stack[brakeSystem_Q] = answer;
        if (answer == 1)
            printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == 2)
            printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == 3)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
    }

    void selectSteeringSystem(int answer)
    {
        stack[SteeringSystem_Q] = answer;
        if (answer == 1)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == 2)
            printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
    }

    int isValidCheck()
    {
        if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
        {
            return false;
        }
        else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
        {
            return false;
        }
        else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
        {
            return false;
        }
        else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
        {
            return false;
        }
        else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
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
        if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Sedan���� Continental������ġ ��� �Ұ�\n");
        }
        else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("SUV���� TOYOTA���� ��� �Ұ�\n");
        }
        else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� WIA���� ��� �Ұ�\n");
        }
        else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� Mando������ġ ��� �Ұ�\n");
        }
        else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
        }
    }
};