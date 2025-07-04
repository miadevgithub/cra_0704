#pragma once
#include "Manufacturer.hpp"

class ISteering : public IManufacturer {
public:
	explicit ISteering(Manufacturer_e Manufacturer) : IManufacturer(Manufacturer)
	{
	}
};