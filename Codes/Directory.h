#pragma once
#include <vector>

class CDirectory
{
public:
	CDirectory();
	~CDirectory();

public:
	bool GetAllFileNames(const std::string &path);

public:
	std::vector<std::string> mAllFileNames;
};

