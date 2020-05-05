#pragma once
#include "Serializer.h"
#include "Repository.h"
template <class T> class RepositoryFile : public Repository<T>
{
protected:
	const char* fileName;
public:
	RepositoryFile();
	RepositoryFile(const char*);
	virtual void saveToFile();
	virtual void loadFromFile();
	~RepositoryFile();
};


template<class T>
RepositoryFile<T>::RepositoryFile() :Repository<T>()
{
}

template<class T>
RepositoryFile<T>::RepositoryFile(const char* name)
{
	fileName = name;
}

template<class T>
RepositoryFile<T>::~RepositoryFile()
{
}

template<class T>
void RepositoryFile<T>::saveToFile()
{
}

template<class T>
void RepositoryFile<T>::loadFromFile()
{
}