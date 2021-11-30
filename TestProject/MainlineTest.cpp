#include <iostream>
#include <assert.h>

#include "../ProductionProject/Production.h"
#include "../ProductionProject/Lottery.h"
#include "TestInput.h"

using namespace std;

// ----------------------------------------------------------------------------

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
	// Check for six numbers.
	setup();
	checkForSixNumbers();
	teardown();

	// Check number range.
	setup();
	checkNumberRange();
	teardown();

	// Check for repeating numbers.
	setup();
	checkForRepeatingNumbers();
	teardown();

	cin.get();
}

// ----------------------------------------------------------------------------

// Sets up each test.
void setup()
{
	// Creates the test input.
	input = new TestInput();

	// Creates a new lottery object and initialises it with the test input.
	Lottery lottery;
	lottery.setInput(input);
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

	// Checks that the size is equal to 6.
	std::vector<int> numbers = lottery->getNumbers();

	// Asserts that all returned numbers are within the correct range.
	for (int number : numbers)
		assert(number >= 0 && number <= 46);
}

void checkForRepeatingNumbers()
{
}

// ----------------------------------------------------------------------------