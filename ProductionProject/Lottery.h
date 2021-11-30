#ifndef LOTTERY_H
#define LOTTERY_H

#include <vector>
#include "Input.h"

class Lottery
{
public:

	void setInput(Input * t_input);

	std::vector<int> getNumbers() const;

};

#endif // !LOTTERY_H
