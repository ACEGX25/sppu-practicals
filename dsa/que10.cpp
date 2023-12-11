#include <iostream>
#include <queue>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};
class BST
{
	Node* root;
	Node*mirror;
	public:
		BST()
		{root = NULL; }
		Node* getroot()
		{  return root; }  
		void insert();
        Node* getmirror()
		{  return mirror;}
		void mirror_tree(Node*);
        void display(Node *);
};
void BST::insert()
{
	Node* temp, *newNode;
	char ch = 'y';

	while(ch == 'y' || ch == 'Y')
	{
		newNode = new Node();
		cout<<"\nEnter data for new Node: ";
		cin>>newNode->data;
		newNode->left = newNode->right = NULL;

		if(root == NULL)
			root = newNode;
		else
		{
			temp = root;
			check:
			if(newNode->data < temp->data)
			{
				if(temp->left != NULL)
				{
					temp = temp->left;
					goto check;
				}
				else
				{
					temp->left = newNode;
				}
			}
			else if(newNode->data > temp->data)
			{
				if(temp->right != NULL)
				{
					temp = temp->right;
					goto check;
                	}
				else
				{
					temp->right = newNode;
				}
            	}
        }
        cout<<"\nEnter y or Y to add more Nodes: ";
        cin>>ch;
    }
}

void BST::display(Node *root)
{
	if(root == NULL)
		return;
	else
	{
		display(root->left);
		cout<<" "<<root->data<<" ";
		display(root->right);
	}
}

void BST::mirror_tree(Node* t)
{
	Node* temp;
	if(t!=NULL)
	{
		temp = t->left;
		t->left = t->right;
		t->right = temp;

		mirror_tree(t->left);
		mirror_tree(t->right);
	}
	else
		return;
}

int main()
{
	BST tree;
	int x, choice;
	char ch = 'y';
    	while(1)
	{
		cout<<"\n\nBinary Search Tree Operations ";
		cout<<"\n1. Insert.";
		cout<<"\n2. Display.";
		cout<<"\n3. Mirror.";
		cout<<"\n4. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: 
				tree.insert();
			break;
			case 2: 
				cout<<"\nInorder traversal of tree: ";
				tree.display(tree.getroot());
				break;
			case 3: 
				cout<<"\nMirror Image of tree: ";
				tree.mirror_tree(tree.getroot());
				tree.display(tree.getroot());
				tree.mirror_tree(tree.getroot());
				break;
			case 4: 
				return 0;
		}
	}
	return 0;
}