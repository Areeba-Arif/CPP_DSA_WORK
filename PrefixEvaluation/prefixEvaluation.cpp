#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// Function to return precedence
int precedence(char opr)
{
    switch(opr)
    {
        case '*':
        case '/':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}

// Check if character is operator
bool isOperator(char c)
{
    return c=='+' || c=='-' || c=='*' || c=='/';
}

// Reverse expression and swap brackets
string reverseExpression(string exp)
{
    reverse(exp.begin(), exp.end());

    for(int i=0; i<exp.length(); i++)
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
    }

    return exp;
}

// Infix to Postfix
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix="";

    for(int i=0; i<infix.length(); i++)
    {
        char c=infix[i];

        if(c==' ')
            continue;

        if(c=='(')
        {
            s.push(c);
        }
        else if(c==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }

            if(!s.empty())
                s.pop();
        }
        else if(isOperator(c))
        {
            while(!s.empty() && precedence(s.top())>precedence(c))
            {
                postfix+=s.top();
                s.pop();
            }

            s.push(c);
        }
        else
        {
            postfix+=c;
        }
    }

    while(!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }

    return postfix;
}

// Infix to Prefix
string infixToPrefix(string infix)
{
    string rev = reverseExpression(infix);

    string postfix = infixToPostfix(rev);

    reverse(postfix.begin(), postfix.end());

    return postfix;
}

// Prefix Evaluation
double evaluatePrefix(string prefix)
{
    stack<double> s;

    for(int i=prefix.length()-1; i>=0; i--)
    {
        char currChar=prefix[i];

        if(currChar==' ')
            continue;

        if(currChar>='0' && currChar<='9')
        {
            s.push(currChar-'0');
        }
        else if(isOperator(currChar))
        {
            double value1=s.top();
            s.pop();

            double value2=s.top();
            s.pop();

            switch(currChar)
            {
                case '+':
                    s.push(value1+value2);
                    break;

                case '-':
                    s.push(value1-value2);
                    break;

                case '*':
                    s.push(value1*value2);
                    break;

                case '/':
                    s.push(value1/value2);
                    break;
            }
        }
    }

    return s.top();
}

int main()
{
    string infix;

    cout<<"Enter Infix Expression: ";
    getline(cin,infix);

    string prefix=infixToPrefix(infix);

    cout<<"Prefix Expression: "<<prefix<<endl;

    double result=evaluatePrefix(prefix);

    cout<<"Evaluation Result: "<<result<<endl;

    return 0;
}