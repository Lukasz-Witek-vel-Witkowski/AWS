#pragma once
#include "BaseFileConfig.h"
class FileConfig : public BaseFileConfig
{
public:
	FileConfig();
	std::string interpreter(std::string i);
	~FileConfig();
};

