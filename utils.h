#include <iostream>
#include <vector>
#include <string>
using namespace std;

int addition(int a, int b)
{
    return a + b;
}
vector<string> splitCode(const string& str, int splitLength)
{
   int NumSubstrings = str.length() / splitLength;
   vector<string> ret;

   for (auto i = 0; i < NumSubstrings; i++)
   {
        ret.push_back(str.substr(i * splitLength, splitLength));
   }
   // If there are leftover characters, create a shorter item at the end.
   if (str.length() % splitLength != 0)
   {
        ret.push_back(str.substr(splitLength * NumSubstrings));
   }
   return ret;
}
string clean(const string& data) // cleans out the code
{
    string checkCode = data;
    string cleanedCode = "";
    for (char& c: checkCode)
    {
        if (c == '0' || c == '1')
        {
            cleanedCode = cleanedCode + c;
        }
    }
    return cleanedCode;
}
string removeHeader(const string& data)
{
    string code = data.substr(data.find("0101111") + 7);
    if (code.length() % 3 != 0)
    {
        code = "N";
    }
    return code;
}
bool checkBrackets(vector<string>& tokens) 
{
    int num = 0;
    int code_pos = 0;
    while (code_pos < tokens.size())
    {
        if (tokens[code_pos] == "OPENLOOP" || tokens[code_pos] == "OPENBLOCK")
        {
            num++;
        }
        else if (tokens[code_pos] == "CLOSELOOP" || tokens[code_pos] == "CLOSEBLOCK")
        {
            num--;
        }
        code_pos++;
    }
    return num == 0;
}
vector<string> tokenize(string data)
{
    // time to tokenize the data
    vector<string> tokens;
    vector<string> code = splitCode(data, 3);
    bool isCommand = false;
    string whichCommand = "stack";
    for (size_t i = 0; i < code.size(); ++i)
    {
        string com = code[i];
        if (isCommand)
        {
            isCommand = false;
            if (whichCommand == "stack")
            {
                if (com == "111")
                {
                    tokens.push_back("ADDSTACK");
                }
                else if (com == "011")
                {
                    tokens.push_back("POP");
                }
                else if (com == "110")
                {
                    tokens.push_back("RETURN");
                }
                else if (com == "010")
                {
                    tokens.push_back("SHIFT");
                }
                else if (com == "101")
                {
                    tokens.push_back("SQU");
                }
                else if (com == "100")
                {
                    tokens.push_back("INCR");
                }
                else if (com == "001")
                {
                    tokens.push_back("DECR");
                }
            }
            else if (whichCommand == "var")
            {
                if (com == "110")
                {
                    tokens.push_back("MIRROR");
                }
                else if (com == "011")
                {
                    tokens.push_back("VARPUSH");
                }
                else if (com == "111")
                {
                    tokens.push_back("INPUT");
                }
            }
            else
            {
                tokens.push_back("IGNORE");
            }
        }
        else
        {
            if (com == "111")
            {
                isCommand = true;
                whichCommand = "stack";
            }
            else if (com == "000")
            {
                isCommand = true;
                whichCommand = "var";
            }
            else if (com == "110")
            {
                tokens.push_back("ADD");
            }
            else if (com == "011")
            {
                tokens.push_back("SUBTR");
            }
            else if (com == "100")
            {
                tokens.push_back("OPENLOOP");
            } 
            else if (com == "001")
            {
                tokens.push_back("CLOSELOOP");
            }
            else if (com == "101")
            {
                tokens.push_back("OPENBLOCK");
            }
            else if (com == "010")
            {
                tokens.push_back("CLOSEBLOCK");
            }
        }
        
    }
    return tokens;
}