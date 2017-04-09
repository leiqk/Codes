#include "stdafx.h"
#include "COneFile.h"

COneFile::COneFile()
{
}


COneFile::~COneFile()
{
}

bool COneFile::ReadIt(const std::string & path)
{
	if (path.empty())
	{
		return false;
	}

	mInFileStream.open(path, std::ios::in);
	if (!mInFileStream.is_open())
	{
		return false;
	}

	while (!mInFileStream.eof())
	{
		char lineBuff[1024];
		mInFileStream.getline(lineBuff, 1024);
		mFileLines.push_back(lineBuff);
		std::cout << lineBuff << std::endl;
	}
	mInFileStream.close();

	return true;
}
