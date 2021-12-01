#ifndef LOTTERY_H
#define LOTTERY_H

#include <vector>
#include <set>
#include "Input.h"
#include "Output.h"

class Lottery
{
public:

	Lottery();

	void setInput(Input* t_input);
	void setOutput(Output* t_output);

	std::vector<int> getNumbers();

	bool isValid() const;

private:

	Input * m_input;
	Output * m_output;
	bool m_valid;

};

#endif // !LOTTERY_H
