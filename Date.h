#pragma once
#include <string>
#include "pch.h"

using namespace std;

typedef struct {
	int day;
	int month;
	int year;
}Date;

string dateToString(Date date);
Date stringToDate(string date);
void verifyDates(Date beginDate, Date endDate);