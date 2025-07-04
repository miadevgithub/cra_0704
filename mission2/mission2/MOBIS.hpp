#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"

class BrakeMOBIS : public IBrake {
public:
	BrakeMOBIS(VehicleType_e Type) : IBrake(Type, Manufacturer_e::MFR_MOBIS)
	{
	}

	void Display() override {
		printf("Brake System : Mobis\n");
	}
};

class EngineMOBIS : public IEngine {
public:
	EngineMOBIS(VehicleType_e Type) : IEngine(Type, Manufacturer_e::MFR_MOBIS)
	{
	}

	void Display() override {
		printf("Engine : Mobis\n");
	}
};

class SteeringMOBIS : public ISteering {
public:
	SteeringMOBIS(VehicleType_e Type) : ISteering(Type, Manufacturer_e::MFR_MOBIS)
	{
	}

	void Display() override {
		printf("SteeringSystem : Mobis\n");
	}
};

class MOBIS : public IManufacturer
{
public:
	static MOBIS instance() {
		static MOBIS instance;
		return instance;
	}

	MOBIS() : IManufacturer(Manufacturer_e::MFR_MOBIS)
	{
	}

	IBrake* BuildBrake(VehicleType_e Type)
	{
		return new BrakeMOBIS(Type);
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		return new EngineMOBIS(Type);
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringMOBIS(Type);
	}
};