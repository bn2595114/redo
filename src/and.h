//and class
#ifndef AND_H
#define AND_H

#include <iostream>
#include <string>
#include <vector>
#include "shell.h"

using namespace std;

class And: public Shell
{
    public:
        
    vector<string> parser();

};

#endif
