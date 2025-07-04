#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"
#include "Types.hpp"

class BrakeBOSCH : public IBrake {
public:
	BrakeBOSCH() : IBrake(Manufacturer_e::MFR_BOSCH)
	{
	}
};

class EngineBOSCH : public IEngine {
public:
	EngineBOSCH() : IEngine(Manufacturer_e::MFR_BOSCH)
	{
	}
};

class SteeringBOSCH : public ISteering {
public:
	SteeringBOSCH() : ISteering(Manufacturer_e::MFR_BOSCH)
	{
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
		return new BrakeBOSCH;
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		return new EngineBOSCH;
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringBOSCH;
	}
};