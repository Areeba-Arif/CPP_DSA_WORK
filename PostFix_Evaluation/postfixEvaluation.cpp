#include <iostream>
#include <stack>
#include <string>

using namespace std;


// ONLY WORK FOR SINGLE DIGIT NUMBERS NOT FOR MUTLIDIGIT


int precedence(char opr) {
    switch(opr) {
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



double evaluatePostfix(string postfix) {
    stack<double> s;

    for (int i = 0; i < postfix.length(); i++) {
        char currChar = postfix[i];

        if (currChar >= '0' && currChar <= '9') {
            s.push(currChar - '0');
        }
        else if (isOperator(currChar)) {
            double value1 = s.top(); s.pop();
            double value2 = s.top(); s.pop();

            switch(currChar) {
                case '+': s.push(value2 + value1); break;
                case '-': s.push(value2 - value1); break;
                case '*': s.push(value2 * value1); break;
                case '/': s.push(value2 / value1); break;
            }
        }
    }

    return s.top();
}




string toPostfix(string infix) {
    string postfix = "";
    stack<char> s;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (c == ' ') continue;

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

        else if(precedence(c) > 0) {
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
    cout << "Enter infix notation (e.g., 3+5*2): ";
    getline(cin, infix);

    string postfix = toPostfix(infix);
    cout << "Postfix notation: " << postfix << endl;

    double result = evaluatePostfix(postfix);
    cout << "Evaluation result: " << result << endl;
    
    return 0;
}
