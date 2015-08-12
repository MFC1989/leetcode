#include <iostream>
#include <stack>
#include <queue>
using namespace std;


//Implement Queue using Stacks  232

class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) 
	{
		elemColsLeft.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void)
	{

		if (elemColsRight.empty())
		{
			while (!elemColsLeft.empty())
			{
				elemColsRight.push(elemColsLeft.top());
				elemColsLeft.pop();
			}
		}
		elemColsRight.pop();
	}

	// Get the front element.
	int peek(void) 
	{
		if (elemColsRight.empty())
		{
			while (!elemColsLeft.empty())
			{
				elemColsRight.push(elemColsLeft.top());
				elemColsLeft.pop();
			}
		}
		return elemColsRight.top();
	}

	// Return whether the queue is empty.
	bool empty(void) 
	{
		if (elemColsLeft.empty()&&elemColsRight.empty())
		{
			return true;
		}
		return false;
	}

private:
	stack<int> elemColsLeft;
	stack<int> elemColsRight;
};

class Stack {
public:
	// Push element x onto stack.
	void push(int x)
	{
		elemColsLeft.push(x);
	}

	// Removes the element on top of the stack.
	void pop() 
	{
		if (!elemColsLeft.empty())
		{
			while (elemColsLeft.size() != 1)
			{
				elemColsRight.push(elemColsLeft.front());
				elemColsLeft.pop();
			}
			elemColsLeft.pop();
		}
		else
		{
			while (elemColsRight.size()!=1)
			{
				elemColsLeft.push(elemColsRight.front());
				elemColsRight.pop();
			}
			elemColsRight.pop();
		}

	}

	// Get the top element.
	int top() 
	{
		if (!elemColsLeft.empty())
		{
			while (elemColsLeft.size() != 1)
			{
				elemColsRight.push(elemColsLeft.front());
				elemColsLeft.pop();
			}
			elemColsRight.push(elemColsLeft.front());
			elemColsLeft.pop();
			return elemColsRight.back();
		}
		else
		{
			while (elemColsRight.size() != 1)
			{
				elemColsLeft.push(elemColsRight.front());
				elemColsRight.pop();
			}
			elemColsLeft.push(elemColsRight.front());
			elemColsRight.pop();
			return elemColsLeft.back();
		}
	}

	// Return whether the stack is empty.
	bool empty() 
	{
		if (elemColsLeft.empty()&&elemColsRight.empty())
		{
			return true;
		}
		return false;
	}

	private:
		queue<int> elemColsLeft;
		queue<int> elemColsRight;
};


int main()
{




	return 0;
}