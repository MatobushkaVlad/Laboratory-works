#pragma once
#include <iostream>
#include "JAVA.hpp"
#include "PHP.hpp"
#include "C-PLUS-PLUS.hpp"
#include "CodeGenerator.hpp"

CodeGenerator* generateCode(Lang _language)
{
    CodeGenerator* shift = nullptr;

    switch (_language) 
{
    case Java: 
    {
        shift = new JAVA(_language);
        shift->someCodeRelatedThing();      //return generated java code
        return shift;
    }

    case C_plus_plus: 
    {
        shift = new C_PLUS_PLUS(_language);
        shift->someCodeRelatedThing();      //return generated C++ code
        return shift;
    }

    case Php: 
    {
        shift = new PHP(_language);
        shift->someCodeRelatedThing();      //return generated PHP code
        return shift;   
    }
}

}