#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include "shell.h"

using namespace std;

class Command: public Shell
{
    private:
        vector<string> commands;

    public:
        Command(string c)
        {
            cout << "Adding to command vector..." << endl;
            commands.push_back(c);

        };

        void execute(){};
};

#endif
