#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"
#include "Types.hpp"

class BrakeMOBIS : public IBrake {
public:
	BrakeMOBIS() : IBrake(Manufacturer_e::MFR_MOBIS)
	{
	}
};

class EngineMOBIS : public IEngine {
public:
	EngineMOBIS() : IEngine(Manufacturer_e::MFR_MOBIS)
	{
	}
};

class SteeringMOBIS : public ISteering {
public:
	SteeringMOBIS() : ISteering(Manufacturer_e::MFR_MOBIS)
	{
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
		return new BrakeMOBIS;
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		return new EngineMOBIS;
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringMOBIS;
	}
};