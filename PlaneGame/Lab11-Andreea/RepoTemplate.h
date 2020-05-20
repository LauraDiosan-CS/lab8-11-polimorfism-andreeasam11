#pragma once
#include<map>
#include<iostream>
#include"Plane.h"
using namespace std;


template< class T >

class RepoTemplate {
protected:
	map<int, T>elem = { };
	int key = 0;
public:
	RepoTemplate<T>();
	virtual ~RepoTemplate<T>();
	virtual void addElem(T);
	virtual int delElem(int i);
	virtual int updateElem(int i, const T nou);
	int getSize();
	map<int, T>getAll();
	void clearMap();
	T find(int i);
};

template <class T>RepoTemplate<T>::RepoTemplate() {

}


template <class T>RepoTemplate<T>::~RepoTemplate() {

}

template <class T>void RepoTemplate<T>::addElem(T e) {
	elem.insert(pair<int, T>(key++, e));
}

template<class T>int RepoTemplate<T>::delElem(int i) {
	auto itr = elem.find(i);
	if (itr != elem.end()) {
		elem.erase(itr);
		return 0;
	}
	else
		return -1;

}

template< class T>int RepoTemplate<T>::updateElem(int i, const T nou) {


	if (i >= 0 && i < elem.size()) {
		delElem(i);
		elem.emplace(i, nou);
		return 0;
	}
	else
		return -1;
}


template<class T>int RepoTemplate<T>::getSize() {

	return elem.size();

}

template<class T>map<int, T> RepoTemplate<T>::getAll() {

	return elem;
}
template<class T>void RepoTemplate<T>::clearMap() {

	elem.clear();
	key = 0;
}
template<class T>T RepoTemplate<T>::find(int i)
{
	int poz = 0;
	for (auto itr = elem.begin(); itr != elem.end(); itr++) {
		if (poz == i) { return itr->second; }
		else { itr++; poz++; }
	}
}