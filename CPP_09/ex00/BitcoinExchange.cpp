#include "BitcoinExchange.hpp"

bool isLeapYear(int year) {
    if (year % 4 != 0) {
        return (false);
    } else if (year % 100 != 0) {
        return (true);
    } else if (year % 400 != 0) {
        return (false);
    } else {
        return (true);
    }
}

bool check_day(Date &date) {
    if(date.month == "01" ||  date.month == "03" || date.month == "05" || date.month == "07" || date.month == "08" || date.month == "10" || date.month == "12")
    {
        std::stringstream s_day(date.day);
        int day;
        s_day >> day;

        if(day > 31 || day <= 0)
            return (false);
        
    }
    else if(date.month == "02" ||  date.month == "04" || date.month == "06" || date.month == "09" || date.month == "11")
    {
        std::stringstream s_day(date.day);
        std::stringstream s_year(date.year);
        int day;
        int year;
        s_day >> day;
        s_year >> year;
        if(day > 30 || day <= 0)
            return (false);
        if(date.month == "02") {
            if(isLeapYear(year) && day > 29)
                return (false);
            else if (!isLeapYear(year) && day > 28)
                return (false);
        }
    }
    return (true);
}

bool check_month(Date &date) {
    std::stringstream s_month(date.month);
    int month;

    s_month >> month;

    if(month > 12 || month < 1)
        return (false);
    return (true);
}

bool check_year(Date &date) {
    std::stringstream s_year(date.year);
    int year;

    s_year >> year;

    if(year < 2009)
        return (false);
    return (true);
}

bool check_date(std::string line) {
    Date date;

    date.year = line.substr(0, 4);
    date.month = line.substr(5, 2);
    date.day = line.substr(8, 2);

    if(date.year.length() != 4 || date.month.length() != 2 || date.day.length() != 2) {
        throw std::runtime_error ("Error: Wrong date format");
    }
    if(!check_day(date) || !check_month(date) || !check_year(date)) {
        throw std::runtime_error ("Error: Invalid date");
    }
    //std::cout << "Day: " << date.day << " Month: " << date.month << " Year: " << date.year << std::endl;

    return (0);
}

//check if int or float return true if it is
bool valid_num(std::string num) {
    int dot = 0;
    for (size_t i = 0; i < num.length(); i++) {
        if(num[i] == '.') {
            dot++;
            if(dot > 1)
                return (false);
        }
        if(num[i] < '0' || num[i] > '9') {
            if(num[i] != '.')
                return (false);
        }
    }
    return (true);
}



bool check_format1(std::string line) {
    for (int i = 0; i < 10; i++) {
        if(i == 4 || i == 7) {
            if(line[i] != '-')
                return (false);
            continue;
        }
        if(line[i] < '0' || line[i] > '9')
            return (false);
    }
    if(line[10] != ' ' || line[11] != '|' || line[12] != ' ')
        return (false);
    if(!valid_num(line.substr(13, line.length())))
        return (false);
    return (true);
}

bool check_format2(std::string line) {
    for (int i = 0; i < 10; i++) {
        if(i == 4 || i == 7) {
            if(line[i] != '-')
                return (false);
            continue;
        }
        if(line[i] < '0' || line[i] > '9')
            return (false);
    }
    if(line[10] != ',')
        return (false);
    if(!valid_num(line.substr(11, line.length())))
        return (false);
    return (true);
}


bool check_value (long long value) {
    if(value < 0 || value > 2147483647)
        return (false);
    return (true);
}

int check_first_line(std::string line) {
    if (line == "date | value") {
        return (1);
    }
    else if (line == "date,exchange_rate") {
        return (2);
    }
    return (0);
}

int safe_data (std::string filename, std::map<std::string, float> &dataMap) {
    std::ifstream file(filename.c_str());
    int flag = 0;
    if(!file) {
        throw std::runtime_error ("Error: File couldn't be opend");
    }

    std::string line;
    std::getline(file, line);
    flag = check_first_line(line);
    if(!flag)
        throw std::runtime_error("Wrong format!");
    while(std::getline(file, line)) {
        if (line == "date | value") {
            flag = 1;
            continue;
        }
        else if (line == "date,exchange_rate") {
            flag = 2;
            continue;
        }
        try {
            if(flag == 1) {
                if(!check_format1(line)) {
                    throw std::runtime_error ("Error: Bad input => " + line);
                }
                std::string date, number, stash;
                std::stringstream ss(line);
                std::getline(ss >> std::ws, date, ' ');
                check_date(date);
                std::getline(ss >> std::ws, stash, '|');
                std::getline(ss >> std::ws, number);

                float num = atof(number.c_str());
                long long num1 = atol(number.c_str());
                dataMap[date] = num;
                if(!check_value(num1))
                    throw std::runtime_error ("Error: Value out of range");
            }
            else if (flag == 2) {
                if(!check_format2(line))
                    throw std::runtime_error ("Error: Bad input");
                std::string date, number, stash;
                std::stringstream ss(line);
                std::getline(ss >> std::ws, date, ',');
                check_date(date);
                std::getline(ss >> std::ws, number);

                float num = atof(number.c_str());
                dataMap[date] = num;
                if(!check_value(num))
                    throw std::runtime_error ("Error: Value out of range");
            }
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    file.close();
    return (0);
}