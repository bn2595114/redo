//semi class
#ifndef SEMI_H
#define SEMI_H

#include <iostream>
#include <string>
#include <vector>
#include "shell.h"

using namespace std;

class Semi: public Shell
{
    private:
        Shell* semiLeft;
        Shell* semiRight;

    public:
        Semi(Shell* leftChild, Shell* rightChild)
        {
            semiLeft = leftChild;
            semiRight = rightChild;
        }

        void print()
        {
            // cout << "Left Child = " << semiLeft << endl;
            // cout << "Right Child = " << semiRight << endl;
        }

        void execute(){};
};

#endif
