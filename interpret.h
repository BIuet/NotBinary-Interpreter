#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <list>
using namespace std;

int checkASCII(int num)
{
    int ret = num;
    while (ret < 0 || ret > 255)
    {
        if (ret > 255)
        {
            ret -= 256;
        }
        else if (ret < 0)
        {
            ret += 256;
        }
    }
    return ret;
}
void interpret(const vector<string>& tokens)
{
    int code_pos = 0;
    stack<int> memory;
    list<int> loops{};
    int echo = 0;
    while (code_pos < tokens.size())
    {
        /*cout << "[ "; // DEBUG
        for (int i = 0; i < memory.size(); i++)
        {
            stack<int> temp;
            while (!memory.empty())
            {
                cout << memory.top() << " ";
                temp.push(memory.top());
                memory.pop();
            }
            while (!temp.empty())
            {
                memory.push(temp.top());
                temp.pop();
            }
        }
        cout << "]" << endl;*/
        string tok = tokens[code_pos];
        if (tok == "ADDSTACK")
        {
            memory.push(0);
        }
        else if (tok == "POP")
        {
            int s = memory.top();
            char oChar = '\0' + s;
            memory.pop();
            cout << oChar;
        }
        else if (tok == "RETURN")
        {
            int s = memory.top();
            char oChar = '\0' + s;
            cout << oChar;
        }
        else if (tok == "SHIFT")
        {
            int s = memory.top();
            memory.pop();
            stack<int> tempMemory;
            while (!memory.empty())
            {
                tempMemory.push(memory.top());
                memory.pop();
            }
            memory.push(s);
            while (!tempMemory.empty())
            {
                memory.push(tempMemory.top());
                tempMemory.pop();
            }
        }
        else if (tok == "SQU")
        {
            int s = memory.top();
            memory.pop();
            memory.push(checkASCII(s * s));
        }
        else if (tok == "INCR")
        {
            int s = memory.top();
            memory.pop();
            memory.push(checkASCII(s + 1));
        }
        else if (tok == "DECR")
        {
            int s = memory.top();
            memory.pop();
            memory.push(checkASCII(s - 1));
        }
        else if (tok == "MIRROR")
        {
            echo = memory.top();
        }
        else if (tok == "VARPUSH")
        {
            memory.push(echo);
        }
        else if (tok == "INPUT")
        {
            cin >> echo;
        }
        else if (tok == "ADD")
        {
            int a = memory.top();
            memory.pop();
            int b = memory.top();
            memory.pop();
            memory.push(checkASCII(a + b));
        }
        else if (tok == "SUBTR")
        {
            int a = memory.top();
            memory.pop();
            int b = memory.top();
            memory.pop();
            memory.push(checkASCII(a - b));
        }
        else if (tok == "OPENLOOP")
        {
            loops.push_front(code_pos);
        }
        else if (tok == "CLOSELOOP")
        {
            if (memory.top() != 0 && !memory.empty())
            {
                code_pos = loops.front() - 1;
                loops.pop_front();
            }
        }
        else if (tok == "OPENBLOCK")
        {
            if (memory.top() == 0)
            {
                // get furthest closing block available.
                bool end = false;
                list<int> blocks{};
                while (!end)
                {
                    code_pos++;
                    if (tokens[code_pos] == "OPENBLOCK")
                    {
                        blocks.push_front(code_pos);
                    }
                    else if (tokens[code_pos] == "CLOSEBLOCK")
                    {
                        if (blocks.size() == 0)
                        {
                            end = true;
                        }
                        else
                        {
                            blocks.pop_front();
                        }
                    }
                }
            }
        }
        code_pos++;
    }
}