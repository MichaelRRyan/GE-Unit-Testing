#ifndef CMD_OUTPUT_H
#define CMD_OUTPUT_H

#include <iostream>
#include "Output.h"

class CmdOutput : public Output
{
public: 

	virtual void print(std::string const & t_string) override;

};

#endif // !CMD_OUTPUT_H
