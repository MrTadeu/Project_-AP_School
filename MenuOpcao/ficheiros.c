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

int fileExistAll(){
  if(fileExists("data/bin/alunos.bin") && fileExists("data/bin/cursosdisciplina.bin") && fileExists("data/bin/disciplinas.bin") && fileExists("data/bin/permission.bin") && fileExists("data/bin/professores.bin") && fileExists("data/bin/regimes.bin") && fileExists("data/bin/salas.bin")){
    return 1;
  }
  else{
    return 0;
  }
}

/* void firsttime(){
    
} */