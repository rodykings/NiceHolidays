#include "pch.h"
#include "clients.h"
#include "operations.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "suboperations.h"
#include <algorithm>



int searchByNif(vector<Client> &vector, int nif) {

	for (int i = 0; i < vector.size(); i++) {
		if (vector[i].nif == nif) {
			return i;
		}
	}
	return -1;
}

//resize field sizes to the specif data lenght
int clientsTableLenght(vector<Client> &vector, int idx) {
	int lenght = 0;
	int size = 0;
	int space = 3;

	switch (idx) {
	case 0:
		lenght = 4;
		for (int i = 0; i < vector.size(); i++) {
			if (vector.at(i).name.size() > lenght)
				lenght = max((int)vector.at(i).name.size(), lenght);
			else
				continue;
		}
		return lenght + space;
		break;
	case 1:
		return 9 + space;
		break;
	case 2:
		lenght = 1;
		for (int i = 0; i < vector.size(); i++) {
			if (to_string(vector.at(i).numPeople).size() > lenght)
				lenght = max((int)to_string(vector.at(i).numPeople).size(), lenght);
			else
				continue;
		}
		return lenght + space;
		break;
	case 3:
		lenght = 6;
		for (int i = 0; i < vector.size(); i++) {
			if (addressToString(vector.at(i).address).length() > lenght) {
				lenght = max((int)(addressToString(vector.at(i).address).length()), lenght);
			}
		}
		return lenght + space;
		break;
	case 4:
		lenght = 5;
		for (int i = 0; i < vector.size(); i++) {
			if (boughtPacksToString(vector.at(i).boughtPacks).length() > lenght) {
				lenght = max((int)(boughtPacksToString(vector.at(i).boughtPacks).length()), lenght);
			}
		}
		return lenght + space;
		break;
	}
}



void showClients(vector<Client> &clients) {

	const string line = "--------------------------------------------------------";;

	system("cls");

	loadAgencyInfo();

	cout << endl << line << endl << "\tLISTA DE CLIENTES" << endl << line << endl<< endl;


	cout << left << setw(clientsTableLenght(clients, 0)) << "NOME" << left << setw(clientsTableLenght(clients, 1)) << "NIF";
	cout << left << setw(clientsTableLenght(clients, 2)) << "N " << left << setw(clientsTableLenght(clients, 3)) << "MORADA";
	cout << left << setw(clientsTableLenght(clients, 4)) << "PACKS" << "DINHEIRO GASTO" << endl <<endl;

	for (int i = 0; i < clients.size(); i++) {
		cout << setw(clientsTableLenght(clients, 0)) << clients[i].name;
		cout << left << setw(clientsTableLenght(clients, 1)) << clients[i].nif;
		cout << left << setw(clientsTableLenght(clients, 2)) << clients[i].numPeople;
		cout << left << setw(clientsTableLenght(clients, 3)) << addressToString(clients[i].address);
		cout << left << setw(clientsTableLenght(clients, 4)) << boughtPacksToString(clients[i].boughtPacks);
		cout << left << setw(30) << clients[i].moneySpent << endl;
	}
	
	cout << endl;
	system("pause");

}
void newClient(vector<Client> &clients) {
	
	Client newClient;
	Address newClientAddress;

	const string line = "--------------------------------------------------------";;

	system("cls");

	loadAgencyInfo();

	cout << endl << line << endl << "\tNOVO CLIENTE" << endl << line << endl;
	cin.clear();
	cin.ignore();

	cout << "NOME:";
	getline(cin, newClient.name);

	
	cout << "NIF:";
	readInt(newClient.nif, 9);
	
	cout << "NUMERO PESSOAS AGREGADO FAMILIAR:";
	readInt(newClient.numPeople);

	cout << "MORADA:" << endl << "\tRUA:";
	getline(cin, newClientAddress.street);

	cout << "\tN PORTA:";
	readInt(newClientAddress.door);

	cout << "\tANDAR(-):";
	getline(cin, newClientAddress.floor);

	cout << "\tCODIGO POSTAL:";
	getline(cin, newClientAddress.postalCode);

	cout << "\tLOCALIDADE:";
	getline(cin, newClientAddress.location);

	newClient.address = newClientAddress;
	newClient.moneySpent = 0;

	clients.push_back(newClient);

	cout << endl << "CLIENTE INSERIDO COM SUCESSO!" << endl <<endl;

	system("pause");
}
void updateClient(vector<Client> &clients){

	int nif;
	vector<Client> newVect;

	const string line = "--------------------------------------------------------";;

	system("cls");

	loadAgencyInfo();

	cout << endl << line << endl << "\tALTERAR CLIENTE" << endl << line << endl;
	cin.clear();
	cin.ignore();

	cout << "NIF DO CLIENTE:";
	readInt(nif, 9);

	if (searchByNif(clients, nif) == -1) {
		cout << endl << "CLIENTE NAO ENCONTRADO!" << endl << endl;
		system("pause");
	}
	else {
		newVect.push_back(clients.at(searchByNif(clients, nif)));
		showClients(newVect);

		int option = 0;

		cout << "O QUE PRETENDE ALTERAR NESTE CLIENTE?" << endl << line << endl;
		cout << "1.NOME" << endl;
		cout << "2.NUMERO PESSOAS AGREGADO FAMILIAR" << endl;
		cout << "3.MORADA" << endl;
		cout << line << endl;
		cout << "OPCAO:";

		do {
			readInt(option);
		} while (option < 1 || option > 3);

		string newName;
		int newInt;
		Address newAddress;

			switch (option)
			{
			case 1:
				cout << endl << "NOVO NOME: ";
				getline(cin, newName);
				break;
			case 2:
				cout << endl << "NUMERO DE PESSOAS AGREGADO FAMILIAR: ";
				readInt(newInt);
				break;
			case 3:
				cout << "NOVA MORADA:" << endl << "\tRUA:";
				getline(cin, newAddress.street);

				cout << "\tN PORTA:";
				readInt(newAddress.door);

				cout << "\tANDAR(-):";
				getline(cin, newAddress.floor);

				cout << "\tCODIGO POSTAL:";
				getline(cin, newAddress.postalCode);

				cout << "\tLOCALIDADE:";
				getline(cin, newAddress.location);

				break;

			}

		cout << endl << endl << "TEM A CERTEZA QUE PRETENDE ALTERAR OS DADOS DESTE CLIENTE CLIENTE? (S/N) ";
		char c;
		if (yesOrNo(c)) {
			switch (option)
			{
			case 1:
				clients.at(searchByNif(clients, nif)).name = newName;
				break;
			case 2:
				clients.at(searchByNif(clients, nif)).numPeople = newInt;
				break;
			case 3:
				clients.at(searchByNif(clients, nif)).address = newAddress;
				break;
			}
		}

	}

}
void removeClient(vector<Client> &clients) {
	
	int nif;
	vector<Client> newVect;

	const string line = "--------------------------------------------------------";;

	system("cls");

	loadAgencyInfo();

	cout << endl << line << endl << "\tREMOVER CLIENTE" << endl << line << endl;
	cin.clear();
	cin.ignore();

	cout << "NIF DO CLIENTE:";
	readInt(nif, 9);
	if (searchByNif(clients, nif) == -1) {
		cout << endl << "CLIENTE NAO ENCONTRADO!" << endl << endl;
		system("pause");
	}
	else {
		newVect.push_back(clients.at(searchByNif(clients, nif)));
		showClients(newVect);

		char c;
		cout << endl << "TEM A CERTEZA QUE PRETENDE ELIMINAR ESTE CLIENTE? (S/N) ";
		if (yesOrNo(c)) {
			clients.erase(clients.begin() + searchByNif(clients, nif));
		}
		
	}
	

	

}
string boughtPacksToString(vector<int> boughtPacks) {

	string finalStr;

	if (boughtPacks.size() == 0)
		return ";";
	else if (boughtPacks.size() == 1){

		return to_string(boughtPacks[0]);
	}
	else {
		for (int i = 0; i < boughtPacks.size(); i++) {
			if (i == 0) {
				finalStr += to_string(boughtPacks[i]);
			}
			else {
				finalStr += "; ";
				finalStr += to_string(boughtPacks[i]);
			}
		}
		return finalStr;
	}

}
vector<int> stringToBoughtPacks(string strBoughtPacks) {

	string pack;
	vector<int> boughtPacks = {};

	if (strBoughtPacks == ";") {
		return boughtPacks;
	}

	for (int i = 0; i <= strBoughtPacks.length(); i++) {

		if (i == strBoughtPacks.length()) {

			boughtPacks.push_back(stoi(pack));
			return boughtPacks;

		}
		else if(strBoughtPacks[i] == ';'){
			boughtPacks.push_back(stoi(pack));
			pack = "";
		}
		else {
			pack += strBoughtPacks[i];
		}
	}

}
