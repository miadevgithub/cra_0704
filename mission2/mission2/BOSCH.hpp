#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"
#include <iostream>

class BrakeBOSCH : public IBrake {
public:
	BrakeBOSCH(VehicleType_e Type) : IBrake(Type, Manufacturer_e::MFR_BOSCH)
	{
	}

	void Display() override {
		printf("Brake System : Bosch\n");
	}
};

class EngineBOSCH : public IEngine {
public:
	EngineBOSCH(VehicleType_e Type) : IEngine(Type, Manufacturer_e::MFR_BOSCH)
	{
	}

	void Display() override {
		printf("Engine : Bosch\n");
	}
};

class SteeringBOSCH : public ISteering {
public:
	SteeringBOSCH(VehicleType_e Type) : ISteering(Type, Manufacturer_e::MFR_BOSCH)
	{
	}

	void Display() override {
		printf("SteeringSystem : Bosch\n");
	}
};

class BOSCH : public IManufacturer
{
public:
	static BOSCH instance() {
		static BOSCH instance;
		return instance;
	}

	BOSCH() : IManufacturer(Manufacturer_e::MFR_BOSCH)
	{
	}

	IBrake* BuildBrake(VehicleType_e Type)
	{
		return new BrakeBOSCH(Type);
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		return new EngineBOSCH(Type);
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringBOSCH(Type);
	}
};