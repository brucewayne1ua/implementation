/**
 * Implementation of std::string.
 * The main.cpp file will only write tests for my std::string implementation.
 * Also, anyone can write their own tests in my code and request a "Pull Request"
 */


#include "../include/string.hpp"


void first_test()
{
    rsl::String s = { 'a', 'b', 'c' }; 
    rsl::String s2 = { 'a', 'b', 'c', 'd', 'e' }; 
    std::cout << "s2: " << s2.length() << '\n';
    rsl::String s3 = s2 + s;
    std::cout << "s3: " << s3.length() << '\n';
}


int main(int argc, char** argv)
{
    first_test();
    return 0;
}
