#include "pch.h"
#include "Operations.h"

using namespace std;

void loadClients(vector<Client> &clients) {

	ifstream clientsFile;
	clientsFile.open("clients.txt", ios::in);

	string line;
	int counter = 1;

	Client newClient;
	string pack;

	while (getline(clientsFile, line))
	{
	
		if (line == "::::::::::") {

			clients.push_back(newClient);
			newClient = {};
			counter = 1;
		}
		else {

			switch (counter)
			{
			//name
			case 1:
				newClient.name = line;
				break;
			//nif
			case 2:
				newClient.nif = stoi(line);
				break;
			//numberPeople
			case 3:
				newClient.numPeople = stoi(line);
				break;
			//address
			case 4:
				newClient.address = stringToAddress(line);
				break;
			case 5:
				newClient.boughtPacks = stringToBoughtPacks(line);
				break;
			case 6:
				newClient.moneySpent = stod(line);
				break;
			default:
				continue;
				break;
			}

			counter++;
		
		}
	}	
}
void storeClients(vector<Client> &clients) {

	remove("clients.txt");

	for (int i = 0; i < clients.size(); i++) {

		//INSERT IN FILE
		ofstream clientsFile;
		clientsFile.open("clients.txt", std::ios_base::app);
		clientsFile << clients[i].name << endl;
		clientsFile << clients[i].nif << endl;
		clientsFile << clients[i].numPeople << endl;
		clientsFile << addressToString(clients[i].address) << endl;
		clientsFile << boughtPacksToString(clients[i].boughtPacks) << endl;
		clientsFile << clients[i].moneySpent << endl;
		clientsFile << "::::::::::" << endl;
		clientsFile.close();
	}

	
}
void loadPacks(vector<Pack> &packs) {

	Pack newPack;

	ifstream packsFile;
	packsFile.open("packs.txt", ios::in);

	string line;
	int counter = 1;

	getline(packsFile, line);
	
	
	while (getline(packsFile, line))
	{

		if (line == "::::::::::") {

			packs.push_back(newPack);
			newPack = {};
			counter = 1;
		}
		else {
			int pos = 0;

			switch (counter)
			{
			//id
			case 1:
				newPack.id = stoi(line);
				break;
			//places
			case 2:
				newPack.places = stringToPlaces(line);
				break;
			//beginDate
			case 3:
				newPack.beginDate = stringToDate(line);
			//endDate
			case 4:
				newPack.endDate = stringToDate(line);
			//pricePerson
			case 5:
				newPack.pricePerson = stod(line);
				break;
			//signMax
			case 6:
				newPack.signMax = stoi(line);
				break;
			case 7:
				newPack.soldAmount = stoi(line);
			default:
				continue;
				break;
			}
			counter++;
		}
	}
}
void storePacks(vector<Pack> &packs) {

	remove("packs.txt");

	for (int i = 0; i < packs.size(); i++) {

		//INSERT IN FILE
		ofstream packsFile;
		packsFile.open("packs.txt", std::ios_base::app);

		if (i==0)
			packsFile << packs.size() << endl;

		packsFile << packs[i].id << endl;
		packsFile << placesToString(packs[i].places) << endl;
		packsFile << dateToString(packs[i].beginDate) << endl;
		packsFile << dateToString(packs[i].endDate) << endl;
		packsFile << packs[i].pricePerson << endl;
		packsFile << packs[i].signMax << endl;
		packsFile << packs[i].soldAmount << endl;
		packsFile << "::::::::::" << endl;
		packsFile.close();
	}


}

void update(vector<Pack> &packs, vector<Client> &clients) {
	storeClients(clients);
	storePacks(packs);
}