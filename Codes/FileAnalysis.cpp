#include "stdafx.h"
#include "FileAnalysis.h"

CFileAnalysis::CFileAnalysis():
	mSpaceNums(0),
	mNoteNums(0),
	mValidCodeNums(0)
{
}


CFileAnalysis::~CFileAnalysis()
{
}

void CFileAnalysis::AddOneFileContent(const vector<string>& vecFileLines)
{
	mVecFileLines = vecFileLines;
}

bool CFileAnalysis::GetResults(int & nSpaces, int & notes, int & nValidCodes)
{
	if (mNoteNums == 0 && mSpaceNums == 0 && mValidCodeNums == 0)
	{
		return false;
	}

	nSpaces = mSpaceNums;
	notes = mNoteNums;
	nValidCodes = mValidCodeNums;
	return true;
}

void CFileAnalysis::AnalysisItem()
{
	if (mVecFileLines.size() <= 0)
	{
		return;
	}

	vector<string> vecFileLines(mVecFileLines);
	for (int nI = 0; nI < vecFileLines.size(); nI++)
	{
		auto itemLine(vecFileLines.at(nI));		
		//去掉空格
		int nSpacePos = itemLine.find_first_of(" ");
		while ( nSpacePos != -1 && nSpacePos != itemLine.size() )
		{
			itemLine.replace(nSpacePos, 1, "");
			nSpacePos = itemLine.find_first_of(" ", nSpacePos);
		}

		//去掉\t
		int nTablePos = itemLine.find_first_of("\t", 0);
		while (nTablePos != -1 && nTablePos != itemLine.size())
		{
			itemLine.replace(nTablePos, 1, "");
			nTablePos = itemLine.find_first_of("\t", nTablePos);
		}

		//空行
		if (itemLine.empty())
		{
			mSpaceNums++;
			continue;
		}

		//注释//
		int nNotePos = itemLine.find("//", 0);
		if (nNotePos != string::npos)
		{
			if (nNotePos == 0)
			{
				mNoteNums++;				
			}
			else
			{
				mValidCodeNums++;				
			}
			continue;
		}

		//查找/*  */ 注释
		int nNotePos1 = itemLine.find("/*");
		if (nNotePos1 != string::npos)
		{
			//在本行找*/
			int nNextNote = itemLine.find("*/", nNotePos1);
			if (nNextNote != string::npos)
			{
				//本行是否还有非注释的代码
				if (nNotePos1 > 0)
				{
					mValidCodeNums++;					
				}
				else
				{
					mNoteNums++;
				}
				continue;
			}

			//在下文中查找
			int nNextNot = findNextNoteText(nI);
			if (nNextNot == 0)
			{
				//下文没有注释符号
				mValidCodeNums++;
				continue;
			}
			mNoteNums += nNextNot - nI + 1;
			nI = nNextNot + 1;
			continue;
		}

		mValidCodeNums++;
	}
}

int CFileAnalysis::findNextNoteText(int nIndex)
{
	for (int nI = nIndex; nI < mVecFileLines.size(); nI++)
	{
		auto item = mVecFileLines.at(nI);
		int nNotePos = -1;
		nNotePos = item.find("*/");
		if (nNotePos >= 0 && nNotePos < item.size())
		{
			return nI;
		}
	}
	return 0;
}

