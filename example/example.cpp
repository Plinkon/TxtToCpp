#include "TxtToCpp.h"

int main()
{
    std::string filename = "example.txt";
    int intVal;
    std::string strVal;
    bool boolVal;
    char charVal;
    double doubleVal;

    if (txtcpp::getIntValue(filename, "int value", intVal, true, '#'))
    {
        std::cout << "Int value found: " << intVal << "\n";
    }

    if (txtcpp::getDoubleValue(filename, "double value", doubleVal, true, '#'))
    {
        std::cout << "Double value found: " << doubleVal << "\n";
    }

    if (txtcpp::getBoolValue(filename, "bool value", boolVal, true, '#'))
    {
        std::cout << "Bool value found: " << boolVal << "\n";
    }

    if (txtcpp::getCharValue(filename, "char value", charVal, true, '#'))
    {
        std::cout << "Char value found: " << charVal << "\n";
    }

    if (txtcpp::getStringValue(filename, "string value", strVal, true, '#'))
    {
        std::cout << "String value found: " << strVal << "\n";
    }

    txtcpp::replaceCommentSymbolInFile(filename, "$", "#");

    txtcpp::replaceText(filename, "before code ran", "after code ran");

    txtcpp::writeText(filename, "hello, I was written by the code");
}