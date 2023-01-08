#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>

bool folderExists(const char* path) {
  struct stat st;
  if (stat(path, &st) == 0) {
    return S_ISDIR(st.st_mode);
  }
  return false;
}

void firsttime(){
    
}