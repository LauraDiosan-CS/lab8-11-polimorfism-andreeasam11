#pragma once
#include "Serializer.h"
#include <fstream>

template <class T> class CustomFileRepo :public RepositoryFile<T>
{
protected:
	Serializer serial;
public:
	CustomFileRepo();
	CustomFileRepo(const char*, Serializer);
	void loadFromFile();
	void saveToFile();
	~CustomFileRepo();
};

template<class T>
inline CustomFileRepo<T>::CustomFileRepo()
{
}

template<class T>
inline CustomFileRepo<T>::CustomFileRepo(const char* fName, Serializer seri) :RepositoryFile<T>(fName)
{
	serial = seri;
}

template<class T>
inline void CustomFileRepo<T>::loadFromFile()
{
	string line;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, line)) {
		Repository<T>::elem.push_back(serial.serialize(line, '/'));
	}
}

template<class T>
inline void CustomFileRepo<T>::saveToFile()
{
	ofstream f(RepositoryFile<T>::fileName);
	for (int i = 0;i < Repository<T>::size();i++)
		f << Repository<T>::elem[i]->toStringDelimiter('/') << endl;
}

template<class T>
inline CustomFileRepo<T>::~CustomFileRepo()
{
}