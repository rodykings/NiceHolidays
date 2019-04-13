#include "pch.h"
#include "Date.h"


//convert Date struct to string
string dateToString(Date date) {

	string strDate;

	strDate += to_string(date.year);

	strDate += "/";

	if (date.month < 10)
		strDate += "0";
	strDate += to_string(date.month);

	strDate += '/';

	if (date.day < 10)
		strDate += "0";
	strDate += to_string(date.day);

	return strDate;
}
Date stringToDate(string date) {

	Date finalDate;
	string y, m, d;

	int counter = 0;

	for (int i = 0; i <= date.length(); i++)
	{
		if (date[i] == '/')
		{
			counter++;
		}
		else
		{
			switch (counter)
			{
			case 0:
				y += date[i];
				break;
			case 1:
				m += date[i];
				break;
			case 2:
				d += date[i];
				break;
			default:
				continue;
				break;
			}
		}
	}
	finalDate.year = stoi(y);
	finalDate.month = stoi(m);
	finalDate.day = stoi(d);

	return finalDate;
}
bool AreDatesValid(Date beginDate, Date endDate) {
	return true;
}