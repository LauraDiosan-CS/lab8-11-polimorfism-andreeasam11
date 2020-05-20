#pragma once
#include <map>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <class T>
class Repository {
protected:
	map<int, T>elem;
	int key;
public:
	Repository<T>();
	//Repository(const Repository&);
	virtual void addElem(T);
	int findElem(T);
	virtual void delElem(int);
	virtual void updateElem(T, T);
	int dim();
	map<int, T> getAll();
	virtual T getItemFromPos(int);
	~Repository();
};

template <class T> inline Repository<T>::Repository()
{
	this->key = 0;
}

//template <class T> inline Repository<T>::Repository(const Repository& r)
//{
//	this->elem = r.elem;
//	this->key = r.key;
//}

template <class T> void Repository<T>::addElem(T obj)
{
	this->elem.insert(pair<int, T>(this->key++, obj));
}

template <class T> int Repository<T>::findElem(T a)
{
	for (auto itr = elem.begin(); itr != elem.end(); itr++)
		if (elem.find(itr->first)->second == a)
			return itr->first;
	return -1;
}

template <class T> void Repository<T>::delElem(int nr)
{
	elem.erase(nr);
}

template <class T> void Repository<T>::updateElem(T vechi, T noua)
{
	for (auto itr = elem.begin();itr != elem.end();itr++)
		if (elem.find(itr->first)->second == vechi)
		{
			elem[itr->first] = noua;
			break;
		}
}

template <class T> int Repository<T>::dim()
{
	return this->key;
}

template <class T> map<int, T>Repository<T>::getAll()
{
	return elem;
}

template <class T> T Repository<T>::getItemFromPos(int poz)
{
	for (auto itr = elem.begin(); itr != elem.end(); itr++)
		if (itr->first == poz)
			return itr->second;
	return T();
}
template <class T> Repository<T>::~Repository()
{
	elem.clear();
	key = 0;
}