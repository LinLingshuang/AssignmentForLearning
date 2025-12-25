#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> sta;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (!sta.empty())
        {
            if ((sta.top() == '(' && str[i] == ')') ||
                (sta.top() == '[' && str[i] == ']') ||
                (sta.top() == '{' && str[i] == '}'))
            {
                sta.pop();
            }
            else
            {
                sta.push(str[i]);
            }
        }
        else
        {
            sta.push(str[i]);
        }
    }



    if (sta.empty())
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }
}