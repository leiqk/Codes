// Codes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Directory.h"
#include "COneFile.h"



int main()
{
	CDirectory dirFiles;
	dirFiles.GetAllFileNames("F:\\project\\Codes\\testfile\\");

// 	COneFile onefile;
// 	std::string testFile("..\\Codes\\testfile.cpp");
// 	if (!onefile.ReadIt(testFile))
// 	{
// 		return 1;
// 	}
	system("pause");

    return 0;
}

