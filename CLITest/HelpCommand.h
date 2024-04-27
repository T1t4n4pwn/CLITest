#pragma once
#include "Command.h"
#include "CommandManager.h"

class HelpCommand : public Command {
public:

	HelpCommand() : Command(L"help", L"Show command list", L"")
	{
		
	}

	void Execute(const std::vector<std::wstring>& args) const override {
		
		auto pManager = CommandManager::getInstance();
		
		for (const auto& cmd : pManager->getCommands()) {
			std::wcout << cmd->getName() << L"\t" << cmd->getDescription() << std::endl;
		}
	}

private:

};