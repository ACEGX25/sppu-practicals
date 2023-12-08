
#include<iostream>
#include<string.h>
#define max 30
using namespace std;

struct node{
    char data;
    struct node*next;
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
int precedence(char x);
void infix_to_postfix(char infix[], char postfix[]);
void eval_postfix(char postfix[]);
int evaluate(char x, int op1, int op2);


int main(){
        char infix[30], prefix[30], postfix[30];
    int op;
 
    do {
        cout<<endl<<"\t\t"<<"MAIN MENU";
        cout<<endl;
        cout<<endl<<"\t"<<"1. Infix to Postfix with Evaluation        ";
        cout<<endl<<"\t"<<"2. Exit                                   ";
        cout<<endl<<"Enter your choice ";
        cin>>op;    
        cout<<"........................................................."<<endl;
       switch (op){
        case 1:
            cout << "\nEnter the infix expression::" << endl;
                cin >> infix;
            infix_to_postfix(infix, postfix);
            cout << "\nPostfix expression is " << postfix << endl;
            cout << "\n\nEvaluation of Postfix expression";
            eval_postfix(postfix);
            break;
       }
    } while (op!=2);
    return 0;
}

void infix_to_postfix(char infix[], char postfix[])
{
    stack s;
    node* top;
    char x;
    int i, j;
    char token;
    j = 0;
    for (i = 0; infix[i] != '\0'; i++)
    {
        token = infix[i];
        if (isalnum(token))
        {
            postfix[j++] = token;
        }
        else if (token == '(')
        {
            s.push('(');
        }
        else if (token == ')')
        {
            while ((x = s.pop()) != '(')
            {
                postfix[j++] = x;
            }
        }
        else
        {
            x = s.pop1();
            while (precedence(token) < precedence(x) && !s.empty())
            {
                x = s.pop();
                postfix[j++] = x;
            }
            s.push(token);
        }
    }
    while (!s.empty())
    {
        x = s.pop();
        postfix[j++] = x;
    }
    postfix[j] = '\0';
}
 
int precedence(char x)
{
    if (x == '(')
    {
        return(0);
    }
    if (x == '+' || x == '-')
    {
        return(1);
    }
    if (x == '*' || x == '/' || x == '%')
    {
        return(2);
    }
    return(3);
}

void eval_postfix(char postfix[])
{
    stack s;
    char x;
    int op1, op2, val, i;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        x = postfix[i];
        if (isalpha(x))
        {
            cout << "\nEnter the value of " << x << ":";
            cin >> val;
            s.push(val);
        }
        else
        {
            op2 = s.pop();
            op1 = s.pop();
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
