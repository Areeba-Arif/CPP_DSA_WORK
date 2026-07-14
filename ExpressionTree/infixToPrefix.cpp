#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to return precedence
int precedence(string opr)
{
    if (opr == "*" || opr == "/" || opr == "%") return 5;
    if (opr == "+" || opr == "-") return 4;
    if (opr == "<" || opr == ">" || opr == "<=" || opr == ">=" ||
        opr == "==" || opr == "!=") return 3;
    if (opr == "&&") return 2;
    if (opr == "||") return 1;
    return 0;
}

// Reverse infix and swap brackets
string reverseExpression(string exp)
{
    reverse(exp.begin(), exp.end());

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }

    return exp;
}

// Infix to Postfix
string infixToPostfix(string infix)
{
    stack<string> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
    char c = infix[i];
    if (c == ' ') continue; // skip spaces if you allow them

    if (c == '(') {
        s.push("(");
    }
    else if (c == ')') {
        while (!s.empty() && s.top() != "(") {
            postfix += s.top() + " ";
            s.pop();
        }
        if (!s.empty()) s.pop();
    }
    else if (precedence(string(1, c)) > 0 ||
         c == '!' || c == '&' || c == '|') {
        string op(1, c);        //string op = string(1, c);
        if (i + 1 < infix.length()) {
            string two = infix.substr(i, 2);  //substr(start, length)
            if (two=="<="||two==">="||two=="=="||two=="!="||two=="&&"||two=="||") {
                op = two;
                i++;
            }
        }
        while (!s.empty() && s.top() != "(" && precedence(s.top()) > precedence(op)) {
            postfix += s.top() + " ";
            s.pop();
        }
        s.push(op);
    }
    else {
        postfix += c; // part of operand
        postfix += " "; // add space after operand
    }
}

while (!s.empty())
{
    postfix += s.top() + " ";
    s.pop();
}
    return postfix;
}


// Reverse postfix tokens
string reversePostfix(string postfix)
{
    vector<string> tokens;
    string temp = "";

    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == ' ')
        {
            if (!temp.empty())
            {
                tokens.push_back(temp);
                temp = "";
            }
        }
        else
        {
            temp += postfix[i];
        }
    }

    if (!temp.empty())
        tokens.push_back(temp);

    reverse(tokens.begin(), tokens.end());

    string prefix = "";

    for (string t : tokens)
        prefix += t + " ";

    return prefix;
}

// Infix to Prefix
string infixToPrefix(string infix)
{
    string rev = reverseExpression(infix);

    string postfix = infixToPostfix(rev);

    string prefix = reversePostfix(postfix);

    return prefix;
}

int main()
{
    string infix;

    cout << "Enter Expression: ";
    cin >> infix;

    cout << "\nPrefix : " << infixToPrefix(infix);

    return 0;
}