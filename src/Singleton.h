#pragma once
#include <iostream>


template <class T>
class Singleton
{
protected:
	Singleton() {};
	
public:
	static T& Instance()
	{
		static T *instance = new T();
		return *instance;
	}

};

//template <class T> T* Singleton<T>::instance = NULL;