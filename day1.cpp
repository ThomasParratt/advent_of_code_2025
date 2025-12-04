#include <iostream>
#include <fstream>
#include <sstream>

int get_result(std::string str)
{
    return 0;
}

int main(void)
{
    std::ifstream file("input.txt");
    std::stringstream buffer;
    buffer << file.rdbuf();

    std::cout << buffer.str() << std::endl;
    std::cout << get_result(buffer.str()) << std::endl;
}