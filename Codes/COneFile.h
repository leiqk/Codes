#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class COneFile
{
public:
	COneFile();
	~COneFile();

public:
	bool ReadIt(const std::string &path);
	
private:
	std::string mFilePath;
	std::vector<std::string> mFileLines;
	std::ifstream mInFileStream;
};

