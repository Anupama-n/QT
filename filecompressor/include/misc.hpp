#pragma once

#include <sys/stat.h>
#include <string>

double compression_ratio(unsigned long long inFileSize, unsigned long long compressedFileSize);
unsigned long long get_file_size(std::string file_name);
std::string getFileName(const std::string &filePath);