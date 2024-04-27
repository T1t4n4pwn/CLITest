#pragma once
#include <iostream>
#include <vector>

class Command {
public:

	Command(std::wstring Name, std::wstring Description, std::wstring ErrorMessage) 
		: m_name(Name), m_description(Description), m_errMsg(ErrorMessage) 
	{

	}

	const std::wstring& getName() const
	{
		return m_name;
	}

	const std::wstring& getDescription() const
	{
		return m_description;
	}

	const std::wstring& getErrMsg() const
	{
		return m_errMsg;
	}

	virtual void Execute(const std::vector<std::wstring>& args) const = 0;

private:
	std::wstring m_name;
	std::wstring m_description;
	std::wstring m_errMsg;
};