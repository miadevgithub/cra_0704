#pragma once
#include "Manufacturer.hpp"

class ISteering : public IManufacturer {
public:
	explicit ISteering(VehicleType_e Type, Manufacturer_e Manufacturer) : IManufacturer(Manufacturer), _type(Type)
	{
	}

	VehicleType_e _type;

	virtual void Display() = 0;
};