#pragma once
enum Manufacturer_e
{
	GM,
	TOYOTA,
	WIA,
	MANDO,
	CONTINENTAL,
	BOSCH,
	MOBIS,
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