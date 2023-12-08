#include<stdlib.h>
#include<iostream>
#include<string.h>
#define max 30
using namespace std;
struct node
{
    char data;
    struct node* next;
};
class stack
{
    node* top;
    char x;
public:
    stack()
    {
        top = NULL;
    }
    int empty()
    {
        if (top == NULL)
        {
            return(1);
        }
        else
        {
            return(0);
        }
    }
    void push(char x)
    {
        node* p;
        p = new node;
        p->data = x;
        p->next = top;
        top = p;
    }
    char pop()
    {
        if (!empty())
        {
            node* p;
            p = new node;
            p = top;
            top = top->next;
            x = p->data;
            delete p;
            return(x);
        }
        else
        {
            return(0);
        }
    }
    char pop1()
    {
        if (!empty())
        {
            node* p;
            p = new node;
            p = top;
            x = p->data;
            return(x);
        }
        else
        {
            return(0);
        }
    }
};
void infix_to_prefix(char infix[], char prefix[]);
void eval_prefix(char prefix[]);
int evaluate(char x, int op1, int op2);
int main()
{
    char infix[30], prefix[30], postfix[30];
    int op;
 
    do {
        cout<<endl<<"\t\t"<<"MAIN MENU";
        cout<<endl;
        cout<<endl<<"\t"<<"1. Infix to Prefix with Evaluation        ";
        cout<<endl<<"\t"<<"2. Exit                                   ";
        cout<<endl<<"Enter your choice ";
        cin>>op;    
        cout<<"........................................................."<<endl;
       switch (op)
        {
        case 1:
            cout << "\nEnter the infix expression::" << endl;
                cin >> infix;
            infix_to_prefix(infix, prefix);
            cout << "\nPrefix expression is " << prefix << endl;
            cout << "\n\nEvaluation of Prefix expression";
            eval_prefix(prefix);
            break;
        }
    } while (op != 2);
    return 0;
}
void infix_to_prefix(char infix[], char prefix[])
{
    int i, j;
    char temp, in1[30];
    cout << "\n\nEntered infix is...";
    for (i = 0; i <= strlen(infix) - 1; i++)
    {
        cout << infix[i];
    }
    for (i = strlen(infix) - 1, j = 0; i >= 0; i--, j++)
        in1[j] = infix[i];
    in1[j] = '\0';
 
   for (i = 0; in1[i] != '\0'; i++)
    {
        if (in1[i] == '(')
            in1[i] = ')';
        else
            if (in1[i] == ')')
                in1[i] = '(';
    }
    infix_to_prefix(in1, prefix);
    for (i = 0, j = strlen(prefix) - 1; i < j; i++, j--)
    {
        temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }
}
void eval_prefix(char prefix[])
{
    stack s;
    char x;
    int op1, op2, val, i;
    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        x = prefix[i];
        if (isalpha(x))
        {
            cout << "\nEnter the value of " << x << ":";
            cin >> val;
            s.push(val);
        }
        else
        {
            op1 = s.pop();
            op2 = s.pop();
            val = evaluate(x, op1, op2);
            s.push(val);
        }
    }
    val = s.pop();
    cout << "\nValue of expression is " << val;
}
int evaluate(char x, int op1, int op2)
{
    if (x == '+')
        return(op1 + op2);
    if (x == '-')
        return(op1 - op2);
    if (x == '*')
        return(op1 * op2);
    if (x == '/')
        return(op1 / op2);
    if (x == '%')
        return(op1 % op2);
}
