# TxtToCpp
# About
This is a *C++* project I am making. It makes incorporating **.txt** files into a C++ project so much *easier* than ever before. You can *read* certain values from a text file, you can also *write* certain values to a text file aswell.  
Obviously, that is not *everything* in the project / library. If you want to look at ***all*** of the features, there is a file called *docs.txt* inside of the project. You can open that file and read all of the features there. *or* you could scroll down to the *features* section in this file.
___
## How to install
Here is a *list* of steps to do on how to install the project.  
  
1. Download the project
you need to hit the green **code** button and download the project as a *.zip* file.  
1. Open the project
next, open up the file and go into the *src* folder and copy and paste all of the files into your own project.  
1. Include the files
then, you need to include the ***includes.h*** file inside of your main project file. *or* you could use the *template.cpp* file and everything will be included.  
1. Use the code
finally, you can start coding! If you need help, you can visit the *docs.txt* file inside the *help* folder. Have fun!
___
## Example use case
Okay, so let's say that you have some sort of application and there is a *settings* menu. You could use this project / library to ***save*** the user's settings and ***load*** those settings when you reatart the application.  
Normally, this would take a while to just read and write those settings, *but* with txtToCpp, it could be done *very easily*.
___
# **Docs**
TxtToCpp is the *best* library for incorparating **.txt** files into your **C++** project.
___
## Installation
Firstly, to install TxtToCpp, you need to download the library. In *Github*, you need to hit the green ***code*** button and hit ***download as zip***. Then you have sucsessfully installed the library.  
If you want to include this into your own project, you need to copy and paste the files in the *"src"* folder. Then type this:
```cpp
#include "TxtToCpp.h"
```
Then you can start coding!
___
## **Usage**
To use TxtToCpp, there are a lot of different function that you can use. Luckily, I will show you guys here all of the functions in TxtToCpp.
___
```c++
txtcpp::writeText(std::string filename, std::string text);
```
This function allows you to *write text* to a file. First, you put in the name of the file you want to write to. Then, you put in the text you want to write.
___
```c++
txtcpp::replaceText(std::string filename, std::string searchText, std::string replaceText);
```
This function allows you to replace text in a file with other text. The first paramater is the filename, the second is the text you want. to replace, and the third is the text you want to replace it with.
___
```c++
txtcpp::readFile(std::string filename, const char* commentSymbol, bool includeComments);
```
This function allows you to read the file to the console. The first paramater is the filename, the second is the symbol that you want to be the comment in the text file. The third is a *true* or *false* paramater that you can tell the program to read the comments or not.
___
```c++
txtcpp::replaceCommentSymbolInFile(string filename, const char* oldSymbol, const char* newSymbol);
```
This function allows you to replace a comment symbol in a file. It looks at the first character on each line. The first paramater is the filename, the next one is the symbol you want to look for. The last one is the symbol you want to replace it with. Remember that the *oldSymbol* and *newSymbol* are *const char*s. That means you have to put the character inside of '**single quotes**'.
___
```c++
txtcpp::getIntValue(string fileName, string search, int& value, bool skipComments, char commentSymbol);   

txtcpp::getDoubleValue(string fileName, string search, double& value, bool skipComments, char commentSymbol);   
 
txtcpp::getBoolValue(string fileName, string search, bool& value, bool skipComments, char commentSymbol);   

txtcpp::getStringValue(string fileName, string search, string& value, bool skipComments, char commentSymbol);   

txtcpp::getCharValue(string fileName, string search, char& value, bool skipComments, char commentSymbol);   
```
These functions allow you to *search for certian pices of text* inside of a *.txt* file. You could *search for certain values* inside of that text file, this is helpfull because for example you could have a settings.txt file for an application and you could *look for those values*. I think the paramaters are pretty self explanitory.
