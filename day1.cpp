#include <iostream>
#include <fstream>
#include <sstream>

int get_amount(std::string str, int i)
{
    std::string amount_str;
    int amount_i = 0;
    int res = 0;
    for (int idx = i; idx != '\n'; idx++)
    {
        amount_str[amount_i] = str[idx];
        amount_i++;
    }
    try 
    {
        res = std::stoi(amount_str);
    }
    catch (const std::invalid_argument& e) 
    {
        std::cerr << "Error: invalid argument\n";
    }
    catch (const std::out_of_range& e) 
    {
        std::cerr << "Error: number out of range\n";
    }
    return res;
}

int move_left(int dial, int amount)
{
    dial -= amount;
    if (dial < 0)
    {
        dial = 100 + dial;
    }
    return dial;
}

int move_right(int dial, int amount)
{
    dial += amount;
    if (dial > 99)
    {
        dial = 0 + (dial - 100);
    }
    return dial;
}

int get_result(std::string str)
{
    int dial = 50;
    int amount;
    for (int i = 0; i < str.length(); i++)
    {
        //std::cout << "str[i] = " << str[i] << std::endl;
        if (str[i] == 'L')
        {
            //std::cout << "L" << std::endl;
            amount = get_amount(str, i + 1);
            //std::cout << "amount = " << amount << std::endl;
            dial = move_left(dial, amount);
            //std::cout << "dial = " << dial << std::endl;
        }
        if (str[i] == 'R')
        {
            //std::cout << "R" << std::endl;
            amount = get_amount(str, i + 1);
            //std::cout << "amount = " << amount << std::endl;
            dial = move_right(dial, amount);
            //std::cout << "dial = " << dial << std::endl;
        }
    }
    return dial;
}

int main(void)
{
    std::ifstream file("test.txt");
    std::stringstream buffer;
    buffer << file.rdbuf();

    std::cout << buffer.str() << std::endl << std::endl;
    std::cout << get_result(buffer.str()) << std::endl;
}