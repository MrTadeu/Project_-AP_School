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

bool fileExists(const char* path) {
  struct stat st;
  if (stat(path, &st) == 0) {
    return S_ISREG(st.st_mode);
  }
  return false;
}

bool fileExistAll(){
  if(fileExists("data/bin/alunos.bin") && fileExists("data/bin/courses.bin") && fileExists("data/bin/disciplinas.bin") && fileExists("data/bin/perms_file.bin") && fileExists("data/bin/professores.bin") && fileExists("data/bin/regimes.bin") && fileExists("data/bin/salas.bin")){
    return true;
  }
  return false;
}

/* void firsttime(){
    
} */