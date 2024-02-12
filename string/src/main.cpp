/**
 * Implementation of std::string.
 * The main.cpp file will only write tests for my std::string implementation.
 * Also, anyone can write their own tests in my code and request a "Pull Request"
 */


#include "../include/wstring.h"


/* Copy constructor */
void first_test()
{
    String s = { 'a', 'b', 'c' };
    String s2 = s;
}


int main(int argc, char* argv[]) {
    first_test();

}