#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"
#include "Types.hpp"

class BrakeGM : public IBrake {
public:
	BrakeGM() : IBrake(Manufacturer_e::GM)
	{
	}
};

class EngineGM : public IEngine {
public:
	EngineGM() : IEngine(Manufacturer_e::GM)
	{
	}
};

class SteeringGM : public ISteering {
public:
	SteeringGM() : ISteering(Manufacturer_e::GM)
	{
	}
};

class GM : public IManufacturer
{
public:
	static GM instance() {
		static GM instance;
		return instance;
	}

	GM() : IManufacturer(Manufacturer_e::GM)
	{
	}

	IBrake* BuildBrake(VehicleType_e Type)
	{
		return new BrakeGM;
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		return new EngineGM;
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringGM;
	}
};