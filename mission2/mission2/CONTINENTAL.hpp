#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"

class BrakeCONTINENTAL : public IBrake {
public:
	BrakeCONTINENTAL(VehicleType_e Type) : IBrake(Type, Manufacturer_e::MFR_CONTINENTAL)
	{
	}

	void Display() override {
		printf("Brake System : Continental\n");
	}
};

class EngineCONTINENTAL : public IEngine {
public:
	EngineCONTINENTAL(VehicleType_e Type) : IEngine(Type, Manufacturer_e::MFR_CONTINENTAL)
	{
	}

	void Display() override {
		printf("Engine : Continental\n");
	}
};

class SteeringCONTINENTAL : public ISteering {
public:
	SteeringCONTINENTAL(VehicleType_e Type) : ISteering(Type, Manufacturer_e::MFR_CONTINENTAL)
	{
	}

	void Display() override {
		printf("SteeringSystem : Continental\n");
	}
};

class CONTINENTAL : public IManufacturer
{
public:
	static CONTINENTAL instance() {
		static CONTINENTAL instance;
		return instance;
	}

	CONTINENTAL() : IManufacturer(Manufacturer_e::MFR_CONTINENTAL)
	{
	}

	IBrake* BuildBrake(VehicleType_e Type)
	{
		if (Type == VehicleType_e::SEDAN) {
			return nullptr;
		}
		return new BrakeCONTINENTAL(Type);
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		return new EngineCONTINENTAL(Type);
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringCONTINENTAL(Type);
	}
};