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
    private:
        Shell* orLeft;
        Shell* orRight;

    public:
        Or(Shell* leftChild, Shell* rightChild)
        {
            orLeft = leftChild;
            orRight = rightChild;
        }

        void print()
        {
            // cout << "Left Child = " << semiLeft << endl;
            // cout << "Right Child = " << semiRight << endl;
        }

        void execute(){};
};

#endif
