#ifndef CMD_INPUT_H
#define CMD_INPUT_H

#include <iostream>
#include "Input.h"

class CmdInput : public Input
{
public:

	virtual int getInt() override;

};

#endif // !CMD_INPUT_H