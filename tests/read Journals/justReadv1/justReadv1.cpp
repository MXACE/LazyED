// ChangeLanguagePack.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "conio.h"

#include <windows.h>
#include <Lmcons.h>

#include <filesystem>


using namespace std;
namespace fs = std::filesystem;

string PATH;

int main() {
	ofstream JournalList;

	//Get Username
	TCHAR username[UNLEN + 1];
	DWORD size = UNLEN + 1;
	GetUserName((TCHAR*)username, &size);
	string usrname = username;

	//Set path
	PATH = "C:\\Users\\" + usrname + "\\Saved Games\\Frontier Developments\\Elite Dangerous\\";

	//Get Filename and save 
	string filename;
	size_t posFN;

	JournalList.open("JournalList.txt");

	for (auto& entry : fs::directory_iterator(PATH))
	{
		//std::cout << entry.path() << std::endl;
		string entrystring{ entry.path().string() };

		posFN = entrystring.find("Dangerous\\");
		filename = entrystring.substr(posFN+10);

		//journal find
		
		if(filename.compare(filename.length() -4 ,4,".log") == 0)
		{
			cout << "Journal found: "<< filename << "\n";
			JournalList << filename << "\n";
		}
	}
	JournalList.close();

	printf("\ndone");
	_getch();

	return 0;
}
