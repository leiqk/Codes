// Codes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Directory.h"
#include "COneFile.h"
#include "FileAnalysis.h"
#include <iostream>
using namespace std;

int main()
{
	CDirectory dirFiles;
	//dirFiles.GetAllFileNames("F:\\project\\Codes\\testfile\\");
	//dirFiles.GetAllFileNames("F:\\project\\CountCode\\");
	//dirFiles.GetAllFileNames("F:\\FF\\truck\\Engine\\");
	dirFiles.GetAllFileNames("F:\\FF\\truck\\");
	//dirFiles.GetAllFileNames("F:\\FF\\truck\\Common\\Engine\\source\\Config\\");
	vector<string> vecFileNames = dirFiles.getFileNames();
	int nTotalSpaces = 0, nTotalNotes = 0, nTotalValids = 0;
	int nTotalSize = 0;
	cout << "total file numbers :" << vecFileNames.size() << endl;
	for (auto item : vecFileNames)
	{
		COneFile onefile;
		onefile.ReadIt(item);

		vector<string> vecFileLines = onefile.getFileLines();
		nTotalSize += vecFileLines.size();
		CFileAnalysis analysisItem;
		analysisItem.AddOneFileContent(vecFileLines);
		analysisItem.AnalysisItem();

		int nItemSpace = 0, nItemNotes = 0, nItemValid = 0;
		analysisItem.GetResults(nItemSpace, nItemNotes, nItemValid);

		nTotalNotes += nItemNotes;
		nTotalValids += nItemValid;
		nTotalSpaces += nItemSpace;
	}

	cout << "total size :" << nTotalSize << endl;
	cout << "total spaces :" << nTotalSpaces << endl;
	cout << "total Notes :" << nTotalNotes << endl;
	cout << "total Valids :" << nTotalValids << endl;
	system("pause");

    return 0;
}

