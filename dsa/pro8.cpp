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
	Node* mirror;
	public:
		BST()
		{root = NULL;
	         mirror = NULL;
                }
		Node* getroot()
		{  return root; }  
		Node* getmirror()
		{  return mirror;}
		void insert();
		void search(int);
		void display(Node *);
		int height_tree(Node*);
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
void BST::search(int no)
{
	Node *temp;
	temp = root;
	check:
	if(no == temp->data)
	{
		cout<<"\nData found!";
		return;
	}
	if(no < temp->data)
	{
		if(temp->left != NULL)
		{
			temp = temp->left;
			goto check;
		}
		else
		{
			cout<<"\nData doesnt exist.";
			return;
		}
	}
	else if(no > temp->data)
	{
		if(temp->right != NULL)
		{
			temp = temp->right;
			goto check;
		}
		else
		{
			cout<<"\nData doesnt exist.";
			return;
		}
	}
}
int BST::height_tree(Node *t)
{
	int hlt, hrt;
	if(t == NULL)
		return 0;
	else
	{
		hlt = height_tree(t->left) + 1;
		hrt = height_tree(t->right) + 1;
	}
	if(hlt > hrt)
		return hlt;
	return hrt;
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
		cout<<"\n2. Search.";
		cout<<"\n3. Display.";
		cout<<"\n4. Height of the tree.";
		cout<<"\n5. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: 
				tree.insert();
			break;
			case 2: 
				cout<<"\nEnter number to search: ";
				cin>>x;
				tree.search(x);
				break;
			case 3: 
				cout<<"\nInorder traversal of tree: ";
				tree.display(tree.getroot());
				break;
			case 4: 
				cout<<"\nHeight of the tree: "<<tree.height_tree(tree.getroot());
				break;
			case 5: 
				return 0;
		}
	}
	return 0;
}