#include "categorizer.hpp"

using namespace std;

int main(int argc, char** args)
{
    fstream f;
    unsigned int histogram[256];

    if(argc == 1)
    {
        cout << "Please specify input file(s)!" << endl;
        return 1;
    }
    for(int i = 1; i < argc; i++)
    {
        f.open(args[i], ios::binary|ios::in);
        if(!f.is_open())
        {
            cout << "File: " << args[i] << " is not accessible!" << endl;
            continue;
        }
        cout << "File " << args[i] << " opened" << endl;
        ProcessFile(&f, histogram, 256);
        f.close();
    }
    return 0;
}

