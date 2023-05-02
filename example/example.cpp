#include "includes.h"

int main()
{
    std::string filename = "example.txt";
    int intVal;
    std::string strVal;
    bool boolVal;
    char charVal;

    if (txtcpp::getIntValue(filename, "int value", intVal, true, '#'))
    {
        std::cout << "Int value found: " << intVal << "\n";
    }

    else if (txtcpp::getStringValue(filename, "string value", strVal, true, '#'))
    {
        std::cout << "String value found: " << strVal << "\n";
    }

    else if (txtcpp::getBoolValue(filename, "bool value", boolVal, true, '#'))
    {
        std::cout << "Boolean value found: " << boolVal << "\n";
    }

    else if (txtcpp::getCharValue(filename, "char value", charVal, true, '#'))
    {
        std::cout << "Char value found: " << charVal << "\n";
    }

    //txtcpp::replaceCommentSymbolInFile(filename, "$", "#");

    //txtcpp::replaceText(filename, "before code ran", "after code ran");

    //txtcpp::writeText(filename, "hello, I was written by the code");
}