// NiceHolidays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <vector>
#include "Operations.h"
#include "Menu.h"
#include "Agency.h"
#include "Clients.h"
#include "Packs.h"

using namespace std;

int main()
{
	Agency agency;
	vector<Client> clients;
	vector<Pack> packs;
	int lastPackId = 0;

	loadClients(clients);
	loadPacks(packs);
	Menu(agency, clients, packs, lastPackId);

	return 0;
}