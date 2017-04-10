#pragma once
#include <vector>

using namespace std;

class CDirectory
{
public:
	CDirectory();
	~CDirectory();

public:
	bool GetAllFileNames(const std::string &path);

	const std::vector<std::string> &getFileNames()const;

public:
	std::vector<std::string> mAllFileNames;
};

