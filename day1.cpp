#include <iostream>
#include <fstream>
#include <sstream>

std::string parse_input(std::string str)
{
    return str;
}

int main(void)
{
    std::ifstream file("input.txt");
    std::stringstream buffer;
    buffer << file.rdbuf();

    std::cout << parse_input(buffer.str()) << std::endl;
}