//
// Created by luoyulong on 17/12/16.
//

#ifndef VIEW_DEMO_FILE_UTILS_H
#define VIEW_DEMO_FILE_UTILS_H
#include <boost/filesystem.hpp>
#include <string>

struct FilePackage
{
    std::string path;
    std::vector<std::string> name_vec;
};

namespace FileUtil
{
    void FetchFiles(const std::string& path, int max_size, FilePackage* pkg);



};

#endif //VIEW_DEMO_FILE_UTILS_H
