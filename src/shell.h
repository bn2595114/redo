/* This is our Shell base class, the only thing the user will interact with*/

#ifndef SHELL_H
#define SHELL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shell
{
    protected:
        string userInput;

    public:
        /*Constructor*/
        Shell();

        // string userPrompt();

        // string getString()
        // {
        //     return userInput;
        // };

        virtual void execute() = 0;

};

#endif
