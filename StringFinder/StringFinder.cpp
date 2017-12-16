#include <string>
#include <iostream>
#include <filesystem>

#include "dataextractor.h"
#include "commandparser.h"

namespace fs = std::experimental::filesystem;

using namespace std;


int main(int argc, char *argv[])
{
    CommandParser commandParser;
    commandParser.PrintArguments(argc, argv);

    if (commandParser.AreArgumentsValid(argc, argv))
    {
        cout << "Arguments valid. Extracting data..." << endl;

        string location{ argv[1] };
        string searchString{ argv[2] };

        DataExtractor& dataExtractor = DataExtractor::getInstance(searchString, location);

        dataExtractor.ExtractData();

        // de.DisplayData();
    }
    else
    {
        cout << "Invalid arguments. Cannot extract data.";
    }

    getchar();
}
