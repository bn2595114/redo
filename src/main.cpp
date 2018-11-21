//This is just to test as we go along.

#include <iostream>
#include <vector>
#include "command.h"
#include "semi.h"
// #include "shell.h"
// #include "connector.h"
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_iterator.hpp>

using namespace std;
using namespace boost;

string userPrompt()
{
    string userInput;

    char hostName[1024];
    gethostname(hostName, 1023);
    if (!hostName)
    {
        perror("gethostname error");
    }

    char userName[1024];
    getlogin_r(userName, 1023);
    if (!userName)
    {
        perror("getusername error");
    }

    cout << userName << "@" << hostName << "$ ";

    getline(cin, userInput);

    return userInput;
};

vector<string> parser(string passedInput)
{
    vector<string> parsedVector;

    string userInput = passedInput;

    typedef boost::tokenizer<boost::char_separator<char>> Tok;
    boost::char_separator<char> conn("", ";#&&||");
    Tok connector(userInput, conn);

    for (Tok::iterator tok_iter = connector.begin(); tok_iter != connector.end(); tok_iter++)
    {
        if (tok_iter == connector.end())
        {
            return parsedVector;
        }

        if (*tok_iter == " ")
        {
            tok_iter++;
        }

        for (int a = 0; a < 2; a++)
        {
            if (*tok_iter == "&")
            {
                a++;
                if (tok_iter != connector.end())
                {
                    tok_iter++;
                    if (*tok_iter == "&")
                    {
                        parsedVector.push_back("&&");
                        a++;
                    }
                }
            }
        }

        for (int b = 0; b < 2; b++)
        {
            if (*tok_iter == "|")
            {
                b++;
                if (tok_iter != connector.end())
                {
                    tok_iter++;
                    if (*tok_iter == "|")
                    {
                        parsedVector.push_back("||");
                        b++;
                    }
                }
            }
        }

        if (*tok_iter != "|" && *tok_iter != "&")
        {
            parsedVector.push_back(*tok_iter);
        }
    }

    return parsedVector;
};

void checkConnectors(vector<string> passedVector)
{
    vector<string> parsedVector = passedVector;

    string semiConnector = ";";
    string andConnector = "&&";
    string orConnector = "||";

    for(int i = 0; i < parsedVector.size() ; ++i)
    {
        if(parsedVector[i] == semiConnector)
        {
            cout << "Found semicolon" << endl;
            Command* leftChild = new Command(parsedVector[i-1]);
            Command* rightChild = new Command(parsedVector[i+1]);
            Semi* Tree = new Semi(leftChild, rightChild);
            Tree->print();
        }

        if(parsedVector[i] == andConnector)
        {
            cout << "Found and" << endl;
            // Command* leftChild == parsedVector[i-1];
            // Command* rightChild == parsedVector[i+1];
            // And* Tree = new And(leftChild, rightChild);
        }

        if(parsedVector[i] == orConnector)
        {
            cout << "Found or" << endl;
            // Command* leftChild == parsedVector[i-1];
            // Command* rightChild == parsedVector[i+1];
            // Or* Tree = new Or(leftChild, rightChild);
        }

        if (parsedVector[i] != semiConnector && parsedVector[i] != andConnector
            && parsedVector[i] != orConnector)
        {
            cout << "Found command" << endl;
            string toPass = parsedVector[i];
            Command* command = new Command(toPass);
        }
    }
};


void print(vector<string> passedVector)
{
    vector<string> parsedVector = passedVector;

    cout << "PARSED VECTOR: ";

    for(int i = 0; i < parsedVector.size(); i++)
    {
        cout << "Index: " << i  << " " << parsedVector[i] << " " << endl;
    }

    cout << "Vector size " << parsedVector.size() << endl;
};


int main()
{
    string userInput;
    vector<string> parsedVector;

    userInput = userPrompt(); //Input line
    parsedVector = parser(userInput); //Parse line

    checkConnectors(parsedVector);

    return 0;
};