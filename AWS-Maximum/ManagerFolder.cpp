#include "ManagerFolder.h"



ManagerFolder::ManagerFolder(std::string data) {
	Path = data;
}
void ManagerFolder::setFolder(std::string data) {
	V_Folder.push_back(cutPath(data));
}
std::string ManagerFolder::getFolderPath(int i) {
	std::string data = Path;
	data += V_Folder[i];
	return data;
}
std::string ManagerFolder::getNameFolder(int i) {
	return V_Folder[i];
}
std::string ManagerFolder::cutPath(std::string path) {

}


ManagerFolder::~ManagerFolder()
{
}
