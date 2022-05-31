Дан класс, который умеет генерировать код на разных языках. Предложите рефакторинг кода с учетом того, что количество языков будет расширяться.

class CodeGenerator
{
public:
    enum Lang {JAVA = 0, C_PLUS_PLUS = 1, PHP = 2};
    CodeGenerator(Lang language) { _language=language; }
    std::string generateCode()
    {
        switch(_language) {
        case JAVA: someCodeRelatedThing();       //return generated java code
        case C_PLUS_PLUS: someCodeRelatedThing();//return generated C++ code
        case PHP: someCodeRelatedThing();         //return generated PHP code
        }
        throw new std::logic_error("Bad language");
    }
    std::string someCodeRelatedThing() // used in generateCode()
    {
        switch(_language) {
        case JAVA: return “CPP code”;        //return generated java-related stuff
        case C_PLUS_PLUS: //return generated C++-related stuff
        case PHP:         //return generated PHP-related stuff
        }
        throw new std::logic_error("Bad language");
    }

private:
    Lang _language;
}

