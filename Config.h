/* CS300
 * FILENAME: Config.h
 * Class: Config
 * Contributor: Alex Saber
 *
 * File Description:
 * 	- This file contains the code for the configuration of in game objects, items and interactions.
 * 	- When the program first starts it will prompt the user for an option to configure the game.
 *     	- It implements these features by first creating a settings file if one does not already exist.
 *     	  It then will load the file for reading and writing and prompt the user to make decisions about
 *     	  in game content (Not yet determined).
 *
 *     	- TODO:
 *     		- Figure out how to organize info (whether in a yaml file or plain txt)
 *     		- Figure out if C++ has a way to parse yaml files simply and if not
 *     		  figure out a way to organize info in a txt file for parsing and writing.
 *     
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

class Config {

	public:
		Config();
		~Config();

		void run();  // Used by the program class. Runs the Config interface for the user.

	private:
		fstream configFile;  // Loaded or newly created file containing the config data.

		void promptUser(string message);
		
		//TODO: figure out all sections of the config //
		void handleObstacleMods();
		void handleItemMods();
		void handleStatsMods();
		//TODO//

		bool saveConfigFile();
		bool replaceConfigLine(string toReplace, string newLine);

		int writeToFile(int file_line, string text);
		int findItemID(string itemName);
    
        string* findCategoryFromFile(string category);

		fstream loadConfigFile();
};
