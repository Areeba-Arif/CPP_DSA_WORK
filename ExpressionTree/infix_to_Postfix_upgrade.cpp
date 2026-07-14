#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(string opr) {
    if (opr == "*" || opr == "/" || opr == "%") return 5;
    if (opr == "+" || opr == "-") return 4;
    if (opr == "<" || opr == ">" || opr == "<=" || opr == ">=" || 
        opr == "==" || opr == "!=") return 3;
    if (opr == "&&") return 2;
    if (opr == "||") return 1;
    return 0;
}


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
        while (!s.empty() && s.top() != "(" && precedence(s.top()) >= precedence(op)) {
            postfix += s.top() + " ";
            s.pop();
        }
        s.push(op);
    }
    else {
        postfix += c; // part of operand
    }
}

while (!s.empty())
{
    postfix += s.top() + " ";
    s.pop();
}
    return postfix;
}


int main()
{
    string infix;

    cout << "Enter expression: ";       //a+b/(c+(d-x)*(y+5)*6)*x+y 
    //a*b-c+x*y<a*d-e*f&&c!=x
    cin >> infix;

    cout << "Postfix: " << infixToPostfix(infix);


    return 0;
}