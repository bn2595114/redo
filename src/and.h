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
    private:
        Shell* andLeft;
        Shell* andRight;

    public:
        And(Shell* leftChild, Shell* rightChild)
        {
            andLeft = leftChild;
            andRight = rightChild;
        }

        void print()
        {
            // cout << "Left Child = " << semiLeft << endl;
            // cout << "Right Child = " << semiRight << endl;
        }

        void execute(){};

};

#endif
