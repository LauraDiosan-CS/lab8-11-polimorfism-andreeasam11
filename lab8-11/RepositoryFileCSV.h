#pragma once
#include "RepositoryFile.h"
#include "Serializer.h"
#include <fstream>
using namespace std;

template  <class T> class RepositoryFileCSV : public RepositoryFile<T>
{
protected:
	Serializer serial;
public:
	RepositoryFileCSV();
	RepositoryFileCSV(const char*, Serializer);
	void loadFromFile();
	void saveToFile();
	~RepositoryFileCSV();
};
template<class T>
RepositoryFileCSV<T>::RepositoryFileCSV()
{
}

template<class T>
inline RepositoryFileCSV<T>::RepositoryFileCSV(const char* fName, Serializer se) :RepositoryFile<T>(fName)
{
	serial = se;
}

template<class T>
void RepositoryFileCSV<T>::loadFromFile()
{
	string line;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, line)) {
		Repository<T>::elem.push_back(serial.serialize(line, ','));
	}
}

template<class T>
void RepositoryFileCSV<T>::saveToFile()
{
	ofstream f(RepositoryFile<T>::fileName);
	for (int i = 0;i < Repository<T>::size();i++)
		f << Repository<T>::elem[i]->toStringDelimiter(',')<<endl;
}

template<class T>
RepositoryFileCSV<T>::~RepositoryFileCSV()
{
}