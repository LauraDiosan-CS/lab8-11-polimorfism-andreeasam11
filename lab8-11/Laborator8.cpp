#include <iostream>
#include "TestsDomain.h"
#include "RepositoryFileCSV.h"
#include "CustomFileRepo.h"
#include "Serializer.h"
#include "Service.h"
#include "TestRepository.h"
#include "UI.h"
#include "Drona.h";
#include "Telefon.h"

using namespace std;

int main() {
	testTelefon();
	testDrona();
	testRepository();
	Serializer seriel;
	RepositoryFile<Serie*> *repo;
	repo = new RepositoryFile<Serie*>;
	Repository<User> repoUser;
	Service service(repo, repoUser, seriel);
	UI ui(service);
	ui.run();
}