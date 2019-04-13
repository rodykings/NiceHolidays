#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include "Agency.h"
#include "Clients.h"
#include "Packs.h"
#include "SubOperations.h"

using namespace std;


void loadClients(vector<Client> &clients);
void storeClients(vector<Client> &clients);
void loadPacks(vector<Pack> &packs);
void storePacks(vector<Pack> &packs);
void update(vector<Pack> &packs, vector<Client> &clients);