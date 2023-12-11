#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
    char data;
    Node *left, *right;
};

class Expression
{
	char prefix[20], postfix[20], infix[20];
	Node* root;
	int top;
    
	public:
		void input(int);
		Node* getroot()
		{ 
			return root; 
		}
		int validate(int);
		Node* create_Post();
		void inorder_withoutRec(Node*);
		void preorder_withoutRec(Node*);
		void postorder_withoutRec(Node*);
};


int Expression::validate(int x)
{
    int i = 0, opn = 0, opt = 0;
    
    {
        for(;i<postfix[i]!='\0';i++)
        {
            if(postfix[i] == '+' || postfix[i] == '-' ||postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%' || postfix[i] == '^' || postfix[i] == '$')
                opt++;
            else
                opn++;
        }
        
        if(opt != (opn-1))
            return 0;
        return 1;
    }
}
void Expression::input(int x)
{

    {
        while(1)
        {
            cout<<"\nEnter postfix Expression: ";
            cin>>postfix;
            if(validate(x))
                break;
            else
                cout<<"\nWrong Expression. Please enter again.";
        }
    }
}

Node* Expression::create_Post()
{
    int i=0;
    Node* temp, *t1, *t2;
    stack<Node*> s;
    
    for(;postfix[i]!='\0';i++)
    {
        if(isalnum(postfix[i]))
        {
            temp = new Node;
            temp->data = postfix[i];
            temp->left = temp->right = NULL;
            s.push(temp);
        }
        else
        {
            t2 = s.top();
            s.pop();
            t1 = s.top();
            s.pop();
            temp = new Node;
            temp->data = postfix[i];
            temp->left = t1;
            temp->right = t2;
            s.push(temp);
        }
    }
    temp = s.top();
    s.pop();
    return temp;
}
void Expression::inorder_withoutRec(Node* t)
{
    Node* temp = t;
    stack<Node*> s;
    
    while(temp!=NULL)
    {
        s.push(temp);
        temp = temp->left;
    }
    
    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        cout<<" "<<temp->data;
        temp = temp->right;
        while(temp!=NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
}

void Expression::preorder_withoutRec(Node* t)
{
    Node* temp = t;
    stack<Node*> s;
    while(temp != NULL)
    {
        cout<<" "<<temp->data;
        s.push(temp);
        temp = temp->left;
    }
    
    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        temp = temp->right;
        while(temp != NULL)
        {
            cout<<" "<<temp->data;
            s.push(temp);
            temp = temp->left;
        }
    }
}

void Expression::postorder_withoutRec(Node* t)
{
    Node *t1, *temp = t;
    stack<Node*> s, s1;
    
    while(temp!=NULL)
    {
        s.push(temp);
        s1.push(NULL);
        temp = temp->left;
    }
        
    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        t1 = s1.top();
        s1.pop();
        if(t1 == NULL)
        {
            s.push(temp);
            s1.push((Node*)1);
            temp = temp->right;
            while(temp!=NULL)
            {
                s.push(temp);
                s1.push(NULL);
                temp = temp->left;
            }
                
        }
        else
            cout<<" "<<temp->data;       
    }     
}
int main()
{
	int choice;
	Expression et;
	Node* t;

	cout<<"\nPlease enter the postfix string: ";
	et.input(1);
	t = et.create_Post();
	cout<<"Inorder : ";
	et.inorder_withoutRec(t);
	cout<<"\n";
	cout<<"Postorder : ";
	et.postorder_withoutRec(t);
	cout<<"\n";
	cout<<"Preorder : ";
	et.preorder_withoutRec(t);
    return 0;
}