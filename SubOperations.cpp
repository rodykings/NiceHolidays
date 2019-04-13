#include "pch.h"
#include "SubOperations.h"

using namespace std;


string placesToString(vector<string> places) {

	string finalStr;

	for (int i = 0; i < (int)places.size(); i++) {

		if (i == 0) {
			if ((int)places.size() == 1) {
				finalStr += places[i];
				return finalStr;
			}
			else 
				finalStr += places[i] + " - ";
	
		}
		else if (i == 1)
		{
			finalStr += places[i];
		}
		else 
		{
			finalStr += ", ";
			finalStr += places[i];
		}
	}

	return finalStr;
}
vector<string> stringToPlaces(string places) {
	
	vector<string> finalVector;
	string newPlace;

	for (int i = 0; i <= places.length(); i++) {

		if (i == (places.length())) {
			finalVector.push_back(newPlace);
			return finalVector;
		}
		else if (places[i] == ',' || places[i] == '-' || places[i] == '–') {
			
			while (newPlace.back() == ' ') {
				newPlace.erase(find(newPlace.end() - 1, newPlace.end(), ' '));
			}
			while (newPlace[0] == ' ') {
				newPlace.erase(find(newPlace.begin(), newPlace.begin()+1, ' '));
			}

			finalVector.push_back(newPlace);
			newPlace = "";
		}
		else {
			newPlace += places[i];
		}
	}

	return finalVector;
}
void readInt(int &myInt) {

	cin >> myInt;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "INFORMACAO INVALIDA! DIGITE DE NOVO:";
		cin >> myInt;
	}

	cin.clear();
	cin.ignore();
}
void readInt(int &myInt, int size) {

	cin >> myInt;
	string str = to_string(myInt);
	

	while (cin.fail() || (str.length() != size) ) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "INFORMACAO INVALIDA! DIGITE DE NOVO:";
		cin >> myInt;
		str = to_string(myInt);
	}

	cin.clear();
	cin.ignore();
}
void readDouble(double &myDouble) {
	cin >> myDouble;
	string str = to_string(myDouble);


	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "INFORMACAO INVALIDA! DIGITE DE NOVO:";
		cin >> myDouble;
		str = to_string(myDouble);
	}
	cin.clear();
	cin.ignore();
}
bool yesOrNo(char &c) {
	
	cin >> c;
	while (cin.fail()) {
		cin >> c;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "INFORMACAO INVALIDA! DIGITE DE NOVO:";
	}
		
	if (c == 'S' || c == 's') 
		return true;
	else
		return false;
	
}
