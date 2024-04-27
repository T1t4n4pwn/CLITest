#include "Command.h"

class ExampleCommand : public Command {
public:

	ExampleCommand() : Command(L"Add", L"Add rule to filter rule list", L"Usage: Add <ProcessName> <FilePath> <PathType> <IsDenyAccess[true/false]> <IsHideFile[true/false]>")
	{
		
	}

	void Execute(const std::vector<std::wstring>& args) const override
	{
		static int argsLimit = 5;

		if (args.size() != argsLimit) {
			std::wcout << getErrMsg() << std::endl;
			return;
		}

		const std::wstring& processName = args[0];
		const std::wstring& filePath = args[1];
		const std::wstring& pathType = args[2];
		const std::wstring& isDenyAccess = args[3];
		const std::wstring& isHide = args[4];

		std::wcout << processName << std::endl;
		std::wcout << filePath << std::endl;
		std::wcout << pathType << std::endl;
		std::wcout << isDenyAccess << std::endl;
		std::wcout << isHide << std::endl;
		//进一步处理信息
	}

private:


};