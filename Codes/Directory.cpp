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
	for (auto & p : fs::directory_iterator(path))
	{
		for (auto &item : fs::directory_iterator(p))
		{
			auto pathItem = item.path();
			if (pathItem.has_extension())
			{
				string strExtension = pathItem.extension().string();
				if (0 != strExtension.compare(".cpp") &&
					0 != strExtension.compare(".h") &&
					0 != strExtension.compare(".gui") &&
					0 != strExtension.compare(".cs"))
				{
					continue;
				}
				std::cout << pathItem << endl;
				mAllFileNames.push_back(pathItem.string());
			}
			else
			{
				GetAllFileNames(pathItem.string());
			}
		}

		auto pathItem = p.path();
		if (pathItem.has_extension())
		{
			string strExtension = pathItem.extension().string();
			if (0 != strExtension.compare(".cpp") &&
				0 != strExtension.compare(".h") &&
				0 != strExtension.compare(".gui") &&
				0 != strExtension.compare(".cs"))
			{
				continue;
			}
			std::cout << pathItem << endl;
			mAllFileNames.push_back(pathItem.string());
		}
	}
	return false;
}

const std::vector<std::string>& CDirectory::getFileNames() const
{
	// TODO: 在此处插入 return 语句
	return mAllFileNames;
}
