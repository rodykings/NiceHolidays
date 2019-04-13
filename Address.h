#pragma once
#include <string>
#include "pch.h"

using namespace std;

typedef struct{
	string street;
	int door;
	string floor;
	string postalCode;
	string location;
}Address;

Address stringToAddress(string address);
string addressToString(Address address);