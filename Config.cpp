#include "Config.h"

Config::Config() 
{
	this->configFile.open("config.txt");
}

Config::~Config()
{}

void Config::run() 
{
	// Start by reading each section of the file and prompt the user
	// for any desired changes.
	replaceConfigLine("settings1", "settings2");

	// Finish by writing the changes back to the file.
	saveConfigFile();
}

bool Config::saveConfigFile() 
{
	this->configFile.close();
	return true;
}

int Config::writeToFile(int file_line, string text)
{
	return 0;
}

int Config::findItemID(string itemName) 
{
	ifstream filein("config.txt"); //File to read from
    if(!filein)
    {
        cout << "Error opening file!" << endl;
        return false;
    }

	return 0;
}

//
// Replaces a line in the config file. C++ has no builtin for this.
//
bool Config::replaceConfigLine(string toReplace, string newLine) 
{
    ifstream filein("config.txt"); //File to read from
    ofstream fileout("newConfig.txt"); //Temporary file to modify
    if(!filein || !fileout)
    {
        cout << "Error opening files!" << endl;
        return false;
    }

    string temp;
	bool notFound = true;
    while(filein >> temp)
    {
        if(temp == toReplace && notFound){
            temp = newLine;
			notFound = false;
        }
        temp += "\n";
        fileout << temp;
    }

	if (notFound) {
		return false;
	}

	// Delete old config and rename temp file for replacement.
	remove("config.txt");
	rename("newConfig.txt", "config.txt");
	return true;
}

