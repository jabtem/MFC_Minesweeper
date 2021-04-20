#pragma once
#ifndef CONTAINER //��� �ߺ� ����
#define CONTAINER 10
template <typename T>//�����̳� ���ø�ȭ
class Container
{
public:
	Container(int = 50);
	~Container();
	void Insert(T); //�������Է�
	T Remove(int);  //idx��° ��ü ����
	T GetItem(int); //�ε��� idx�� ��ü ����
	int GetElemSum();//����� ��ü�� ��
	int GetLength();//�迭ũ�� ����
	T& operator[](int i);//a[i]������ �����ε�

private:
	T* arr;
	int length;
	int arrIdx;
};
template <typename T>
Container<T>::Container(int len)
	:arrIdx(0)
{
	arr = new T[len];
	this->length = len;
}
template <typename T>
Container<T>::~Container()
{
	delete[]arr;
}
template <typename T>
void Container<T>::Insert(T data)//�������Է�
{
	if (arrIdx >= length)
	{
		return;
	}
	arr[arrIdx++] = data;
}
template <typename T>
T Container<T>::Remove(int idx)//idx��° ��ü ����
{
	if (arrIdx >= length)
	{
		return NULL;
	}
	T remove = arr[idx];//�����Ȱ�ü
	if (idx == arrIdx - 1) //������ �ε�����ġ�� �迭�ǳ��ΰ��
	{
		arrIdx--;
	}
	else
	{
		for (int i = idx;i < arrIdx - 1;++i)
		{
			arr[idx] = arr[idx + 1];//�迭�� ��ĭ�� �����δ��
		}
	}
	return remove;
}
template <typename T>
T Container<T>::GetItem(int idx)//�ε��� idx�� ��ü ����
{
	return arr[idx];
}
template <typename T>
int Container<T>::GetElemSum()//����� ��ü�� ��
{
	return arrIdx;
}
template <typename T>
int Container<T>::GetLength()//����� ��ü�� ��
{
	return length;
}
template <typename T>
T& Container<T>::operator[](int i)//������ �����ε�
{
	return arr[i];
}
#endif