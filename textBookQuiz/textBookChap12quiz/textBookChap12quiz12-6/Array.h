#pragma once
#include<cassert>
#include<string>

template<class T>
class Array{
private:
	T* list;
	int size;
public:
	Array(int sz = 50);
	Array(const Array<T>& a);
	~Array();

	Array<T>& operator=(const Array<T>& rhs);

	T& operator[](int i);

	T& operator[](int i)const;

	operator T* ();

	operator T* ()const;

	int getSize()const;

	void resize(int sz);

};

template<class T>
Array<T>::Array(int sz) {
	assert(sz >= 0);
	size = sz;
	list = new T[size];
}

template<class T>
Array<T>::~Array() {
	delete[]list;
}

template<class T>
Array<T>::Array(const Array<T>& a) {
	size = a.size;
	list = new T[size];
	for (int i = 0; i < size; i++) {
		list[i] = a.list[i];
	}
}

template<class T>
Array<T>& Array<T>:: operator=(const Array<T>& rhs) {
	if (&rhs != this) {
		if (size != rhs.size) {
			delete[]list;
			size = rhs.size;
			list = new T[size];
		}
		for (int i = 0; i < size; i++) {
			list[i] = rhs.list[i];
		}
	}
	return *this;
}

template<class T>
T& Array<T>::operator[](int n) {
	if (n < 0 || n >= size) {
		throw std::string("out_of_range");
	}
	return list[n];
}

template<class T>
T& Array<T>::operator[](int n)const {
	if (n < 0 || n >= size) {
		throw std::string("out_of_range");
	}
	return list[n];
}

template<class T>
Array<T>:: operator T* (){
	return list;
}

template<class T>
Array<T>:: operator T* ()const {
	return list;
}

template<class T>
int Array<T>::getSize()const {
	return size;
}

template<class T>
void Array<T>::resize(int sz) {
	assert(sz >= 0);
	if (sz == 0) {
		return;
	}
	T* newList = new T[sz];
	int n = (sz < size) ? sz : size;

	for (int i = 0; i < n; i++) {
		newList[i] = list[i];
	}
	delete[]list;
	list = newList;
	size = sz;
}
