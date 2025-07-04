#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"

class BrakeGM : public IBrake {
public:
	BrakeGM(VehicleType_e Type) : IBrake(Type, Manufacturer_e::MFR_GM)
	{
	}

	void Display() override {
		printf("Brake System : GM\n");
	}
};

class EngineGM : public IEngine {
public:
	EngineGM(VehicleType_e Type) : IEngine(Type, Manufacturer_e::MFR_GM)
	{
	}

	void Display() override {
		printf("Engine : GM\n");
	}
};

class SteeringGM : public ISteering {
public:
	SteeringGM(VehicleType_e Type) : ISteering(Type, Manufacturer_e::MFR_GM)
	{
	}

	void Display() override {
		printf("SteeringSystem : GM\n");
	}
};

class GM : public IManufacturer
{
public:
	static GM instance() {
		static GM instance;
		return instance;
	}

	GM() : IManufacturer(Manufacturer_e::MFR_GM)
	{
	}

	IBrake* BuildBrake(VehicleType_e Type)
	{
		return new BrakeGM(Type);
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		return new EngineGM(Type);
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringGM(Type);
	}
};