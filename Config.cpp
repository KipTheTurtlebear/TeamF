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
    
    // TESTING START
	//replaceConfigLine("Monster", "Monster1");
    
    findCategoryFromFile("Obstacles");
    // TESTING END

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
        // If you've arrived at the line to replace then
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
    
    // Rewrite was successful.
	return true;
}

string* Config::findCategoryFromFile(string category) {
    // Returns this if function success.
    string* toReturn;
    
    // Returns this if function fails.
    string * error = new string[1];
    error[0] = "Error";
    
    ifstream filein("config.txt"); //File to read from
    if(!filein)
    {
        cout << "Error opening file!" << endl;
        return error;
    }
    
    // The while loop below will search the file for the given category
    bool found = false;
    string temp;
    while(getline(filein, temp))
    {
        // If you've arrived at the line to replace then
//        if(temp == category){
//            temp = newLine;
//            found = true;
//        }
//
//        if (!notFound) {
//            break;
//        }
        cout << temp << endl;
    }
    
    if (!found) {
        return error;
    }
    return toReturn;
}

