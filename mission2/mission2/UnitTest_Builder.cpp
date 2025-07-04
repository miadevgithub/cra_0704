#include <gmock/gmock.h>
#include "Builder.hpp"

class BUILDER_FIXTURE : public ::testing::Test
{
public:
};

struct TestInput
{
	ManufacturerInfo_t info;
	bool result;
};

TEST_F(BUILDER_FIXTURE, Sedan)
{
	TestInput input[] = {
		// {TYPE, ENGINE, BRAKE, STEERING},
		{{SEDAN, MFR_GM, MFR_MANDO, MFR_BOSCH}, true },
		{{SEDAN, MFR_GM, MFR_MANDO, MFR_MOBIS}, true },
		{{SEDAN, MFR_GM, MFR_CONTINENTAL, MFR_BOSCH}, false},
		{{SEDAN, MFR_GM, MFR_CONTINENTAL, MFR_MOBIS}, false},
		{{SEDAN, MFR_GM, MFR_BOSCH, MFR_BOSCH}, true},
		{{SEDAN, MFR_GM, MFR_BOSCH, MFR_MOBIS}, false},

		{{SEDAN, MFR_TOYOTA, MFR_MANDO, MFR_BOSCH}, true},
		{{SEDAN, MFR_TOYOTA, MFR_MANDO, MFR_MOBIS}, true},
		{{SEDAN, MFR_TOYOTA, MFR_CONTINENTAL, MFR_BOSCH}, false},
		{{SEDAN, MFR_TOYOTA, MFR_CONTINENTAL, MFR_MOBIS}, false},
		{{SEDAN, MFR_TOYOTA, MFR_BOSCH, MFR_BOSCH}, true},
		{{SEDAN, MFR_TOYOTA, MFR_BOSCH, MFR_MOBIS}, false},

		{{SEDAN, MFR_WIA, MFR_MANDO, MFR_BOSCH}, true},
		{{SEDAN, MFR_WIA, MFR_MANDO, MFR_MOBIS}, true},
		{{SEDAN, MFR_WIA, MFR_CONTINENTAL, MFR_BOSCH}, false},
		{{SEDAN, MFR_WIA, MFR_CONTINENTAL, MFR_MOBIS}, false},
		{{SEDAN, MFR_WIA, MFR_BOSCH, MFR_BOSCH}, true},
		{{SEDAN, MFR_WIA, MFR_BOSCH, MFR_MOBIS}, false},
	};

	for (int i = 0; i < (sizeof(input) / sizeof(TestInput)); ++i) {
		Car car(input[i].info);
		bool result = car.TestBuild(input[i].info);
		EXPECT_EQ(result, input[i].result);
	}
}

TEST_F(BUILDER_FIXTURE, Suv)
{
	TestInput input[] = {
		// {TYPE, ENGINE, BRAKE, STEERING},
		{{SUV, MFR_GM, MFR_MANDO, MFR_BOSCH}, true },
		{{SUV, MFR_GM, MFR_MANDO, MFR_MOBIS}, true },
		{{SUV, MFR_GM, MFR_CONTINENTAL, MFR_BOSCH}, true},
		{{SUV, MFR_GM, MFR_CONTINENTAL, MFR_MOBIS}, true},
		{{SUV, MFR_GM, MFR_BOSCH, MFR_BOSCH}, true},
		{{SUV, MFR_GM, MFR_BOSCH, MFR_MOBIS}, false},

		{{SUV, MFR_TOYOTA, MFR_MANDO, MFR_BOSCH}, false},
		{{SUV, MFR_TOYOTA, MFR_MANDO, MFR_MOBIS}, false},
		{{SUV, MFR_TOYOTA, MFR_CONTINENTAL, MFR_BOSCH}, false},
		{{SUV, MFR_TOYOTA, MFR_CONTINENTAL, MFR_MOBIS}, false},
		{{SUV, MFR_TOYOTA, MFR_BOSCH, MFR_BOSCH}, false},
		{{SUV, MFR_TOYOTA, MFR_BOSCH, MFR_MOBIS}, false},

		{{SUV, MFR_WIA, MFR_MANDO, MFR_BOSCH}, true},
		{{SUV, MFR_WIA, MFR_MANDO, MFR_MOBIS}, true},
		{{SUV, MFR_WIA, MFR_CONTINENTAL, MFR_BOSCH}, true},
		{{SUV, MFR_WIA, MFR_CONTINENTAL, MFR_MOBIS}, true},
		{{SUV, MFR_WIA, MFR_BOSCH, MFR_BOSCH}, true},
		{{SUV, MFR_WIA, MFR_BOSCH, MFR_MOBIS}, false},
	};

	for (int i = 0; i < (sizeof(input) / sizeof(TestInput)); ++i) {
		Car car(input[i].info);
		bool result = car.TestBuild(input[i].info);
		EXPECT_EQ(result, input[i].result);
	}
}

TEST_F(BUILDER_FIXTURE, Truck)
{
	TestInput input[] = {
		// {TYPE, ENGINE, BRAKE, STEERING},
		{{TRUCK, MFR_GM, MFR_MANDO, MFR_BOSCH}, false },
		{{TRUCK, MFR_GM, MFR_MANDO, MFR_MOBIS}, false },
		{{TRUCK, MFR_GM, MFR_CONTINENTAL, MFR_BOSCH}, true},
		{{TRUCK, MFR_GM, MFR_CONTINENTAL, MFR_MOBIS}, true},
		{{TRUCK, MFR_GM, MFR_BOSCH, MFR_BOSCH}, true},
		{{TRUCK, MFR_GM, MFR_BOSCH, MFR_MOBIS}, false},

		{{TRUCK, MFR_TOYOTA, MFR_MANDO, MFR_BOSCH}, false},
		{{TRUCK, MFR_TOYOTA, MFR_MANDO, MFR_MOBIS}, false},
		{{TRUCK, MFR_TOYOTA, MFR_CONTINENTAL, MFR_BOSCH}, true},
		{{TRUCK, MFR_TOYOTA, MFR_CONTINENTAL, MFR_MOBIS}, true},
		{{TRUCK, MFR_TOYOTA, MFR_BOSCH, MFR_BOSCH}, true},
		{{TRUCK, MFR_TOYOTA, MFR_BOSCH, MFR_MOBIS}, false},

		{{TRUCK, MFR_WIA, MFR_MANDO, MFR_BOSCH}, false},
		{{TRUCK, MFR_WIA, MFR_MANDO, MFR_MOBIS}, false},
		{{TRUCK, MFR_WIA, MFR_CONTINENTAL, MFR_BOSCH}, false},
		{{TRUCK, MFR_WIA, MFR_CONTINENTAL, MFR_MOBIS}, false},
		{{TRUCK, MFR_WIA, MFR_BOSCH, MFR_BOSCH}, false},
		{{TRUCK, MFR_WIA, MFR_BOSCH, MFR_MOBIS}, false},
	};

	for (int i = 0; i < (sizeof(input) / sizeof(TestInput)); ++i) {
		Car car(input[i].info);
		bool result = car.TestBuild(input[i].info);
		EXPECT_EQ(result, input[i].result) << i;
	}
}