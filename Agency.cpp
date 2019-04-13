#include "pch.h"
#include "Agency.h"

void loadAgencyInfo() {

	Agency agency;

	ifstream agencyFile;
	string line;

	agencyFile.open("agency.txt");

	if (agencyFile.is_open())
	{
		for (int i = 0; i <= 5; i++)
		{
			getline(agencyFile, line);
			switch (i)
			{
			case 0:
				agency.name = line;
			case 1:
				agency.nif = line;
			case 2:
				agency.url = line;
			case 3:
				agency.clientPath = line;
			case 4:
				agency.packagesPath = line;

			default:
				break;
			}
			cout << line << endl;

		}
		agencyFile.close();
	}
}