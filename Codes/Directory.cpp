#include "stdafx.h"
#include "Directory.h"
#include <filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

CDirectory::CDirectory()
{
}

CDirectory::~CDirectory()
{
}

bool CDirectory::GetAllFileNames(const std::string &path)
{
	//std::string path = "path_to_directory";
	for (auto & p : fs::directory_iterator(path))
	{
		//mAllFileNames.push_back((p.path()));
		for (auto &item : fs::directory_iterator(p))
		{
			fs::directory_entry(item);
			
			std::string sPathTemp(item.path());
			if (sPathTemp.find("."))
			{
				std::cout << item << std::endl;
				mAllFileNames.push_back(item.path);
			}
		}

		//std::cout << p << std::endl;

	}
// 	std::experimental::filesystem::directory_iterator dirItem;
// 	std::experimental::filesystem::read_symlink(path);
// 	for (auto item : std::experimental::filesystem::directory_iterator())
// 	{
// 		item->
// 	}
	
	return false;
}
