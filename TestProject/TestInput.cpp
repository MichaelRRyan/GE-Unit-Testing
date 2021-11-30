#include "TestInput.h"

void TestInput::setReturnValues(std::initializer_list<int> const& t_returnValues)
{
	for (int value : t_returnValues)
		m_returnValues.push_back(value);
}

int TestInput::getInt()
{
	if (m_returnValues.empty()) return -1;

	int value = m_returnValues.back();
	m_returnValues.pop_back();
	return value;
}
