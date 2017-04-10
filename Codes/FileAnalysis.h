#pragma once

#include <iostream>
#include <vector>
using namespace std;

class CFileAnalysis
{
public:
	CFileAnalysis();
	~CFileAnalysis();

	void AddOneFileContent(const vector<string > &vecFileLines);
	
	bool GetResults(int &nSpaces, int &notes, int &nValidCodes);

	void AnalysisItem();

private:
	int findNextNoteText(int nIndex);

private:
	//一个文件所有的行数内容
	std::vector<std::string> mVecFileLines;

	//空行
	int mSpaceNums;

	//注释行
	int mNoteNums;

	//有效代码
	int mValidCodeNums;
};

