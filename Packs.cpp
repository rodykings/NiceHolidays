#include "pch.h"
#include "Packs.h"


int searchById(vector<Pack> &vector, int id) {
	for (int i = 0; i < vector.size(); i++) {
		if (abs(vector[i].id) == id) {
			return i;
		}
	}
	return -1;
}
vector<Pack> searchByDestination(vector<Pack> &packs) {

	vector<Pack> newPack;
	int packId;
	string place;

	cout << endl << "DIGITE O LOCAL: ";
	cin >> place;
	transform(place.begin(), place.end(), place.begin(), ::tolower);

	string packPlace;

	for (int i = 0; i < packs.size(); i++) {
		for (int u = 0; u < packs[i].places.size(); u++) {
			packPlace = packs[i].places[u];
			transform(packPlace.begin(), packPlace.end(), packPlace.begin(), ::tolower);
			if (place.find(packPlace) != string::npos) {
				newPack.push_back(packs[i]);
			}
		}
	}
	if (newPack.size() == 0) {
		cout << endl << "NAO FORAM ENCONTRADOS PACOTES PARA ESSE DESTINO!";
	}
	else
		showPacks(newPack);

	return newPack;
	
}
int packTableLenght(vector<Pack> &vector, int idx) {
	int lenght = 0;
	int size = 0;
	int space = 3;

	switch (idx) {
	case 0:
		for (int i = 0; i < vector.size(); i++) {
			if ((int)to_string(vector.at(i).id).size() > lenght)
				lenght = max((int)to_string(vector.at(i).id).size(), lenght);
			else
				continue;
		}
		return lenght + space;
		break;
	case 1:
		return 10 + space;
		break;

	case 2:
		lenght = 8;
		for (int i = 0; i < vector.size(); i++) {
			if ((int)to_string(vector.at(i).pricePerson).size() > lenght)
				lenght = max((int)to_string(vector.at(i).pricePerson).size(), lenght);
			else
				continue;
		}
		return lenght + space;
		break;

	case 3:
		lenght = 5;

		for (int i = 0; i < vector.size(); i++) {
			if ((int)to_string(vector[i].signMax).size() > lenght) {
				lenght = max((int)to_string(vector[i].signMax).size(), lenght);
			}
		}
		return lenght + space;
		break;



	case 4:
		lenght = 9;

		for (int i = 0; i < vector.size(); i++) {
			if ((int)to_string(vector[i].soldAmount).size() > lenght) {
				lenght = max((int)to_string(vector[i].soldAmount).size(), lenght);
			}
		}
		return lenght + space;
		break;
	}
}
void showPacks(vector<Pack> packs) {

	const string line = "--------------------------------------------------------";

	system("cls");

	loadAgencyInfo();

	cout << endl << line << endl << "\tLISTA DE PACKS" << endl << line << endl << endl;

	cout << left << setw(packTableLenght(packs, 0)) << "ID" << left << setw(packTableLenght(packs, 1)) << "DATA INICIO";
	cout << left << setw(packTableLenght(packs, 1)) << "DATA FIM " << left << setw(packTableLenght(packs, 2)) << "PRECO/P";
	cout << left << setw(packTableLenght(packs, 3)) << "VAGAS" << left << setw(packTableLenght(packs, 4)) << "COMPRADOS";
	cout << left << setw(1) << "LOCAIS" << endl << endl;

	for (int i = 0; i < packs.size(); i++) {

		cout << left << setw(packTableLenght(packs, 0)) << packs[i].id;
		cout << left << setw(packTableLenght(packs, 1)) << dateToString(packs[i].beginDate);
		cout << left << setw(packTableLenght(packs, 1)) << dateToString(packs[i].endDate);
		cout << left << setw(packTableLenght(packs, 2)) << packs[i].pricePerson;
		cout << left << setw(packTableLenght(packs, 3)) << packs[i].signMax;
		cout << left << setw(packTableLenght(packs, 4)) << packs[i].soldAmount;
		cout << left << placesToString(packs[i].places);

		cout << endl;
	}

	cout << endl;
	system("pause");

}
void newPack(vector<Pack> &packs) {

	Pack newPack;

	const string line = "--------------------------------------------------------";;

	system("cls");
	string mainPlace;
	int numPlaces;
	string subPlace;

	loadAgencyInfo();

	cout << endl << line << endl << "\tNOVO PACK" << endl << line << endl;
	cin.clear();
	cin.ignore();

	newPack.id = packs.size() + 1;

	cout << "LOCAL PRINCIPAL:";
	getline(cin, mainPlace);
	newPack.places.push_back(mainPlace);
	
	cout << "N DE LOCAIS A VISITAR:";
	readInt(numPlaces);


	for (int i = 1; i <= numPlaces; i++) {
		cout << to_string(i) + ". LOCAL A VISTAR:";
		getline(cin, subPlace);
		newPack.places.push_back(subPlace);
		subPlace = "";

	}

	cout << "DATA INICIO:" << endl << "\tDIA:";
	readInt(newPack.beginDate.day);

	cout << "\tMES:";
	readInt(newPack.beginDate.month);

	cout << "\tANO:";
	readInt(newPack.beginDate.year);

	cout << "DATA FIM:" << endl << "\tDIA:";
	readInt(newPack.endDate.day);

	cout << "\tMES:";
	readInt(newPack.endDate.month);

	cout << "\tANO:";
	readInt(newPack.endDate.year);

	cout << "CUSTO POR PESSOA:";
	readDouble(newPack.pricePerson);

	cout << "NUMERO DE VAGAS:";
	readInt(newPack.signMax);

	newPack.soldAmount = 0;


	packs.push_back(newPack);

	cout << endl << "PACK INSERIDO COM SUCESSO!" << endl << endl;	
	system("pause");
	
}
void updatePack(vector<Pack> &packs) {
	
	int id;
	vector<Pack> newVect;

	const string line = "--------------------------------------------------------";

	system("cls");

	loadAgencyInfo();

	cout << endl << line << endl << "\tALTERAR PACOTE" << endl << line << endl;
	cin.clear();
	cin.ignore();

	cout << "ID DO PACOTE:";
	readInt(id);

	if (searchById(packs, id) == -1) {
		cout << endl << "PACK NAO ENCONTRADO!" << endl << endl;
		system("pause");
	}
	else {
		newVect.push_back(packs.at(searchById(packs, id)));
		showPacks(newVect);

		int option = 0;

		cout << "O QUE PRETENDE ALTERAR NESTE PACOTE?" << endl << line << endl;
		cout << "1.DATA DE INICIO" << endl;
		cout << "2.DATA DE FIM" << endl;
		cout << "3.PRECO POR PESSOA" << endl;
		cout << "4.NUMERO DE VAGAS" << endl;
		cout << line << endl;
		cout << "OPCAO:";

		do {
			readInt(option);
		} while (option < 1 || option > 4);

		Date newBeginDate;
		Date newEndDate;
		double newPricePerson;
		int newSignMax;

		switch (option)
		{
		case 1:
			cout << "NOVA DATA INICIO:" << endl << "\tDIA:";
			readInt(newBeginDate.day);

			cout << "\tMES:";
			readInt(newBeginDate.month);

			cout << "\tANO:";
			readInt(newBeginDate.year);

			
		case 2:
			cout << "NOVA DATA FIM:" << endl << "\tDIA:";
			readInt(newEndDate.day);

			cout << "\tMES:";
			readInt(newEndDate.month);

			cout << "\tANO:";
			readInt(newEndDate.year);
			break;
		case 3:
			cout << "NOVO CUSTO POR PESSOA:";
			readDouble(newPricePerson);

			break;
		case 4:
			cout << "NOVO NUMERO DE VAGAS:";
			readInt(newSignMax);
			break;


		}

		cout << endl << endl << "TEM A CERTEZA QUE PRETENDE ALTERAR ESTE PACOTE ? (S/N) ";
		char c;
		if (yesOrNo(c)) {
			switch (option)
			{
			case 1:
				packs.at(searchById(packs, id)).beginDate = newBeginDate;
				break;
			case 2:
				packs.at(searchById(packs, id)).endDate = newEndDate;
				break;
			case 3:
				packs.at(searchById(packs, id)).pricePerson = newPricePerson;
				break;
			case 4:
				packs.at(searchById(packs, id)).signMax = newSignMax;
				break;
			}

			cout << endl << endl << "PACOTE ALTERADO COM SUCESSO! " << endl << endl;
			system("pause");
		}

	}

}
void removePack(vector<Pack> &packs) {

	int id;
	vector<Pack> newVect;

	const string line = "--------------------------------------------------------";;

	system("cls");

	loadAgencyInfo();

	cout << endl << line << endl << "\tREMOVER PACOTE" << endl << line << endl;
	cin.clear();
	cin.ignore();

	cout << "ID DO PACOTE:";
	readInt(id);
	if (searchById(packs, id) == -1) {
		cout << endl << "PACOTE NAO ENCONTRADO" << endl << endl;
		system("pause");
	}
	else {
		newVect.push_back(packs.at(searchById(packs, id)));
		showPacks(newVect);

		char c;
		cout << endl << "TEM A CERTEZA QUE PRETENDE ELIMINAR ESTE PACOTE? (S/N) ";
		if (yesOrNo(c)) {
			packs.erase(packs.begin() + searchById(packs, id));
			cout << endl << "PACOTE REMOVIDO COM SUCESSO!" <<endl  << endl ;
		}
		system("pause");
		
	}

}
void buyPack(vector<Client> &clients, vector<Pack> &packs) {

	vector<Client> newVect;
	const string line = "----------------------------------------------------------";

	int packId;
	int nif;
	int clientId;

	system("cls");

	loadAgencyInfo();

	cout << endl << line << endl << "\tCOMPRAR PACOTE" << endl << line << endl;
	cin.clear();
	cin.ignore();

	cout << "NIF DO CLIENTE:";
	readInt(nif, 9);
	if (searchByNif(clients, nif) == -1) {
		cout << endl << "CLIENTE NAO ENCONTRADO!" << endl << endl;
		system("pause");
	}
	else {
		clientId = searchByNif(clients, nif);
		newVect.push_back(clients.at(clientId));
		showClients(newVect);

		char c;
		cout << endl << "TEM A CERTEZA QUE PRETENDE COMPRAR UM PACOTE PARA ESTE CLIENTE? (S/N) ";
		if (yesOrNo(c)) {

			vector<Pack> selectedPacks = searchByDestination(packs);
			if (selectedPacks.size() == 0) {
				
				cout << endl << "NAO EXISTE NENHUM PACOTE COM ESSE DESTINO! "<< endl << endl;
				system("pause");

			}
			else {
				showPacks(selectedPacks);

				cout << endl << "DIGITE O ID DO PACOTE: ";
				readInt(packId);


				if (searchById(packs, packId) == -1) {
					cout << endl << "NAO EXISTE ESSE PACOTE! ";
				}
				else {
					packId = searchById(packs, packId);
					if (packs[packId].id < 0) {
						cout << endl << "NAO EXISTEM VAGAS DISPONIVEIS PARA ESTE PACOTE!" << endl << endl;
						system("pause");
					}
					else if (clients[clientId].numPeople + packs[packId].soldAmount <= packs[packId].signMax) {

						double totalPrice = (packs[packId].pricePerson * clients[clientId].numPeople);
						
						cout << endl << line;
						cout << endl << "PACK ID: " << packs[packId].id;
						cout << endl << "LOCAIS: " << placesToString(packs[packId].places);
						cout << endl << "DATA INICIO: " << dateToString(packs[packId].beginDate);
						cout << endl << "DATA FIM: " << dateToString(packs[packId].endDate);
						cout << endl << "PRECO/PAX: " << packs[packId].pricePerson << endl << line << endl;
						cout << endl << "PRECO TOTAL: " << fixed << setprecision(2) << totalPrice;
						cout << endl << line;

						char c;
						cout << endl << "PRETENDE COMPRAR ESTE PACOTE? (S/N) ";
						if (yesOrNo(c)) {
							clients[clientId].moneySpent += totalPrice;
							clients[clientId].boughtPacks.push_back(packs[packId].id);
							packs[packId].soldAmount += clients[clientId].numPeople;

							if (packs[packId].soldAmount == packs[packId].signMax) {
								packs[packId].id *= -1;
							}

							cout << endl << "PACOTE COMPRADO COM SUCESSO!" << endl << endl;
							system("pause");
						}
					}
					else
					{
						cout << endl << "NAO EXISTEM VAGAS DISPONIVEIS PARA ESTE PACOTE!" << endl << endl;
						system("pause");
					}
				}
			}
			
		}

	}
	

	

	
}