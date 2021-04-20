#pragma once
#ifndef CONTAINER //헤더 중복 방지
#define CONTAINER 10
template <typename T>//컨테이너 템플릿화
class Container
{
public:
	Container(int = 50);
	~Container();
	void Insert(T); //순차적입력
	T Remove(int);  //idx번째 객체 삭제
	T GetItem(int); //인덱스 idx의 객체 참조
	int GetElemSum();//저장된 객체의 수
	int GetLength();//배열크기 리턴
	T& operator[](int i);//a[i]연산자 오버로딩

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
void Container<T>::Insert(T data)//순차적입력
{
	if (arrIdx >= length)
	{
		return;
	}
	arr[arrIdx++] = data;
}
template <typename T>
T Container<T>::Remove(int idx)//idx번째 객체 삭제
{
	if (arrIdx >= length)
	{
		return NULL;
	}
	T remove = arr[idx];//삭제된객체
	if (idx == arrIdx - 1) //삭제할 인덱스위치가 배열의끝인경우
	{
		arrIdx--;
	}
	else
	{
		for (int i = idx;i < arrIdx - 1;++i)
		{
			arr[idx] = arr[idx + 1];//배열을 한칸씩 앞으로당김
		}
	}
	return remove;
}
template <typename T>
T Container<T>::GetItem(int idx)//인덱스 idx의 객체 참조
{
	return arr[idx];
}
template <typename T>
int Container<T>::GetElemSum()//저장된 객체의 수
{
	return arrIdx;
}
template <typename T>
int Container<T>::GetLength()//저장된 객체의 수
{
	return length;
}
template <typename T>
T& Container<T>::operator[](int i)//연산자 오버로딩
{
	return arr[i];
}
#endif