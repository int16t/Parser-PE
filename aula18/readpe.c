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
  if(petest_ispe(&pe)){
    printf("##### TYPE OF ARCHIVE #####\n");
    printf("PE archive\n");
  }
  else
    fatal("O arquivo nao eh um PE... Saindo.\n");
  
  printf("########## IMAGE DOS HEADER ##########\n");
  printf("File: %s\n", pe.filepath);
  printf("Magic numbers: %x\n", pe.hdr_dos->e_magic);
  printf("Bytes on last page of file: %d\n", pe.hdr_dos->e_cblp);
  printf("Pages in file: %d\n", pe.hdr_dos->e_cp);
  printf("Relocations: %d\n", pe.hdr_dos->e_crlc);
  printf("Size of header in paragraphs: %d\n", pe.hdr_dos->e_cparhdr);
  printf("Minimum extra paragraphs needed: %x\n", pe.hdr_dos->e_minalloc);
  printf("Maximum extra paragraphs needed: %x\n", pe.hdr_dos->e_maxalloc);
  printf("Initial (relative) SS value: %d\n", pe.hdr_dos->e_ss);
  printf("Initial SP value: %d\n", pe.hdr_dos->e_sp);
  printf("Checksum: %d\n", pe.hdr_dos->e_csum);
  printf("Initial IP value: %d\n", pe.hdr_dos->e_ip);
  printf("Initial (relative) CS value: %d\n", pe.hdr_dos->e_cs);
  printf("File address of relocation table: %d\n", pe.hdr_dos->e_lfarlc);
  printf("Overlay number: %d\n", pe.hdr_dos->e_ovno);
  printf("Reserved words: %d\n", pe.hdr_dos->e_res[4]);
  printf("OEM identifier: %d\n", pe.hdr_dos->e_oemid);
  printf("OEM information: %d\n", pe.hdr_dos->e_oeminfo);
  printf("Reserved words: %d\n", pe.hdr_dos->e_res2[10]);
  printf("File address of new exe header: %d\n", pe.hdr_dos->e_lfanew);

  printf("########################################\n");
    

  petest_deinit(&pe);

  return 0;
}