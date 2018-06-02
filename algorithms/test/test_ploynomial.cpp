//
// Created by luoyulong on 18/4/22.
//
#include <gtest/gtest.h>
#include <cmath>
#include "../src/ploynomial_algo.h"

class TestPloynomialAlgo: public testing::Test
{
public:
    void SetUp() override
    {}

    void TearDown() override
    {
    }

public:

};

TEST_F(TestPloynomialAlgo, PloynomialCalc)
{
    double coeff[4] = { 5.5, 6.5, 7.5, 8.5 };
    double x = 9.8;

    using namespace algo;
    double result = PloynomialCalc(coeff, coeff + 4, x);
    double result2 = coeff[0] * std::pow(x, 3) + coeff[1] * std::pow(x, 2) + coeff[2] * x + coeff[3];
    ASSERT_TRUE(std::abs(result - result2) < 1e-9);
}
