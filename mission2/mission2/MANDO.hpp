#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"

class BrakeMANDO : public IBrake {
public:
	BrakeMANDO(VehicleType_e Type) : IBrake(Type, Manufacturer_e::MFR_MANDO)
	{
	}

	void Display() override {
		printf("Brake System : Mando\n");
	}
};

class EngineMANDO : public IEngine {
public:
	EngineMANDO(VehicleType_e Type) : IEngine(Type, Manufacturer_e::MFR_MANDO)
	{
	}

	void Display() override {
		printf("Engine : Mando\n");
	}
};

class SteeringMANDO : public ISteering {
public:
	SteeringMANDO(VehicleType_e Type) : ISteering(Type, Manufacturer_e::MFR_MANDO)
	{
	}

	void Display() override {
		printf("SteeringSystem : Mando\n");
	}
};

class MANDO : public IManufacturer
{
public:
	static MANDO instance() {
		static MANDO instance;
		return instance;
	}

	MANDO() : IManufacturer(Manufacturer_e::MFR_MANDO)
	{
	}

	IBrake* BuildBrake(VehicleType_e Type)
	{
		if (Type == VehicleType_e::TRUCK) {
			return nullptr;
		}
		return new BrakeMANDO(Type);
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		return new EngineMANDO(Type);
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringMANDO(Type);
	}
};