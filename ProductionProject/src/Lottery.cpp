#include "Lottery.h"

Lottery::Lottery() :
	m_input{ nullptr },
	m_output{ nullptr }
{
}

void Lottery::setInput(Input * t_input)
{
	m_input = t_input;
}

void Lottery::setOutput(Output* t_output)
{
	m_output = t_output;
}

std::vector<int> Lottery::getNumbers()
{
	std::vector<int> numbers;

	if (m_input)
	{
		std::set<int> validNumbers;
		m_valid = true;

		while (validNumbers.size() < 6)
		{
			// Prompts for a number and takes an input.
			print("Please enter a number between 1 and 46: ");
			int number = m_input->getInt();

			// Breaks if the inputted number is negative one.
			if (number == -1)
			{
				m_valid = false;
				print("\"-1\" Recieved, input cancelled.\n");
				break;
			}

			// If the number is within an acceptable range, adds it to the numbers.
			else if (number >= 1 && number <= 46)
			{
				int size = validNumbers.size();
				validNumbers.insert(number);

				// If the number is a duplicate, displays an error.
				if (validNumbers.size() == size)
					print("Duplicate number.\n");
			}

			// If the number is outside the range, displays an error.
			else print("Invalid number.\n");
		}

		// Adds all the valid numbers to the vector.
		for (int number : validNumbers)
			numbers.push_back(number);
	}

	return numbers;
}

bool Lottery::isValid() const
{
	return m_valid;
}

void Lottery::print(std::string const & t_string)
{
	if(m_output) 
		m_output->print(t_string);
}
