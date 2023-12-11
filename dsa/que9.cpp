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
        void del(int);
        Node* delete_Node(Node *, int);
		void mirror_tree(Node*);
        void display(Node *);
		void display_level();
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
void BST::del(int x)
{
	root = delete_Node(root, x);
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

Node* BST::delete_Node(Node *t, int x)
{
	Node *temp;

	if(t == NULL)
	{
		cout<<"\nElement not found!";
		return t;
    	}
	if(x < t->data)	
	{
		t->left = delete_Node(t->left, x);
		return t;
	}
	else if(x > t->data)
	{
		t->right = delete_Node(t->right, x);
		return t;
	}
	else
	{
		if(t->left == NULL && t->right == NULL)
		{
			temp = t;
			delete temp;
			return NULL;
		}
		if(t->left == NULL)
		{
			temp = t;
			t = t->right;
			delete temp;
			return t;
		}
		if(t->right == NULL)
		{
			temp = t;
			t = t->left;
			delete temp;
			return t;
		}
		temp = t->right;
		while(temp->left != NULL)
			temp = temp->left;
		t->data = temp->data;
		t->right = delete_Node(t->right, temp->data);
		return t;
	}
	return NULL;
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
void BST::display_level()
{
	queue<Node*> q, q2;
	Node* curr;
	Node* temp = root;
	if(temp == NULL)
		return;

	q.push(temp);
	q.push(NULL);

	while (q.size() > 1)
	{
		curr = q.front();
		q.pop();

		if (curr == NULL)
		{
			q.push(NULL);
			cout << "\n";
		}

		else
		{

			if(curr->left)
			q.push(curr->left);

			if(curr->right)
			q.push(curr->right);

			cout << curr->data << " ";
		}
	}
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
		cout<<"\n2. Delete.";
		cout<<"\n3. Display level wise.";
		cout<<"\n4. Mirror.";
		cout<<"\n5. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: 
				tree.insert();
			break;
			case 2: 
				cout<<"\nTo delete: ";
				cin>>x;
				tree.del(x);
				break;
			case 3: 
				cout<<"\nLevel-Order traversal of tree: ";
				tree.display_level();
				break;
			case 4: 
				cout<<"\nMirror Image of tree: ";
				tree.mirror_tree(tree.getroot());
				tree.display(tree.getroot());
				tree.mirror_tree(tree.getroot());
				break;
			case 5: 
				return 0;
		}
	}
	return 0;
}