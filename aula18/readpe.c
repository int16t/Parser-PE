#include <stdio.h>
#include <stdlib.h>
#include "../aula20/lib/petest.h"

void fatal(char *msg){
  fprintf(stderr,"ERRO: %s\n", msg);
  exit(1);
}

void usage(void){
  printf("Uso:\n ./readpe <programa.exe>\n");
  exit (1);
}

int main (int argc, char *argv[]){

  unsigned char buffer[32];

  if(argc != 2){
    usage();
  }

  PEFILE pe; 

  pe.filepath = argv[1];
  petest_init(&pe);
  if(petest_ispe(&pe))
    printf("O arquivo eh um PE....\n");
  else
    fatal("O arquivo nao eh um PE... Saindo.\n");

  printf("File: %s\n", pe.filepath);
  printf("MZ header: %x\n", pe.hdr_dos->e_magic);
  printf("COFF header offset: %x\n", pe.hdr_dos->e_lfanew);
  

  petest_deinit(&pe);

  return 0;
}
