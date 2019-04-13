#include "pch.h"
#include "Address.h"

Address stringToAddress(string address) {

	Address finalAddress;
	string door = "";

	int pos = 0;
	for (int i = 0; i <= address.length(); i++)
	{
		if (address[i] == '/')
		{
			pos++;
		}
		else if (address[i] == ' ' && (address[i + 1] == '/' || address[i - 1] == '/')) {
			continue;
		}
		else
		{
			switch (pos)
			{
			case 0:
				finalAddress.street += address[i];
				break;
			case 1:
				door += address[i];
				break;
			case 2:
				finalAddress.floor += address[i];
				break;
			case 3:
				finalAddress.postalCode += address[i];
				break;
			case 4:
				finalAddress.location += address[i];
				break;
			default:
				continue;
				break;
			}

		}
	}

	finalAddress.door = stoi(door);
	return finalAddress;

}
string addressToString(Address address) {

	string del = " / ";
	return address.street + del + to_string(address.door) + del + address.floor + del + address.postalCode + del + address.location;
}