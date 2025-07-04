#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"
#include "Types.hpp"

class BrakeMANDO : public IBrake {
public:
	BrakeMANDO() : IBrake(Manufacturer_e::MANDO)
	{
	}
};

class EngineMANDO : public IEngine {
public:
	EngineMANDO() : IEngine(Manufacturer_e::MANDO)
	{
	}
};

class SteeringMANDO : public ISteering {
public:
	SteeringMANDO() : ISteering(Manufacturer_e::MANDO)
	{
	}
};

class MANDO : public IManufacturer
{
public:
	static MANDO instance() {
		static MANDO instance;
		return instance;
	}

	MANDO() : IManufacturer(Manufacturer_e::MANDO)
	{
	}

	IBrake* BuildBrake(VehicleType_e Type)
	{
		if (Type == VehicleType_e::TRUCK) {
			return nullptr;
		}
		return new BrakeMANDO;
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		return new EngineMANDO;
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringMANDO;
	}
};