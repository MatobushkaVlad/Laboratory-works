#pragma once
#include <iostream>
#include "CodeGenerator.hpp"

//Потомок
class C_PLUS_PLUS : public CodeGenerator
{
public:

	C_PLUS_PLUS(Lang _language) : CodeGenerator(_language)
	{

	}

	virtual ~C_PLUS_PLUS()
	{

	}

	std::string someCodeRelatedThing() override
	{
		return "C++ code";        //return generated C++-related stuff
	}

};