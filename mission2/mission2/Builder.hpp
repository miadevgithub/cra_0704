#include "BOSCH.hpp"
#include "CONTINENTAL.hpp"
#include "GM.hpp"
#include "MANDO.hpp"
#include "MOBIS.hpp"
#include "TOYOTA.hpp"
#include "WIA.hpp"

#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"

struct ManufacturerInfo_t
{
    VehicleType_e _type;
    Manufacturer_e _engine;
    Manufacturer_e _brake;   
    Manufacturer_e _steering;
};

class Car {
public:
    explicit Car(const ManufacturerInfo_t& rInfo) {
        _type = rInfo._type;
        _brake = BuildBrake(rInfo._type, rInfo._brake);
        _engine = BuildEngine(rInfo._type, rInfo._engine);
        _steering = BuildSteering(rInfo._type, rInfo._engine);
    }

    void Display() {
        if (_type == 1)
            printf("Car Type : Sedan\n");
        if (_type == 2)
            printf("Car Type : SUV\n");
        if (_type == 3)
            printf("Car Type : Truck\n");

        _engine->Display();
        _brake->Display();
        _steering->Display();
    }

    void Build(const ManufacturerInfo_t& rInfo)
    {
        if (isValidCheck(rInfo) == false)
        {
            printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        }
        else
        {
            if (_engine->GetManufacturer() == MFR_BROKEN)
            {
                printf("������ ���峪�ֽ��ϴ�.\n");
                printf("�ڵ����� �������� �ʽ��ϴ�.\n");
            }
            else
            {

                Display();

                printf("�ڵ����� ���۵˴ϴ�.\n");
            }
        }
    }

    bool TestBuild(const ManufacturerInfo_t& rInfo)
    {
        if (rInfo._type == SEDAN && rInfo._brake == MFR_CONTINENTAL)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Sedan���� Continental������ġ ��� �Ұ�\n");
            return false;
        }
        else if (rInfo._type == SUV && rInfo._engine == MFR_TOYOTA)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("SUV���� TOYOTA���� ��� �Ұ�\n");
            return false;
        }
        else if (rInfo._type == TRUCK && rInfo._engine == MFR_WIA)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� WIA���� ��� �Ұ�\n");
            return false;
        }
        else if (rInfo._type == TRUCK && rInfo._brake == MFR_MANDO)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� Mando������ġ ��� �Ұ�\n");
            return false;
        }
        else if (rInfo._brake == MFR_BOSCH && rInfo._steering != MFR_BOSCH)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
            return false;
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
            return true;
        }
    }

protected:
    IBrake* BuildBrake(VehicleType_e type, Manufacturer_e mfr)
    {
        IBrake* brake = nullptr;

        switch (mfr) {
        case MFR_BOSCH:
            brake = BOSCH::instance().BuildBrake(type);
            break;

        case MFR_CONTINENTAL:
            brake = CONTINENTAL::instance().BuildBrake(type);
            break;

        case MFR_GM:
            brake = GM::instance().BuildBrake(type);
            break;

        case MFR_MANDO:
            brake = MANDO::instance().BuildBrake(type);
            break;

        case MFR_MOBIS:
            brake = MOBIS::instance().BuildBrake(type);
            break;

        case MFR_TOYOTA:
            brake = TOYOTA::instance().BuildBrake(type);
            break;

        case MFR_WIA:
            brake = WIA::instance().BuildBrake(type);
            break;

        default:
            break;
        }
        return brake;
    }

    IEngine* BuildEngine(VehicleType_e type, Manufacturer_e mfr)
    {
        IEngine* engine = nullptr;

        switch (mfr) {
        case MFR_BOSCH:
            engine = BOSCH::instance().BuildEngine(type);
            break;

        case MFR_CONTINENTAL:
            engine = CONTINENTAL::instance().BuildEngine(type);
            break;

        case MFR_GM:
            engine = GM::instance().BuildEngine(type);
            break;

        case MFR_MANDO:
            engine = MANDO::instance().BuildEngine(type);
            break;

        case MFR_MOBIS:
            engine = MOBIS::instance().BuildEngine(type);
            break;

        case MFR_TOYOTA:
            engine = TOYOTA::instance().BuildEngine(type);
            break;

        case MFR_WIA:
            engine = WIA::instance().BuildEngine(type);
            break;

        case MFR_BROKEN:
            engine = new BrokenEngine;
            break;

        default:
            break;
        }
        return engine;
    }

    ISteering* BuildSteering(VehicleType_e type, Manufacturer_e mfr)
    {
        ISteering* steering = nullptr;

        switch (mfr) {
        case MFR_BOSCH:
            steering = BOSCH::instance().BuildSteering(type);
            break;

        case MFR_CONTINENTAL:
            steering = CONTINENTAL::instance().BuildSteering(type);
            break;

        case MFR_GM:
            steering = GM::instance().BuildSteering(type);
            break;

        case MFR_MANDO:
            steering = MANDO::instance().BuildSteering(type);
            break;

        case MFR_MOBIS:
            steering = MOBIS::instance().BuildSteering(type);
            break;

        case MFR_TOYOTA:
            steering = TOYOTA::instance().BuildSteering(type);
            break;

        case MFR_WIA:
            steering = WIA::instance().BuildSteering(type);
            break;

        default:
            break;
        }
        return steering;
    }

    int isValidCheck(const ManufacturerInfo_t& rInfo)
    {
        if (rInfo._type == SEDAN && rInfo._brake == MFR_CONTINENTAL)
        {
            return false;
        }
        else if (rInfo._type == SUV && rInfo._engine == MFR_TOYOTA)
        {
            return false;
        }
        else if (rInfo._type == TRUCK && rInfo._engine == MFR_WIA)
        {
            return false;
        }
        else if (rInfo._type == TRUCK && rInfo._brake == MFR_MANDO)
        {
            return false;
        }
        else if (rInfo._brake == MFR_BOSCH && rInfo._steering != MFR_BOSCH)
        {
            return false;
        }
        else
        {
            return true;
        }
        return true;
    }

private:
    IBrake* _brake;
    IEngine* _engine;
    ISteering* _steering;
    VehicleType_e _type;
};