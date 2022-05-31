#pragma once
#include <iostream>

enum Lang { Java = 0, C_plus_plus = 1, Php = 2 };

//Базовый, родительский класс
class CodeGenerator
{
public:
	CodeGenerator(Lang _language)
	{
		 m_language = _language;
	}

	virtual ~CodeGenerator()
	{

	}

	virtual std::string someCodeRelatedThing() = 0;

protected:

	Lang m_language;

};
