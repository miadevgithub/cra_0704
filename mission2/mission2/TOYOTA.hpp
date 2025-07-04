#pragma once
#include "Manufacturer.hpp"
#include "Brake.hpp"
#include "Engine.hpp"
#include "Steering.hpp"
#include "Types.hpp"

class BrakeTOYOTA : public IBrake {
public:
	BrakeTOYOTA() : IBrake(Manufacturer_e::MFR_TOYOTA)
	{
	}
};

class EngineTOYOTA : public IEngine {
public:
	EngineTOYOTA() : IEngine(Manufacturer_e::MFR_TOYOTA)
	{
	}
};

class SteeringTOYOTA : public ISteering {
public:
	SteeringTOYOTA() : ISteering(Manufacturer_e::MFR_TOYOTA)
	{
	}
};

class TOYOTA : public IManufacturer
{
public:
	static TOYOTA instance() {
		static TOYOTA instance;
		return instance;
	}

	TOYOTA() : IManufacturer(Manufacturer_e::MFR_TOYOTA)
	{
	}

	IBrake* BuildBrake(VehicleType_e Type)
	{
		return new BrakeTOYOTA;
	}

	IEngine* BuildEngine(VehicleType_e Type)
	{
		if (Type == VehicleType_e::SUV) {
			return nullptr;
		}
		return new EngineTOYOTA;
	}

	ISteering* BuildSteering(VehicleType_e Type)
	{
		return new SteeringTOYOTA;
	}
};