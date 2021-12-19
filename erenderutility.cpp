#include "erenderutility.h"

int erenderIsExistDir(const char *path){
    return true;
}

int erenderIsExistFile(const char *path){
    return true;
}

void erenderCreateDir(const char *path){
    char buf[ERENDER_MAXIMUM_FILEPATH_LENGTH];
#ifdef _WIN32
#else
    sprintf(buf, "%s %s", "mkdir -p", path);
#endif
    system(buf);
}

void erenderCreateRootDir(){
#ifdef _WIN32
#else
    erenderCreateDir(static_cast<const char*>("$HOME/.erender"));
#endif
}

void erenderCreateProjectMetaFile(){

}
