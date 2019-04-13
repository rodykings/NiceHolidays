#include "pch.h"
#include "Menu.h"

void Menu(Agency &agency, vector<Client> &clients, vector<Pack> &packs, int &lastPackId) {

	system("cls");

	const string line = "----------------------------------------------------------";

	int option;
	bool fail = false;

	do {
		fail = false;

		loadAgencyInfo();

		cout << endl << line << endl << "\tMENU" << endl << line << endl;
		cout << '|' << "OPERACOES       " << " | " << "CLIENTES         " << " | " << "PACOTES         " << " | " << endl;
		cout << line << endl;
		cout << '|' << "1.COMPRAR PACOTE" << " | " << "4.NOVO CLIENTE   " << " | " << "7.NOVO PACOTE   " << " | " << endl;
		cout << '|' << "2.VER CLIENTES  " << " | " << "5.ALTERAR CLIENTE" << " | " << "8.ALTERAR PACOTE" << " | " << endl;
		cout << '|' << "3.VER PACOTES   " << " | " << "6.REMOVER CLIENTE" << " | " << "9.REMOVER PACOTE" << " | " << endl;
		cout << line << endl;
		cout << '|' << "CTR+Z ou 10" << "| - SAIR E GUARDAR" << endl << endl;

		cout << "SELECIONE UMA OPCAO:";

		cin >> option;

		if (cin.fail()) {
			if (cin.eof()) {
				exit(0);
			}
			cin.clear();
			cin.ignore();
			system("cls");
			fail = true;
		}
		else if (option <= 0 || option > 10) {
			system("cls");
			fail = true;
		}
		else
			fail = false;

	} while (fail);

	int nif;
	vector<Client> newVect;

	switch (option)
	{
		//COMPRAR PACOTE
	case 1:
		buyPack(clients, packs);
		update(packs, clients);
		Menu(agency, clients, packs, lastPackId);
		break;
		//VER clients
	case 2:
		showClients(clients);
		Menu(agency, clients, packs, lastPackId);
		break;
		//VER PACOTES
	case 3:
		showPacks(packs);
		Menu(agency, clients, packs, lastPackId);
		break;
		//NOVO CLIENTE
	case 4:
		newClient(clients);
		update(packs, clients);
		Menu(agency, clients, packs, lastPackId);
		//ALTERAR CLIENTE
	case 5:
		updateClient(clients);
		update(packs, clients);
		Menu(agency, clients, packs, lastPackId);
		break;
		//REMOVER CLIENTE
	case 6:
		removeClient(clients);
		update(packs, clients);
		Menu(agency, clients, packs, lastPackId);
		break;
		//NOVO PACOTE
	case 7:
		newPack(packs);
		update(packs, clients);
		Menu(agency, clients, packs, lastPackId);
		break;
		//ALTERAR PACOTE
	case 8:
		updatePack(packs);
		update(packs, clients);
		Menu(agency, clients, packs, lastPackId);
		break;
		//REMOVER PACOTE
	case 9:
		removePack(packs);
		update(packs, clients);
		Menu(agency, clients, packs, lastPackId);
		break;
		//exit
	case 10:
		update(packs, clients);
		exit(0);
		break;
	default:
		break;
	}
}