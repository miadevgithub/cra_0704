#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"
#include "Types.hpp"

class BrakeWIA : public IBrake {
public:
	BrakeWIA() : IBrake(Manufacturer_e::MFR_WIA)
	{
	}
};

class EngineWIA : public IEngine {
public:
	EngineWIA() : IEngine(Manufacturer_e::MFR_WIA)
	{
	}
};

class SteeringWIA : public ISteering {
public:
	SteeringWIA() : ISteering(Manufacturer_e::MFR_WIA)
	{
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
		return new BrakeWIA;
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		if (Type == VehicleType_e::TRUCK) {
			return nullptr;
		}
		return new EngineWIA;
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringWIA;
	}
};