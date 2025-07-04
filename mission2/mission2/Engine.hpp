#pragma once
#include "Manufacturer.hpp"

class IEngine : public IManufacturer {
public:
	explicit IEngine(Manufacturer_e Manufacturer) : IManufacturer(Manufacturer)
	{
	}
};