#pragma once
#include <string>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Date.h"
#include "SubOperations.h"
#include "Clients.h"

using namespace std;

typedef struct{
	int id;
	vector<string> places;
	Date beginDate;
	Date endDate;
	double pricePerson;
	int signMax; 
	int soldAmount;
}Pack;

int searchById(vector<Pack> &vector, int id);
vector<Pack> searchByDestination(vector<Pack> &packs);
int packTableLenght(vector<Pack> &vector, int idx);
void showPacks(vector<Pack> packs);
void newPack(vector<Pack> &packs);
void updatePack(vector<Pack> &packs);
void removePack(vector<Pack> &packs);
void buyPack(vector<Client> &clients, vector<Pack> &packs);




