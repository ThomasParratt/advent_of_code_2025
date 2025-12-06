#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void print_vec(std::vector<std::string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}

void find_pairs(const std::vector<std::string>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::vector<std::string> range_ends;
        std::stringstream ss(vec[i]);
        std::string token;
        while (std::getline(ss, token, '-')) 
        {
            range_ends.push_back(token);
        }
        print_vec(range_ends);
        
    } 
}

std::vector<std::string> get_ranges(const std::string& input)
{
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ',')) 
    {
        result.push_back(token);
    }
    return result;
}

int main(void)
{
    std::ifstream file("day2.txt");
    std::stringstream buffer;
    buffer << file.rdbuf();

    find_pairs(get_ranges(buffer.str()));
}