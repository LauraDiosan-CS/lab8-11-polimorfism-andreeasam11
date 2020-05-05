#include "TestRepository.h"
#include "RepositoryFileCSV.h"
#include "CustomFileRepo.h"
#include "Telefon.h"
#include "Serializer.h"
#include <assert.h>
#include "Drona.h"
#include <iostream>

using namespace std;

void testRepository() {
	RepositoryFile<Serie*> *repo, *repoCustom;
	Serializer seriel;
	repo = new RepositoryFileCSV<Serie*>("repositoryTestCSV.csv", seriel);
	Serie *d1= new Drona("samsung", "d20", 20, 30);
	repo->loadFromFile();
	assert(repo->size() == 1);
	vector<string> t1;
	t1.push_back("rx100");
	t1.push_back("rga234");
	Serie *te1=new Telefon("Samsung", "GalaxyS10", 200, t1);
	repo->add(d1);
	repo->add(te1);
	assert(repo->size() == 3);
	assert(repo->find(te1) == 2);
	repoCustom = new CustomFileRepo<Serie*>("repositoryTestCustom.txt", seriel);
	Serie* d2 = new Drona("samsung", "d20", 20, 30);
	repoCustom->loadFromFile();
	assert(repoCustom->size() == 1);
	vector<string> t2;
	t2.push_back("rx100");
	t2.push_back("rga234");
	Serie* te2 = new Telefon("Samsung", "GalaxyS10", 200, t2);
	repoCustom->add(d2);
	repoCustom->add(te2);
	assert(repoCustom->size() == 3);
	assert(repoCustom->find(te2) == 2);
	cout << "Repository tests done!" << endl;
}