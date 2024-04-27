#include <iostream>
#include <string>
#include "CommandManager.h"
#include "HelpCommand.h"
#include "ExampleCommand.h"

int main() 
{
	
	auto pManager = CommandManager::getInstance();

	pManager->AddCommand(new HelpCommand);
	pManager->AddCommand(new ExampleCommand);
	
	while(1) {
		std::wstring cmdLine;
		std::wcout << L"[TitanFilter]> ";
		std::getline(std::wcin, cmdLine);

		pManager->DealCommand(cmdLine);
	}

	return 0;
}