#include <string>
#include <iostream>
#include <filesystem>
#include <termcolor\termcolor.hpp>

#include "dataextractor.h"
#include "commandparser.h"

namespace fs = std::experimental::filesystem;

using namespace std;
using namespace termcolor;

int main(int argc, char *argv[])
{
    CommandParser cp;

    cp.PrintArguments(argc, argv);

    if ( cp.ValidateArguments(argc, argv) )
    {
        cout << green << "Arguments valid. Extracting data..." << reset<< endl;

        DataExtractor& de = DataExtractor::instance( cp.searchString(), cp.location() );

        de.ExtractData();
        
        // de.DisplayData();
    }
    else
    {
        cout << red << "Invalid arguments. Cannot extract data." << reset << endl;
    }

    getchar();
}
