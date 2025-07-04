#pragma once
#include "Manufacturer.hpp"

class IBrake : public IManufacturer {
public:
	explicit IBrake(Manufacturer_e Manufacturer) : IManufacturer(Manufacturer)
	{
	}
};