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
	//һ���ļ����е���������
	std::vector<std::string> mVecFileLines;

	//����
	int mSpaceNums;

	//ע����
	int mNoteNums;

	//��Ч����
	int mValidCodeNums;
};

