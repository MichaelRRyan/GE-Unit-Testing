#include <iostream>
#include <assert.h>
#include <set>

#include "Lottery.h"
#include "TestInput.h"

using namespace std;

// ----------------------------------------------------------------------------

void runTest(void (*t_func)(), std::string const & t_testName);

void setup();
void teardown();

void checkForSixNumbers();
void checkNumberRange();
void checkForRepeatingNumbers();

// ----------------------------------------------------------------------------

TestInput * input;
Lottery * lottery;

// ----------------------------------------------------------------------------

int main()
{
	// Run the tests.
	runTest(&checkForSixNumbers, "Check for Six Numbers");
	runTest(&checkNumberRange, "Check Number Range");
	runTest(&checkForRepeatingNumbers, "Check for Repeating Numbers");

	std::cout << "All tests passed.";

	std::cout << "\n\nPress enter to exit...";
	cin.get();

	return 0;
}

// ----------------------------------------------------------------------------

void runTest(void(*t_func)(), std::string const& t_testName)
{
	std::cout << "- " << t_testName;
	setup();
	t_func();
	teardown();
	std::cout << " - Test Passed.\n";
}

// Sets up each test.
void setup()
{
	// Creates the test input.
	input = new TestInput();

	// Creates a new lottery object and initialises it with the test input.
	lottery = new Lottery();
	lottery->setInput(input);
}

// Cleans up each test.
void teardown()
{
	delete lottery;
	delete input;
}

// ----------------------------------------------------------------------------

void checkForSixNumbers()
{
	// GOOD INPUT TEST.

	// Initialises the test input with valid values.
	input->setReturnValues({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

	// Checks that the size is equal to 6.
	assert(lottery->getNumbers().size() == 6);

	// MIXED INPUT TEST.

	// Initialises the test input with 6 valid values and some junk values.
	input->clearReturnValues();
	input->setReturnValues({ -5, 2, 0, 4, 100, 420, 7, 8, 9, 10 });

	// Checks that the size is equal to 6.
	assert(lottery->getNumbers().size() == 6);
}

void checkNumberRange()
{
	// Initialises the test input with 6 valid values and some junk values.
	input->setReturnValues({ -5, 2, 0, 4, 100, 420, 7, 8, 9, 10 });

	// Gets the lotto numbers.
	std::vector<int> numbers = lottery->getNumbers();

	// Asserts that all returned numbers are within the correct range.
	for (int number : numbers)
		assert(number >= 0 && number <= 46);
}

void checkForRepeatingNumbers()
{
	// Initialises the test input with 6 valid values + duplicates.
	input->setReturnValues({ 1, 1, 1, 10, 4, 4, 7, 40, 34, 40, 9, 10 });

	// Gets the lotto numbers.
	std::vector<int> numbers = lottery->getNumbers();

	// Asserts that all returned numbers are unique.
	std::set<int> checkedNumbers;
	for (int number : numbers)
	{
		// Adds the number to the set and check that the size increased.
		// Sets can only have one of each number, if a duplicate is added, the 
		//		size will not increase.
		size_t numCheckedNumbers = checkedNumbers.size();
		checkedNumbers.insert(number);
		assert(numCheckedNumbers + 1 == checkedNumbers.size());
	}
}

// ----------------------------------------------------------------------------