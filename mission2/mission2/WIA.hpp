#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"

class BrakeWIA : public IBrake {
public:
	BrakeWIA(VehicleType_e Type) : IBrake(Type, Manufacturer_e::MFR_WIA)
	{
	}

	void Display() override {
		printf("Brake System : WIA\n");
	}
};

class EngineWIA : public IEngine {
public:
	EngineWIA(VehicleType_e Type) : IEngine(Type, Manufacturer_e::MFR_WIA)
	{
	}

	void Display() override {
		printf("Engine : WIA\n");
	}
};

class SteeringWIA : public ISteering {
public:
	SteeringWIA(VehicleType_e Type) : ISteering(Type, Manufacturer_e::MFR_WIA)
	{
	}

	void Display() override {
		printf("SteeringSystem : WIA\n");
	}
};

class WIA : public IManufacturer
{
public:
	static WIA instance() {
		static WIA instance;
		return instance;
	}

	WIA() : IManufacturer(Manufacturer_e::MFR_WIA)
	{
	}

	IBrake* BuildBrake(VehicleType_e Type)
	{
		return new BrakeWIA(Type);
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		if (Type == VehicleType_e::TRUCK) {
			return nullptr;
		}
		return new EngineWIA(Type);
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringWIA(Type);
	}
};