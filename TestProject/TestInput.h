#ifndef TEST_INPUT_H
#define TEST_INPUT_H

#include <vector>
#include "../ProductionProject/Input.h"

class TestInput : public Input
{
public:

	void clearReturnValues();

	void setReturnValues(std::initializer_list<int> const & t_returnValues);

	virtual int getInt() override;

private:

	std::vector<int> m_returnValues;

};

#endif // !TEST_INPUT_H