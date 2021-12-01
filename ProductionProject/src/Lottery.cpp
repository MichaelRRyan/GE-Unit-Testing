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

std::vector<int> Lottery::getNumbers() const
{
	std::vector<int> numbers;

	if (m_input)
	{
		std::set<int> validNumbers;

		while (validNumbers.size() < 6)
		{
			// Prompts for a number and takes an input.
			if (m_output) m_output->print("Please enter a number between 1 and 46: ");
			int number = m_input->getInt();

			// If the number is within an acceptable range, adds it to the numbers.
			if (number >= 1 && number <= 46)
			{
				int size = validNumbers.size();
				validNumbers.insert(number);

				// If the number is a duplicate, displays an error.
				if (validNumbers.size() == size && m_output)
					m_output->print("Duplicate number.\n");
			}
			// If the number is outside the range, displays an error.
			else if(m_output) 
				m_output->print("Invalid number.\n");
		}

		// Adds all the valid numbers to the vector.
		for (int number : validNumbers)
			numbers.push_back(number);
	}

	return numbers;
}