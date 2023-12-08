#include<iostream>

using namespace std;

class CircularQueue {
  	private:
  		int front;
  		int rear;
  		int arr[5];
  		

  	public:
  		CircularQueue() 
		{
      		front = -1;
      		rear = -1;
      		for (int i = 0; i < 5; i++) 
        		arr[i] = 0;
      	}
    
  	bool isEmpty();
  	bool isFull(); 
  	void enqueue(int val); 
  	int  dequeue(); 
  	int  count();
  	void display(); 
};
int main() 
{
  	CircularQueue q1;
  	int value, option;

  	do{
    	cout<<"\n Operations on Queue ";
    	cout << "1. Enqueue()" << endl;
    	cout << "2. Dequeue()" << endl;
   	cout << "3. isEmpty()" << endl;
    	cout << "4. isFull()" << endl;
    	cout << "5. count()" << endl;
    	cout << "6. display()" << endl;
    	cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    	cin >> option;

    	switch (option) 
		{
    		case 0:
      			break;
    		case 1:
      			cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
      				cin >> value;
      			q1.enqueue(value);
      			break;
    		case 2:
      			cout << "Dequeue Operation \nDequeued Value : " << q1.dequeue() << endl;
      			break;
            case 3:
      			if (q1.isFull())
        			cout << "Queue is Full" << endl;
      			else
        			cout << "Queue is not Full" << endl;
      			break;
            case 4:
      			cout << "Display Function Called - " << endl;
      			q1.display();
      			break;
            default:
      			cout << "Enter Proper Option number " << endl;
    	}

  	} while (option != 0);

  	return 0;
}

bool CircularQueue::isFull()
	{
    	if ((rear + 1) % 5 == front)
      		return true;
   		else
      		return false;
  	}

void CircularQueue::enqueue(int val)
  	{
    	if (isFull()) 
		{
 	    	cout << "Queue full" << endl;
   		  	return;
    	} 
		else if (isEmpty()) 
		{
     		rear = 0;
      		front = 0;
     		arr[rear] = val;
    	} 
    	
		else 
		{
      		rear = (rear + 1) % 5;
      		arr[rear] = val;

   		}
  	}

//pop element from front	
int CircularQueue::dequeue()
	{
    	int x = 0;
    	if (isEmpty()) 
		{
      		cout << "Queue is Empty" << endl;
      		return x;
   	 	} 
   	 	
		else if (rear == front) 
		{
      		x = arr[rear];
      		rear = -1;
      		front = -1;
      		return x;
    	} 
		
		else 
		{
      		cout << "front value: " << front << endl;
      		x = arr[front];
      		arr[front] = 0;
      		front = (front + 1) % 5;
      		return x;
    	}
  	}

void CircularQueue::display()
	{
    	cout << "All values in the Queue are - " << endl;
    	for (int i = 0; i < 5; i++) 
      		cout << arr[i] << "  ";
    
	}