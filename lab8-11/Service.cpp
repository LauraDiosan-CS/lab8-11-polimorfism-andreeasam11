#include "Service.h"
#include "Exceptions.h"
#include "User.h"

Service::Service() {
}

Service::Service(RepositoryFile<Serie*>* repos, Repository<User> users, Serializer seri) {
	repo = repos;
	repoUser = users;
	seriel = seri;
	User u1("andreea", "123");
	User u2("ana", "1234");
	User u3("andrei", "12345");
	repoUser.add(u1);
	repoUser.add(u2);
	repoUser.add(u3);
}

void Service::login(string u, string p) {
	User usr(u, p);
	if (repoUser.find(usr) == -1)
	{
		LogginException exc("Acest user nu exista!");
		throw exc;
	}
}

void Service::addDrona(string producator, string model, int bucati, int rotoare) {
	Serie* drona = new Drona(producator, model, bucati, rotoare);
	DroneValidator validator;
	validator.validate(Drona(producator, model, bucati, rotoare));
	repo->add(drona);
	repo->saveToFile();
}

void Service::addTelefon(string producator, string model, int bucati, vector<string> gsm) {
	Serie* telefon = new Telefon(producator, model, bucati, gsm);
	TelefonValidator validator;
	validator.validate(Telefon(producator, model, bucati, gsm));
	repo->add(telefon);
	repo->saveToFile();
}

vector<Serie*> Service::cautareProducator(string linie) {
	vector<Serie*> final;
	for (int i = 0;i < repo->size();i++)
		if (repo->getAll()[i]->getNumeProducator() == linie)
			final.push_back(repo->getAll()[i]->clone());
	return final;
}

vector<Serie*> Service::getAll() {
	return repo->getAll();
}

void Service::logout(string u, string p) {
	User usr(u, p);
	repoUser.remove(usr);
}

void Service::changeRepo(string linie) {
	if (linie == "RepoCSV")
	{
		repo = new RepositoryFileCSV<Serie*>("repositoryCSV.csv", seriel);
		repo->loadFromFile();
	}
	else
		if (linie == "CustomFileRepo")
		{
			repo = new CustomFileRepo<Serie*>("customFileRepo.txt", seriel);
			repo->loadFromFile();
		}
		else
		{
			RepositoryException exc("Poti alege doar intre: RepoCSV si CustomFileRepo");
			throw exc;
		}
	
}

Service::~Service() {
}