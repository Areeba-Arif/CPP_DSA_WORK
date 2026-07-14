#include <iostream>
#include <string>
using namespace std;

//---------------------- NODE ----------------------

struct Node
{
    int digit;
    Node* next;
};

//---------------------- INSERT AT END ----------------------

void insert(Node*& head, int d)
{
    Node* temp = new Node;
    temp->digit = d;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }

    Node* p = head;

    while(p->next != NULL)
        p = p->next;

    p->next = temp;
}

//---------------------- CREATE BIG INTEGER ----------------------

Node* createBigInteger(string num)
{
    Node* head = NULL;

    for(int i = num.length()-1; i>=0; i--)
        insert(head, num[i]-'0');

    return head;
}

//---------------------- DISPLAY ----------------------

void display(Node* head)
{
    if(head==NULL)
        return;

    display(head->next);
    cout<<head->digit;
}

//---------------------- ADDITION ----------------------

Node* add(Node* a, Node* b)
{
    Node* result=NULL;

    int carry=0;

    while(a!=NULL || b!=NULL || carry!=0)
    {
        int sum=carry;

        if(a!=NULL)
        {
            sum+=a->digit;
            a=a->next;
        }

        if(b!=NULL)
        {
            sum+=b->digit;
            b=b->next;
        }

        insert(result,sum%10);

        carry=sum/10;
    }

    return result;
}

//---------------------- SUBTRACTION ----------------------
// Assumption : First number >= Second number

Node* subtract(Node* a, Node* b)
{
    Node* result=NULL;

    int borrow=0;

    while(a!=NULL)
    {
        int diff=a->digit-borrow;

        if(b!=NULL)
        {
            diff-=b->digit;
            b=b->next;
        }

        if(diff<0)
        {
            diff+=10;
            borrow=1;
        }
        else
            borrow=0;

        insert(result,diff);

        a=a->next;
    }

    return result;
}

//---------------------- MULTIPLY BY ONE DIGIT ----------------------

Node* multiplyDigit(Node* num,int digit)
{
    Node* result=NULL;

    int carry=0;

    while(num!=NULL || carry)
    {
        int product=carry;

        if(num!=NULL)
        {
            product+=num->digit*digit;
            num=num->next;
        }

        insert(result,product%10);

        carry=product/10;
    }

    return result;
}

//---------------------- COPY LIST ----------------------

Node* copyList(Node* head)
{
    Node* copy=NULL;

    while(head!=NULL)
    {
        insert(copy,head->digit);
        head=head->next;
    }

    return copy;
}

//---------------------- SHIFT LEFT ----------------------

Node* shift(Node* head,int zeros)
{
    Node* copy=copyList(head);

    while(zeros--)
    {
        Node* temp=new Node;
        temp->digit=0;
        temp->next=copy;
        copy=temp;
    }

    return copy;
}

//---------------------- MULTIPLICATION ----------------------

Node* multiply(Node* num1,Node* num2)
{
    Node* answer=NULL;

    int position=0;

    while(num2!=NULL)
    {
        Node* temp=multiplyDigit(num1,num2->digit);

        temp=shift(temp,position);

        if(answer==NULL)
            answer=temp;
        else
            answer=add(answer,temp);

        position++;

        num2=num2->next;
    }

    return answer;
}

//---------------------- MAIN ----------------------

int main()
{
    string n1,n2;

    cout<<"Enter First Big Integer : ";
    cin>>n1;

    cout<<"Enter Second Big Integer : ";
    cin>>n2;

    Node* num1=createBigInteger(n1);
    Node* num2=createBigInteger(n2);

    cout<<"\nFirst Number  : ";
    display(num1);

    cout<<"\nSecond Number : ";
    display(num2);

    Node* sum=add(num1,num2);

    cout<<"\nAddition      : ";
    display(sum);

    cout<<endl;

    Node* sub=subtract(num1,num2);

    cout<<"Subtraction   : ";
    display(sub);

    cout<<endl;

    Node* mul=multiply(num1,num2);

    cout<<"Multiplication: ";
    display(mul);

    cout<<endl;

    return 0;
}