#ifndef ROOT_H
#define ROOT_H

#include <vector>
#include <fstream>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <bitset>
#include <QString>

#include "image.h"

class Root
{
private:

    std::vector<fileStruct> rootFiles;
    std::string fileToStr(char *filename);

public:
    explicit Root(Image &image);

    int find_file(std::string filename);

    fileStruct getFile(int id);

    void describe_file(fileStruct &file);

    bool isDirectory(fileStruct &file);

};

#endif // ROOT_H
