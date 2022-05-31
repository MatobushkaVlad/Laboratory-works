#pragma once
#include <iostream>
#include "CodeGenerator.hpp"

//Потомок
class PHP : public CodeGenerator
{
public:

	PHP(Lang _language) : CodeGenerator(_language)
	{

	}

	virtual ~PHP()
	{

	}

	std::string someCodeRelatedThing() override
	{
		return "Php code";        //return generated PHP-related stuff
	}

};