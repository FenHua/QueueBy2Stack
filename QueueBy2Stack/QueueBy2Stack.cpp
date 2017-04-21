// QueueBy2Stack.cpp : 定义控制台应用程序的入口点。
#include"iostream"
#include<stack>
#include<assert.h>
using namespace std;
template<typename T>class QueueBy2Stack
{
private:
	stack<T>_stack1;
	stack<T>_stack2;
public:
	void Push(const T&x)
	{
		_stack1.push(x);
	}
	void Pop()
	{
		assert(!_stack1.empty() || !_stack2.empty());
		if (_stack2.empty())
		{
			//栈2空
			while (_stack1.size() > 0)
			{
				T&tmp = _stack1.top();
				_stack1.pop();
				_stack2.push(tmp);
			}
		}
		_stack2.pop();
	}
	T& Front()
	{
		assert(!_stack1.empty() || !_stack2.empty());
		if (_stack2.empty())
		{
			while (_stack1.size() > 0)
			{
				T&tmp = _stack1.top();
				_stack1.pop();
				_stack2.push(tmp);
			}
		}
		return _stack2.top();
	}
	T& Back()
	{
		assert(!_stack1.empty() || !_stack2.empty());
		if (_stack1.empty())
		{
			while (_stack2.size() > 0)
			{
				T& tmp = _stack2.top();
				_stack2.pop();
				_stack1.push(tmp);
			}
		}
		return _stack1.top();
	}
	bool Empty()
	{
		return (_stack1.empty()) && (_stack2.empty());
	}
};
int main()
{
	QueueBy2Stack<int>qs;
	qs.Push(1);
	qs.Push(2);
	qs.Push(3);
	qs.Push(4);
	qs.Push(5);
	cout << qs.Front() << endl;
	cout << qs.Back() << endl;
	qs.Pop();
	qs.Pop();
	cout << qs.Front() << endl;
	cout << qs.Back() << endl;
	qs.Pop();
	qs.Pop();
	qs.Pop();
	system("pause");
	return 0;
}