#ifndef LOTTERY_H
#define LOTTERY_H

#include <set>
#include "Input.h"

class Lottery
{
public:

	void setInput(Input const * t_input);

	std::set<int> getNumbers() const;

};

#endif // !LOTTERY_H
