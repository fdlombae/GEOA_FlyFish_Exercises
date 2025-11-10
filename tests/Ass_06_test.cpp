#include "../FlyFish/src/FlyFish.h"
#include "../src/Ass_06.h"

#include <gtest/gtest.h>

TEST(LAB_06, ClosestPoint1) {
    const TriVector point1 = {-1, -1, 0, 1};
    const TriVector point2 = {0, -1, -1, 1};
    const Vector plane1 = {0, 0, 1, 1};

    EXPECT_EQ(point1, ClosestPointToPlane(plane1, point1, point2));
}

TEST(LAB_06, ClosestPoint2) {
    const TriVector point1 = {4, 10, 0, 2};
    const TriVector point2 = {4, 12, 0, 4};
    const Vector plane1 = {3, 14, 0, 0};

    EXPECT_EQ(point2, ClosestPointToPlane(plane1, point1, point2));
}

TEST(LAB_06, OverlappingPoints) {
    const TriVector point1 = {4, 10, 0, 2};
    const TriVector point2 = {4, 10, 0, 2};
    const Vector plane1 = {3, -14, 0, -1};

    EXPECT_EQ(point1, ClosestPointToPlane(plane1, point1, point2));
}

TEST(LAB_06, PointsInPlane) {
    const TriVector point1 = {2, 3, 0 , 3};
    const TriVector point2 = {0, -2, 0, -2};
    const Vector plane1 = {1, 0, 1, 0};

    EXPECT_EQ(point1, ClosestPointToPlane(plane1, point1, point2));
}

// Main entry point for Google Test
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
