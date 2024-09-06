#include "replace.hpp"

std::string replace (std::string str, std::string s1, std::string s2){
    int i;
    if(str.empty() || s1.empty() || s2.empty())
        return (0);
    i = str.find(s1);
    while(i != (int)std::string::npos){
        str.erase(i, s1.length());
        str.insert(i, s2);
        i += s1.length();
        i = str.find(s1, i);
    }
    return str;
}

int main (int argc, char **argv)
{
    if(argc == 4)
    {
        std::string filename = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        std::string fileline;
        std::string replacement;

        if(!argv[1] || !argv[2] || !argv[3])
            std::cout << "Wrong Input" << std::endl;
        std::ofstream newFile("newFile.txt");
        if(!newFile){
            std::cout << "Something is wrong with the new file!" << std::endl;
            return (1);
        }
        std::ifstream file(filename.c_str());
        if(!file){
            std::cout << "Something is wrong with the file!" << std::endl;
            return (1);
        }
        if(file.is_open()){
            while(file.good())
            {
            std::getline(file, fileline);
            replacement = replace(fileline, s1, s2);
            newFile << replacement << std::endl;
            }
        }
        file.close();
        newFile.close();
    }
    else
        std::cout << "Wrong Input!" << std::endl;
}