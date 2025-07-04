#pragma once
enum Manufacturer_e
{
	MFR_GM,
	MFR_TOYOTA,
	MFR_WIA,
	MFR_MANDO,
	MFR_CONTINENTAL,
	MFR_BOSCH,
	MFR_MOBIS,
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