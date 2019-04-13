#pragma once
#include <iostream>
#include <string>
#include "Address.h"
#include <fstream>


using namespace std;

typedef struct {
	string name;
	string nif;
	Address address;
	string url;
	string clientPath;
	string packagesPath;
}Agency;

void loadAgencyInfo();