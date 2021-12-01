#ifndef LOTTERY_TESTS_H
#define LOTTERY_TESTS_H

#include <set>
#include <assert.h>

#include <TestFixture.h>
#include <TestSuite.h>
#include <TestAssert.h>
#include <TestCase.h>
#include <TestCaller.h>

#include "Lottery.h"
#include "TestInput.h"

class LotteryTests : public CppUnit::TestFixture
{
public:

    static CppUnit::Test * suite();

    void setUp();
    void tearDown();

    void checkForSixNumbers();
    void checkNumberRange();
    void checkForRepeatingNumbers();

private:

    TestInput * m_input;
    Lottery * m_lottery;

};

#endif // !LOTTERY_TESTS_H