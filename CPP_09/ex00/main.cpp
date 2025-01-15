#include "BitcoinExchange.hpp"

void print_map(std::map<std::string, float> &map) {
    std::map<std::string, float>::iterator it;
        for(it = map.begin(); it != map.end(); it++) {
            std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        }
}

float calculate(float d_value, float i_value) {
    float result;

    result = d_value * i_value;
    return (result);
}

int convert_strtoi(std::string format) {
    std::stringstream str(format);
    int num;
    str >> num;
    return (num);
}

void search_map(std::string date, float num, std::map<std::string, float> &map) {
    std::map<std::string, float>::iterator it = map.lower_bound(date);
    it--;
    if (it != map.end()) {
        std::cout << it->first << " => " << num << " = "<< calculate(it->second, num) << std::endl;
    } else {
        std::cout << "Date not found" << std::endl;
    }
}

//check if try catch is implemented correctly

int main (int argc, char **argv){
    
    try {
        if(argc == 2) {
            std::map<std::string, float> dataMap;
                if(safe_data("data.csv", dataMap))
                    return (1);
                if(safe_data(argv[1], dataMap))
                    return (1);
        }
        else {
            std::cerr << "Error: Wrong amount of arguments" << std::endl;
            return (1);
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (1);
    }
    return (0);
}