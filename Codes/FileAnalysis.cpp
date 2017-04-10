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
		//ȥ���ո�
		int nSpacePos = itemLine.find_first_of(" ");
		while ( nSpacePos != -1 && nSpacePos != itemLine.size() )
		{
			itemLine.replace(nSpacePos, 1, "");
			nSpacePos = itemLine.find_first_of(" ", nSpacePos);
		}

		//ȥ��\t
		int nTablePos = itemLine.find_first_of("\t", 0);
		while (nTablePos != -1 && nTablePos != itemLine.size())
		{
			itemLine.replace(nTablePos, 1, "");
			nTablePos = itemLine.find_first_of("\t", nTablePos);
		}

		//����
		if (itemLine.empty())
		{
			mSpaceNums++;
			continue;
		}

		//ע��//
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

		//����/*  */ ע��
		int nNotePos1 = itemLine.find("/*");
		if (nNotePos1 != string::npos)
		{
			//�ڱ�����*/
			int nNextNote = itemLine.find("*/", nNotePos1);
			if (nNextNote != string::npos)
			{
				//�����Ƿ��з�ע�͵Ĵ���
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

			//�������в���
			int nNextNot = findNextNoteText(nI);
			if (nNextNot == 0)
			{
				//����û��ע�ͷ���
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

