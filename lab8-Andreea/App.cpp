
#include"Tests.h"
#include "Phone.h"
#include "SerializerSerie.h"
#include "SerializerUser.h"
#include "Repository.h"
#include"RepositoryFile.h"
#include"Service.h"
#include"UI.h"
using namespace std;
#include <iostream>
#include "RepositoryFileCSV.h"
#include "RepositoryFileHTML.h"

int main()
{
    cout << "start"<<endl;
    Tests test;
    test.testDomainPhone();
    test.testDomainDrone();
    test.testRepoTemplate();
 
    test.testRepoFileCSV();
    test.testRepoFileHTML();
    test.testRepoFileSerie();
    test.testService();
    cout << "succes" << endl;
    SerializerSerie* s = new SerializerSerie();
    SerializerUser* u = new SerializerUser();
    RepositoryFileHTML<Serie*>repof("Series.html",s);
    RepositoryFile<User*> repo("Users.txt", ' ', u);
    Service serv(repof, repo);
    UI ui(serv);
    ui.showUI();
}