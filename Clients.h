#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Address.h"
#include "Agency.h"

using namespace std;

typedef struct {
	string name;
	int nif;
	int numPeople;
	Address address;
	vector<int> boughtPacks;
	double moneySpent;
}Client;

int searchByNif(vector<Client> &vector, int nif);
int clientsTableLenght(vector<Client> &vector, int idx);
void showClients(vector <Client> &clients);
void newClient(vector<Client> &clients);
void updateClient(vector<Client> &clients);
void removeClient(vector<Client> &clients);
string boughtPacksToString(vector<int> boughtPacks);
vector<int> stringToBoughtPacks(string strBoughtPacks);




