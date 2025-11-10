#include "../FlyFish/src/FlyFish.h"
#include "../src/Lab_01.h"

#include <gtest/gtest.h>

TEST(LAB_01, NormalizingMultiVector) {
    const MultiVector result{-0.126618, 0.158272, -0.189927, 0.221581,  -0.253236, 0.28489, - 0.316544, 0.348199, - 0.379853, 0.411508, - 0.443162, 0.474817, - 0.506471, 0.538126, - 0.56978, 0.601434};
    EXPECT_TRUE(Exercise_00(
        MultiVector{-4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16, 17, -18, 19})
        .RoundedEqual(result, 0.001f)
        );
}

TEST(LAB_01, IntersectionOfPlanes) {
    const TriVector result{ -1, 1, -1, 1};
    EXPECT_EQ(Exercise_01(Vector{5, 3, -1, 1}, Vector{2, 3, 2, 1}, Vector{1, 1, 1, 1}), result);
}

TEST(LAB_01, LineThroughPoints) {
    const BiVector result{ -0.56422, -0.059391, 0.32665, -0.50483, 0.059391, -0.86118};
    EXPECT_TRUE(Exercise_02(TriVector{2, 3, 4, 5}, TriVector{-4, 5, -6, 7}).RoundedEqual(result, 0.01f));
}

TEST(LAB_01, PlaneThroughPointWithNormal) {
    const Vector result{ -2.44949, 0.408248, 0.408248, .816497};
    EXPECT_TRUE(Exercise_03(TriVector{5, 3, -1, 1}, 1, 1, 2).RoundedEqual(result, 0.001f));
}

// Main entry point for Google Test
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
