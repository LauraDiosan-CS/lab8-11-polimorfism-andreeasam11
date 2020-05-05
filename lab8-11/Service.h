#pragma once
#include "RepositoryFile.h"
#include "RepositoryFileCSV.h"
#include "CustomFileRepo.h"
#include "DronaValidator.h"
#include "TelefonValidator.h"
#include "Serializer.h"
#include "Drona.h"
#include "Telefon.h"
#include "User.h"

class Service {
private:
	RepositoryFile<Serie*>* repo;
	Repository<User> repoUser;
	Serializer seriel;
public:
	Service();
	Service(RepositoryFile<Serie*>*, Repository<User>, Serializer);
	void addDrona(string, string, int, int);
	void addTelefon(string, string, int, vector<string>);
	vector<Serie*> cautareProducator(string);
	void login(string, string);
	vector<Serie*> getAll();
	void changeRepo(string);
	void logout(string, string);
	~Service();
};