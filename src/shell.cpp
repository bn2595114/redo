//Definition file for shell

#include <iostream>
#include "shell.h"
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;

Shell::Shell(){};

// string Shell::userPrompt()
// {
//     char hostName[1024];
//     gethostname(hostName, 1023);
//     if (!hostName)
//     {
//         perror("gethostname error");
//     }
//
//     char userName[1024];
//     getlogin_r(userName, 1023);
//     if (!userName)
//     {
//         perror("getusername error");
//     }
//
//     cout << userName << "@" << hostName << "$ ";
//
//     getline(cin, userInput);
//
//     return userInput;
// };
