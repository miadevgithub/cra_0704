#pragma once
#include <iostream>

enum VehicleType_e
{
	SEDAN = 1,
	SUV,
	TRUCK,
};

enum Manufacturer_e
{
	MFR_GM,
	MFR_TOYOTA,
	MFR_WIA,
	MFR_MANDO,
	MFR_CONTINENTAL,
	MFR_BOSCH,
	MFR_MOBIS,
	MFR_BROKEN,
	MFR_MAX,
};

class IManufacturer
{
public:
	explicit IManufacturer(Manufacturer_e Manufacturer) : _Manufacturer(Manufacturer)
	{
	}

	inline Manufacturer_e GetManufacturer() const {
		return _Manufacturer;
	}

private:
	Manufacturer_e _Manufacturer;
};