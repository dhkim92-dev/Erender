#ifndef ERENDERUTILITY_H
#define ERENDERUTILITY_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define ERENDER_MAXIMUM_FILEPATH_LENGTH 2048

int erenderIsExistDir(const char *dir_path);
int erenderIsExistFile(const char *file_path);
void erenderCreateDir(const char *dir_path);
void erenderCreateRootDir();
void erenderCreateProjectMetaFile();

#endif // ERENDERUTILITY_H
