#pragma once
template <typename T>
class Stack
{
public:
	Stack(int);
	~Stack();
	T Pop();
	void Push(const T&);
	int GetIdx();
private:
	int index;
	int len;
	T* stackPtr;//스택포인터
};
template <typename T>
Stack<T>::Stack(int len)
	:index(-1)
{
	stackPtr = new T[len];
}
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr;
}
template <typename T>
T Stack<T>::Pop()
{
	if (index != -1)
	{
		return stackPtr[index--];
	}
}
template <typename T>
void Stack<T>::Push(const T& p)
{
	stackPtr[++index] = p;
}
template <typename T>
int Stack<T>::GetIdx()
{
	return index;
}