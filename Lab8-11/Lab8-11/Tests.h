#pragma once
#include"Phone.h"
#include"Repository.h"
#include"RepositoryFile.h"

class Tests {
private:
	RepositoryFile<Phone> repof;
	RepositoryTemplate<Phone> repo;
	//Service serv();
public:
	Tests();
	void testDomain();
	void testRepoTemplate();
	void testRepoFile();
	//void testService();
	~Tests();
};
