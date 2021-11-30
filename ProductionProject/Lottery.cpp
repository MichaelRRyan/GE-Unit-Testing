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
		while (numbers.size() < 6)
		{
			if (m_output) m_output->print("Please enter a number: ");
			int number = m_input->getInt();
			numbers.push_back(number);
		}
	}

	return numbers;
}
