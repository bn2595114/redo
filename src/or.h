//or class
#ifndef OR_H
#define OR_H

#include <iostream>
#include <string>
#include <vector>
#include "shell.h"

using namespace std;

class Or: public Shell
{
    public:
        
    vector<string> parser();
};

#endif
