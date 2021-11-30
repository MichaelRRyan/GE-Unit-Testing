#include <iostream>
#include <vector>

#include "Lottery.h"
#include "CmdInput.h"

int main()
{
	// Creates and sets up the input and lottery.
	CmdInput input;
	Lottery lottery;
	lottery.setInput(&input);

	// Gets and prints the lotto numbers.
	std::vector<int> numbers = lottery.getNumbers();
	std::cout << "The lotto numbers are: ";
	for (int number : numbers)
		std::cout << number << " ";

	// Pauses for input.
	std::cin.get();

	return 0;
}
