#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

bool isInt(const string& s) {
    return !s.empty() && s.find_first_not_of("0123456789") == string::npos;
}

bool isDouble(const string& s) {
    if (s.empty()) {
        return false;
    }
    size_t idx;
    stod(s, &idx);
    return idx == s.size();
}

bool isString(const string& s) {
    return true; // a string can be any non-empty sequence of characters
}

bool isBool(const string& s) {
    return s == "true" || s == "false";
}

bool isChar(const string& s) {
    return s.size() == 1;
}

bool toBool(const string& s) {
    return s == "true";
}

char toChar(const string& s) {
    return s[0];
}


namespace txtcpp
{
    
    void writeText(string filename, string text) {
        ofstream outfile(filename, ios::app);
        if (outfile.is_open()) {
            outfile << text << endl;
            outfile.close();
        } else {
            cout << "Error opening file." << endl;
        }
    }

    void replaceText(string filename, string searchText, string replaceText) {
        ifstream infile(filename);
        ofstream outfile("temp.txt");
        string line;
        if (infile.is_open() && outfile.is_open()) {
            while (getline(infile, line)) {
                size_t pos = line.find(searchText);
                if (pos != string::npos) {
                    line.replace(pos, searchText.length(), replaceText);
                }
                outfile << line << endl;
            }
            infile.close();
            outfile.close();
            remove(filename.c_str());
            rename("temp.txt", filename.c_str());
        } else {
            cout << "Error opening file." << endl;
        }
    }

    void readFile(string filename, const char* commentSymbol, bool includeComments) {
    ifstream infile(filename);
    string line;
    if (infile.is_open()) {
        while (getline(infile, line)) {
            if (includeComments || line.find(commentSymbol) != 0) {
                cout << line << endl; // process the line if includeComments is true or if the line doesn't start with the comment symbol
            }
        }
        infile.close();
    } else {
        cout << "Error opening file." << endl;
    }
}

void replaceCommentSymbolInFile(string filename, const char* oldSymbol, const char* newSymbol) {
    ifstream infile(filename);
    ofstream outfile("temp.txt");
    string line;
    if (infile.is_open() && outfile.is_open()) {
        while (getline(infile, line)) {
            if (line.find(oldSymbol) == 0) {
                outfile << newSymbol << line.substr(strlen(oldSymbol)) << endl; // write the new symbol followed by the rest of the line
            } else {
                outfile << line << endl; // write the line as is
            }
        }
        infile.close();
        outfile.close();
        remove(filename.c_str()); // delete the original file
        rename("temp.txt", filename.c_str()); // rename the temporary file to the original filename
    } else {
        cout << "Error opening file." << endl;
    }
}

bool getIntValue(string fileName, string search, int& value, bool skipComments, char commentSymbol) {
    value = -1;
    bool found = false;
    ifstream infile(fileName);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            if (skipComments && line[0] == commentSymbol) {
                continue;
            }
            if (line.find(search) != string::npos) {
                string valueString = line.substr(line.find("=") + 1);
                if (isInt(valueString)) {
                    value = stoi(valueString);
                    found = true;
                    break;
                }
            }
        }
        infile.close();
    } else {
        cout << "Error opening file." << endl;
    }
    return found;
}

bool getDoubleValue(string fileName, string search, double& value, bool skipComments, char commentSymbol) {
    value = -1.0;
    bool found = false;
    ifstream infile(fileName);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            if (skipComments && line[0] == commentSymbol) {
                continue;
            }
            if (line.find(search) != string::npos) {
                string valueString = line.substr(line.find("=") + 1);
                if (isDouble(valueString)) {
                    value = stod(valueString);
                    found = true;
                    break;
                }
            }
        }
        infile.close();
    } else {
        cout << "Error opening file." << endl;
    }
    return found;
}

bool getStringValue(string fileName, string search, string& value, bool skipComments, char commentSymbol) {
    value = "";
    bool found = false;
    ifstream infile(fileName);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            if (skipComments && line[0] == commentSymbol) {
                continue;
            }
            if (line.find(search) != string::npos) {
                string valueString = line.substr(line.find("=") + 1);
                if (isString(valueString)) {
                    value = valueString;
                    found = true;
                    break;
                }
            }
        }
        infile.close();
    } else {
        cout << "Error opening file." << endl;
    }
    return found;
}

bool getBoolValue(string fileName, string search, bool& value, bool skipComments, char commentSymbol) {
    value = false;
    bool found = false;
    ifstream infile(fileName);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            if (skipComments && line[0] == commentSymbol) {
                continue;
            }
            if (line.find(search) != string::npos) {
                string valueString = line.substr(line.find("=") + 1);
                if (isBool(valueString)) {
                    value = toBool(valueString);
                    found = true;
                    break;
                }
            }
        }
        infile.close();
    } else {
        cout << "Error opening file." << endl;
    }
    return found;
}

bool getCharValue(string fileName, string search, char& value, bool skipComments, char commentSymbol) {
    value = '\0';
    bool found = false;
    ifstream infile(fileName);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            if (skipComments && line[0] == commentSymbol) {
                continue;
            }

            if (line.find(search) != string::npos) {
                string valueString = line.substr(line.find("=") + 1);
                if (isChar(valueString)) {
                value = valueString[0];
                found = true;
                break;
                }
            }
        }

    infile.close();
    }

    else {
    cout << "Error opening file." << endl;
    }

    return found;
    }
}
