#include <gmock/gmock.h>
#include "GM.hpp"
#include "MANDO.hpp"
#include "WIA.hpp"
#include "TOYOTA.hpp"
#include "CONTINENTAL.hpp"
#include "BOSCH.hpp"
#include "MOBIS.hpp"

// GM
class GM_FIXTURE : public ::testing::Test
{
public:
	GM mfr;
};

TEST_F(GM_FIXTURE, BuildBrake)
{
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::TRUCK), nullptr);
}

TEST_F(GM_FIXTURE, BuildEngine)
{
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::TRUCK), nullptr);
}

TEST_F(GM_FIXTURE, BuildSteering)
{
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::TRUCK), nullptr);
}


// TOYOTA
class TOYOTA_FIXTURE : public ::testing::Test
{
public:
	TOYOTA mfr;
};

TEST_F(TOYOTA_FIXTURE, BuildBrake)
{
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::TRUCK), nullptr);
}

TEST_F(TOYOTA_FIXTURE, BuildEngine)
{
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SEDAN), nullptr);
	EXPECT_EQ(mfr.instance().BuildEngine(VehicleType_e::SUV), nullptr) << "제한조건 2-2. 토요타는 SUV용 엔진을 만들지 않는다";
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::TRUCK), nullptr);
}

TEST_F(TOYOTA_FIXTURE, BuildSteering)
{
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::TRUCK), nullptr);
}


// WIA
class WIA_FIXTURE : public ::testing::Test
{
public:
	WIA mfr;
};

TEST_F(WIA_FIXTURE, BuildBrake)
{
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::TRUCK), nullptr);
}

TEST_F(WIA_FIXTURE, BuildEngine)
{
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SUV), nullptr);
	EXPECT_EQ(mfr.instance().BuildEngine(VehicleType_e::TRUCK), nullptr) << "제한조건 2-3. WIA는 Truck용 엔진을 만들지 않는다";
}

TEST_F(WIA_FIXTURE, BuildSteering)
{
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::TRUCK), nullptr);
}

// MANDO
class MANDO_FIXTURE : public ::testing::Test
{
public:
	MANDO mfr;
};

TEST_F(MANDO_FIXTURE, BuildBrake)
{
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SUV), nullptr);
	EXPECT_EQ(mfr.instance().BuildBrake(VehicleType_e::TRUCK), nullptr) << "제한조건 4-4. MANDO는 Truck용 제동장치를 만들지 않는다";
}

TEST_F(MANDO_FIXTURE, BuildEngine)
{
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::TRUCK), nullptr);
}

TEST_F(MANDO_FIXTURE, BuildSteering)
{
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::TRUCK), nullptr);
}

// CONTINENTAL
class CONTINENTAL_FIXTURE : public ::testing::Test
{
public:
	CONTINENTAL mfr;
};

TEST_F(CONTINENTAL_FIXTURE, BuildBrake)
{
	EXPECT_EQ(mfr.instance().BuildBrake(VehicleType_e::SEDAN), nullptr) << "제한조건 2-1. Continental은 Sedan용 제동장치를 만들지 않는다";
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::TRUCK), nullptr);
}

TEST_F(CONTINENTAL_FIXTURE, BuildEngine)
{
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::TRUCK), nullptr);
}

TEST_F(CONTINENTAL_FIXTURE, BuildSteering)
{
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::TRUCK), nullptr);
}


// BOSCH
class BOSCH_FIXTURE : public ::testing::Test
{
public:
	BOSCH mfr;
};

TEST_F(BOSCH_FIXTURE, BuildBrake)
{
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::TRUCK), nullptr);
}

TEST_F(BOSCH_FIXTURE, BuildEngine)
{
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::TRUCK), nullptr);
}

TEST_F(BOSCH_FIXTURE, BuildSteering)
{
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::TRUCK), nullptr);
}


// MOBIS
class MOBIS_FIXTURE : public ::testing::Test
{
public:
	MOBIS mfr;
};

TEST_F(MOBIS_FIXTURE, BuildBrake)
{
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildBrake(VehicleType_e::TRUCK), nullptr);
}

TEST_F(MOBIS_FIXTURE, BuildEngine)
{
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildEngine(VehicleType_e::TRUCK), nullptr);
}

TEST_F(MOBIS_FIXTURE, BuildSteering)
{
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SEDAN), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::SUV), nullptr);
	EXPECT_NE(mfr.instance().BuildSteering(VehicleType_e::TRUCK), nullptr);
}