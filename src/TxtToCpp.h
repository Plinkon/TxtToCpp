#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>

namespace txtcpp {
    void writeText(std::string filename, std::string text);
    void replaceText(std::string filename, std::string searchText, std::string replaceText);
    void replaceCommentSymbolInFile(std::string filename, const char* oldSymbol, const char* newSymbol);
    void readFile(std::string filename, const char* commentSymbol, bool includeComments);
    bool getBoolValue(std::string filename, std::string search, bool& value, bool skipComments, char commentSymbol);
    bool getCharValue(std::string fileName, std::string search, char& value, bool skipComments, char commentSymbol);
    bool getIntValue(std::string filename, std::string search, int& value, bool skipComments, char commentSymbol);
    bool getDoubleValue(std::string filename, std::string key, double& value, bool skipComments, char commentSymbol);
    bool getStringValue(std::string filename, std::string key, std::string& value, bool skipComments, char commentSymbol);
}

#endif
