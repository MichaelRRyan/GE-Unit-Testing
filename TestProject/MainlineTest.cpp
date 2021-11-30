#include <iostream>
#include <assert.h>

#include "../ProductionProject/Production.h"
#include "../ProductionProject/Lottery.h"
#include "TestInput.h"

using namespace std;

void checkForSixNumbers();
void checkNumberRange();
void checkForRepeatingNumbers();

int main()
{
	checkForSixNumbers();
	cin.get();
}

void checkForSixNumbers()
{
	// Creates the test input and initialises it with values.
	TestInput input;
	input.setReturnValues({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

	// Creates a new lottery object and initialises it with the test input.
	Lottery lottery;
	lottery.setInput(&input);

	// Checks that the size is equal to 6.
	assert(lottery.getNumbers().size() == 6);
}

void checkNumberRange()
{
}

void checkForRepeatingNumbers()
{
}
