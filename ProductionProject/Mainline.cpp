#include <iostream>
#include <limits>
#include <vector>

#include "Lottery.h"
#include "CmdInput.h"
#include "CmdOutput.h"

const auto LineLimit = std::numeric_limits<std::streamsize>::max();

int main()
{
	// Creates and sets up the input, output, and lottery.
	CmdInput input;
	CmdOutput output;
	Lottery lottery;
	lottery.setInput(&input);
	lottery.setOutput(&output);

	// Gets and prints the lotto numbers.
	std::vector<int> numbers = lottery.getNumbers();

	system("cls");
	std::cout << "The lotto numbers are: ";

	for (int number : numbers)
		std::cout << number << " ";

	// Pauses for input.
	std::cout << "\n\nPress enter to exit...";
	std::cin.ignore(LineLimit, '\n');
	std::cin.get();

	return 0;
}
