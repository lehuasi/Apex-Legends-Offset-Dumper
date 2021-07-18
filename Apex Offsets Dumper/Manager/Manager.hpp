#pragma once

namespace Management
{
	__forceinline void CreateDataFolder()
	{
		if (!std::filesystem::exists(xorstr_("dumps")))
		{
			if (!std::filesystem::create_directory(xorstr_("dumps")))
				return;
		}
	}

	__forceinline void LogToFile(std::ofstream &mFile, std::string text, uintptr_t address = 0, bool end = false)//this sucks improve it xd
	{
		if (!mFile.good())
			return;

		if (address)
			mFile << std::setw(4) << text.c_str() << xorstr_(" 0x") << std::hex << address << xorstr_("\r") << std::endl;
		else if (address && end)
			mFile << std::setw(4) << text.c_str() << xorstr_("\r\n") << std::endl;
		else
			mFile << std::setw(4) << text.c_str() << xorstr_("\r\n") << std::endl;
	}
}