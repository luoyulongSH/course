//
// Created by luoyulong on 17/12/16.
//

#include "file_util.h"
#include <algorithm>
using namespace boost::filesystem;
namespace FileUtil
{
    void FetchFiles(const std::string& path, int max_size, FilePackage* pkg)
    {
        if (!exists(path))
        {
            printf("%s not exist!!", path.c_str());
            return;
        }

        pkg->path = path;

        directory_iterator end_itr; // default construction yields past-the-end
        for ( directory_iterator itr( path ); itr != end_itr; ++itr )
        {
            if (is_regular_file(itr->status()))
            {
                pkg->name_vec.push_back(itr->path().filename().string());
            }

        }
        std::sort(pkg->name_vec.begin(), pkg->name_vec.end());
    }
}