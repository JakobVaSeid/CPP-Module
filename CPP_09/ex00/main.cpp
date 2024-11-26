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

void search_map(std::map<std::string, float> &map1, std::map<std::string, float> &map2) {
    std::map<std::string, float>::iterator it1;
    for (it1 = map1.begin(); it1 != map1.end(); ++it1) {
        std::map<std::string, float>::iterator it2 = map2.lower_bound(it1->first);
        if (it2 != map2.begin() && (it2 == map2.end() || map2.key_comp()(it1->first, it2->first))) {
            --it2;
        }
        if (it2 != map2.end() && (map2.key_comp()(it1->first, it2->first))) {
            std::cout << it2->first << " => " << calculate(it1->second, it2->second) <<std::endl;
        } else {
            std::cout << it2->first << " => " << calculate(it1->second, it2->second) <<std::endl;
        }
    }
}


//check if try catch is implemented correctly

int main (int argc, char **argv){
    
    if(argc == 2) {
        std::map<std::string, float> dataMap;
        std::map<std::string, float> dataMap1;
        /* try { */
            if(safe_data(argv[1], dataMap))
                return (1);
            if(safe_data("data.csv", dataMap1))
                return (1);
            search_map(dataMap, dataMap1);
        /* } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        } */
    }
    else
        std::cerr << "Error: Wrong amount of arguments" << std::endl;
    return (0);
}