#pragma once
#include "Manufacturer.hpp"

class IEngine : public IManufacturer {
public:
	explicit IEngine(VehicleType_e Type, Manufacturer_e Manufacturer) : IManufacturer(Manufacturer), _type(Type)
	{
	}

	VehicleType_e _type;

	virtual void Display() = 0;
};

class BrokenEngine : public IEngine {
public:
	explicit BrokenEngine() : IEngine(SEDAN, MFR_BROKEN)
	{
	}

	void Display() override
	{

	}
};