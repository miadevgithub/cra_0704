#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"
#include "Types.hpp"

class BrakeCONTINENTAL : public IBrake {
public:
	BrakeCONTINENTAL() : IBrake(Manufacturer_e::CONTINENTAL)
	{
	}
};

class EngineCONTINENTAL : public IEngine {
public:
	EngineCONTINENTAL() : IEngine(Manufacturer_e::CONTINENTAL)
	{
	}
};

class SteeringCONTINENTAL : public ISteering {
public:
	SteeringCONTINENTAL() : ISteering(Manufacturer_e::CONTINENTAL)
	{
	}
};

class CONTINENTAL : public IManufacturer
{
public:
	static CONTINENTAL instance() {
		static CONTINENTAL instance;
		return instance;
	}

	CONTINENTAL() : IManufacturer(Manufacturer_e::CONTINENTAL)
	{
	}

	IBrake* BuildBrake(VehicleType_e Type)
	{
		if (Type == VehicleType_e::SEDAN) {
			return nullptr;
		}
		return new BrakeCONTINENTAL;
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		return new EngineCONTINENTAL;
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringCONTINENTAL;
	}
};