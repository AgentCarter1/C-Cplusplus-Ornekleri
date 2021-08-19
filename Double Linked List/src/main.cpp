#include <iostream>
#include "Program.hpp"
using namespace std;
int main(int argc, char **argv)
{
    Program *prog = new Program();
    prog->Run();
    delete prog;
    return 0;
}