#include "LotteryTests.h"

// ----------------------------------------------------------------------------
CppUnit::Test * LotteryTests::suite()
{
    CppUnit::TestSuite * suit = new CppUnit::TestSuite("Lottery Tests");

    // == ADDS ALL THE TESTS WITH NAMES ==

    // Six Number Checks.
    // ------------------------------------------------------------------------
    suit->addTest(new CppUnit::TestCaller<LotteryTests>(
        "Check for Six Numbers", 
        &LotteryTests::checkForSixNumbers));

    suit->addTest(new CppUnit::TestCaller<LotteryTests>(
        "Check for Six Numbers with Mixed Input", 
        &LotteryTests::checkForSixNumbersMixedInput));

    suit->addTest(new CppUnit::TestCaller<LotteryTests>(
        "Check for Six Numbers with Invalid Input", 
        &LotteryTests::checkForSixNumbersInvalidInput));

    // Number Range Checks.
    // ------------------------------------------------------------------------
    suit->addTest(new CppUnit::TestCaller<LotteryTests>(
        "Check Number Range", 
        &LotteryTests::checkNumberRange));

    suit->addTest(new CppUnit::TestCaller<LotteryTests>(
        "Check Number Range with Mixed Input", 
        &LotteryTests::checkNumberRangeMixedInput));

    suit->addTest(new CppUnit::TestCaller<LotteryTests>(
        "Check Number Range with Invalid Input", 
        &LotteryTests::checkNumberRangeInvalidInput));

    // Repeating Numbers Checks.
    // ------------------------------------------------------------------------
    suit->addTest(new CppUnit::TestCaller<LotteryTests>(
        "Check for Repeating Numbers", 
        &LotteryTests::checkForRepeatingNumbers));
    
    suit->addTest(new CppUnit::TestCaller<LotteryTests>(
        "Check for Repeating Numbers with Mixed Input", 
        &LotteryTests::checkForRepeatingNumbersMixedInput));
    
    suit->addTest(new CppUnit::TestCaller<LotteryTests>(
        "Check for Repeating Numbers with Invalid Input", 
        &LotteryTests::checkForRepeatingNumbersInvalidInput));

    return suit;
}

// Sets up each test.
// ----------------------------------------------------------------------------
void LotteryTests::setUp()
{
    // Creates the test input.
	m_input = new TestInput();

	// Creates a new lottery object and initialises it with the test input.
	m_lottery = new Lottery();
	m_lottery->setInput(m_input);
}

// Cleans up each test.
// ----------------------------------------------------------------------------
void LotteryTests::tearDown()
{
    delete m_lottery;
	delete m_input;
}

// ----------------------------------------------------------------------------
void LotteryTests::checkForSixNumbers()
{
	// Initialises the test input with valid values.
	m_input->setReturnValues({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

	// Checks that the size is equal to 6.
	CPPUNIT_ASSERT(m_lottery->getNumbers().size() == 6);
	CPPUNIT_ASSERT(m_lottery->isValid() == true);
}

// ----------------------------------------------------------------------------
void LotteryTests::checkForSixNumbersMixedInput()
{
    // Initialises the test input with 6 valid values and some junk values.
	m_input->setReturnValues({ 1, -5, 2, 0, 4, 100, 8, 420, 7, 9 });

	// Checks that the size is equal to 6.
	CPPUNIT_ASSERT(m_lottery->getNumbers().size() == 6);
	CPPUNIT_ASSERT(m_lottery->isValid() == true);
}

// ----------------------------------------------------------------------------
void LotteryTests::checkForSixNumbersInvalidInput()
{
    // Initialises the test input with less than 6 values.
	m_input->setReturnValues({ 1, 2, 3 });

	// Checks that the size is equal to 3.
	CPPUNIT_ASSERT(m_lottery->getNumbers().size() == 3);
	CPPUNIT_ASSERT(m_lottery->isValid() == false);
}

// ----------------------------------------------------------------------------
void LotteryTests::checkNumberRange()
{
    // Initialises the test input with 6 valid values.
	m_input->setReturnValues({ 2, 1, 4, 5, 7, 6 });

	// Gets the lotto numbers.
	std::vector<int> numbers = m_lottery->getNumbers();

	// Asserts that all returned numbers are within the correct range.
	for (int number : numbers)
		CPPUNIT_ASSERT(number >= 0 && number <= 46);
    
	CPPUNIT_ASSERT(m_lottery->isValid() == true);
}

// ----------------------------------------------------------------------------
void LotteryTests::checkNumberRangeMixedInput()
{
    // Initialises the test input with 6 valid values and some junk values.
	m_input->setReturnValues({ -5, 2, 0, 4, 100, 420, 7, 8, 9, 10 });

	// Gets the lotto numbers.
	std::vector<int> numbers = m_lottery->getNumbers();

	// Asserts that all returned numbers are within the correct range.
	for (int number : numbers)
		CPPUNIT_ASSERT(number >= 0 && number <= 46);
    
	CPPUNIT_ASSERT(m_lottery->isValid() == true);
}

// ----------------------------------------------------------------------------
void LotteryTests::checkNumberRangeInvalidInput()
{
    // Initialises the test input with less than 6 valid values.
	m_input->setReturnValues({ -5, 2, 0, 100, 420, 7 });

	// Gets the lotto numbers.
	std::vector<int> numbers = m_lottery->getNumbers();

	// Asserts that all returned numbers are within the correct range.
	for (int number : numbers)
		CPPUNIT_ASSERT(number >= 0 && number <= 46);
    
	CPPUNIT_ASSERT(m_lottery->isValid() == false);
}

// ----------------------------------------------------------------------------
void LotteryTests::checkForRepeatingNumbers()
{
    // Initialises the test input with 6 valid values.
	m_input->setReturnValues({ 1, 10, 4, 7, 40, 34 });

	// Gets the lotto numbers.
	std::vector<int> numbers = m_lottery->getNumbers();

	// Asserts that all returned numbers are unique.
	std::set<int> checkedNumbers;
	for (int number : numbers)
	{
		// Adds the number to the set and check that the size increased.
		// Sets can only have one of each number, if a duplicate is added, the 
		//		size will not increase.
		size_t numCheckedNumbers = checkedNumbers.size();
		checkedNumbers.insert(number);
		CPPUNIT_ASSERT(numCheckedNumbers + 1 == checkedNumbers.size());
	}

	CPPUNIT_ASSERT(m_lottery->isValid() == true);
}

// ----------------------------------------------------------------------------
void LotteryTests::checkForRepeatingNumbersMixedInput()
{
    // Initialises the test input with 6 valid values + duplicates.
	m_input->setReturnValues({ 1, 1, 1, 10, 4, 4, 7, 40, 34, 40, 9, 10 });

	// Gets the lotto numbers.
	std::vector<int> numbers = m_lottery->getNumbers();

	// Asserts that all returned numbers are unique.
	std::set<int> checkedNumbers;
	for (int number : numbers)
	{
		// Adds the number to the set and check that the size increased.
		size_t numCheckedNumbers = checkedNumbers.size();
		checkedNumbers.insert(number);
		CPPUNIT_ASSERT(numCheckedNumbers + 1 == checkedNumbers.size());
	}

	CPPUNIT_ASSERT(m_lottery->isValid() == true);
}

// ----------------------------------------------------------------------------
void LotteryTests::checkForRepeatingNumbersInvalidInput()
{
    // Initialises the test input with less than 6 unique values.
	m_input->setReturnValues({ 1, 1, 1, 10, 4, 4, 7, 40 });

	// Gets the lotto numbers.
	std::vector<int> numbers = m_lottery->getNumbers();

	// Asserts that all returned numbers are unique.
	std::set<int> checkedNumbers;
	for (int number : numbers)
	{
		// Adds the number to the set and check that the size increased.
		size_t numCheckedNumbers = checkedNumbers.size();
		checkedNumbers.insert(number);
		CPPUNIT_ASSERT(numCheckedNumbers + 1 == checkedNumbers.size());
	}

	CPPUNIT_ASSERT(m_lottery->isValid() == false);
}

// ----------------------------------------------------------------------------