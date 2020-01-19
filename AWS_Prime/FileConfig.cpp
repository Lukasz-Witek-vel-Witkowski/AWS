#include "FileConfig.h"

FileConfig::FileConfig()//:BaseFileConfig<std::string>()
{
}
std::string FileConfig::interpreter(std::string data) {
	return Parameter.at(data);
}

FileConfig::~FileConfig()
{
}



