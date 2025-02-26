#pragma once

#include <iostream>
#include <map>
#include <exception>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

struct Date {
    std::string day;
    std::string month;
    std::string year;
};

bool isLeapYear(int year);
bool check_day(Date &date);
bool check_month(Date &date);
bool check_year(Date &date);
bool check_date(std::string line);
void check_value (long long value, int flag);
int safe_data (std::string filename, std::map<std::string, float> &dataMap);
void search_map(std::string date, float num, std::map<std::string, float> &map);