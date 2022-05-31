#pragma once
#include <iostream>
#include "CodeGenerator.hpp"

//Потомок
class JAVA : public CodeGenerator
{
public:

	JAVA(Lang _language) : CodeGenerator(_language)
	{

	}

	virtual ~JAVA()
	{

	}

	std::string someCodeRelatedThing() override
	{
		return "Java code";        //return generated java-related stuff
	}

};