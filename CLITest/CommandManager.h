#pragma once
#include <iostream>
#include "Command.h"
#include "TextUtils.h"

class CommandManager {
public:
	static CommandManager* getInstance() 
	{
		static CommandManager* pManager = nullptr;
		if (pManager == nullptr) {
			pManager = new CommandManager;
		}
		return pManager;
	}

	void AddCommand(Command* Cmd) 
	{
		if (Cmd == nullptr) {
			return;
		}

		m_cmds.push_back(Cmd);
	}

	void DealCommand(const std::wstring& Text) 
	{
		std::vector<std::wstring> result;

		if (!TextUtilsW::Split(Text, L" ", result)) {
			std::wcout << L"Unknow command, try help" << std::endl;
			return;
		}

		Command* cmd = GetCommandByName(result[0]);
		if (cmd == nullptr) {
			std::wcout << L"Unknow command, try help" << std::endl;
			return;
		}

		std::vector<std::wstring> args{ std::begin(result) + 1, std::end(result) };

		cmd->Execute(args);
	}

	const std::vector<Command*>& getCommands() 
	{
		return m_cmds;
	}

private:

	CommandManager() 
	{ 

	}

	~CommandManager() 
	{
		for (Command* cmd : m_cmds) {

			if (cmd == nullptr) {
				continue;
			}

			delete cmd;
		}
	}

	Command* GetCommandByName(const std::wstring& Name) 
	{
		
		for (Command* e : m_cmds)
		{
			if (e == nullptr) {
				continue;
			}

			if (TextUtilsW::EqualsNocase(Name, e->getName())) {
				return e;
			}

		}

		return nullptr;
	}

private:
	std::vector<Command*> m_cmds;
};