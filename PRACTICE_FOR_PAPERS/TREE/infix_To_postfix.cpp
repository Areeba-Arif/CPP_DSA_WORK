#include <iostream>
#include <stack>
using namespace std;

int precedence(char opr)
{
    switch(opr)
    {
        case '*' :
        case '/' :
        case '%' :
        {
            return 5;
        } 
        case '+' :
        case '-':
        {
             return 4;
        }
        case '<' :
        case '>' :
        case '=' :
        case '!' :
        {
            return 3;
        }
        case '&':
        {
            return 2;
        }
        case '|' : 
        {
            return 1; 
        }  
        default :
        {
             return 0;
        }     
    }

}

bool isOperator(char c) {
    return precedence(c) > 0;
}


string toPostfix(string infix) {
    string postfix = "";
    stack<char> s;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if(c =='(')
        {
            s.push(c);
        }
        else if(c == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }


            if(!s.empty()){
                s.pop();    //remove ( 
            }
        }

        if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
        else{
            postfix += c;
        }
    }

    //remainning

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}


int main() {

    string infix;
    cout<<"Enter infix notation";
    getline(cin , infix);

    // string infix = "a-b+c/x*y+5";
    string prefix = toPostfix(infix);
    cout<<"Prefix notation : "<<prefix<<endl;


    
    return 0;
}