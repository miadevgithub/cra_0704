#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"

class BrakeTOYOTA : public IBrake {
public:
	BrakeTOYOTA(VehicleType_e Type) : IBrake(Type, Manufacturer_e::MFR_TOYOTA)
	{
	}

	void Display() override {
		printf("Brake System : TOYOTA\n");
	}
};

class EngineTOYOTA : public IEngine {
public:
	EngineTOYOTA(VehicleType_e Type) : IEngine(Type, Manufacturer_e::MFR_TOYOTA)
	{
	}

	void Display() override {
		printf("Engine : TOYOTA\n");
	}
};

class SteeringTOYOTA : public ISteering {
public:
	SteeringTOYOTA(VehicleType_e Type) : ISteering(Type, Manufacturer_e::MFR_TOYOTA)
	{
	}

	void Display() override {
		printf("SteeringSystem : TOYOTA\n");
	}
};

class TOYOTA : public IManufacturer
{
public:
	static TOYOTA instance() {
		static TOYOTA instance;
		return instance;
	}

	TOYOTA() : IManufacturer(Manufacturer_e::MFR_TOYOTA)
	{
	}

	IBrake* BuildBrake(VehicleType_e Type)
	{
		return new BrakeTOYOTA(Type);
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		if (Type == VehicleType_e::SUV) {
			return nullptr;
		}
		return new EngineTOYOTA(Type);
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringTOYOTA(Type);
	}
};