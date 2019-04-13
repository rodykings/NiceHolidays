#pragma once
#include "Packs.h"
#include "Clients.h"
#include <algorithm> 
#include <sstream>



using namespace std;

string placesToString(vector<string> places);
vector<string> stringToPlaces(string places);
void readInt(int &myInt);
void readInt(int &myInt, int size);
void readDouble(double &myDouble);
bool yesOrNo(char &c);
int searchByNif(vector<Client> &vector, int nif);

