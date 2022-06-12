#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include "palavra.h"

#define MAX_LEN 1000

int main(int argc, char *const argv[])
{
  Palavra *list_word = NULL;
  FILE *txt_input = fopen(argv[2], "r");
  char line[MAX_LEN];
  int pcount = 1;
  int count_words = 0;
  int temp = 0;
  int option;
  int vflag = 0;
  int hflag = 0;
  while ((option = getopt(argc, argv, "vh")) != -1)
  {
    switch (option)
    {
    case 'v':
      if (vflag)
      {
        printf("Only one option allowed\n");
        exit(1);
      }
      else
      {
        vflag++;
        hflag++;
      }
      printf("Indice Remissivo V1.0");
      break;
    case 'h':
      if (hflag)
      {
        printf("Only one option allowed\n");
        exit(1);
      }
      else
      {
        vflag++;
        hflag++;
      }
      printf("Usage: ./main.out exit.csv caso.txt palavras.html");
      break;
    }
  }

  if (txt_input == NULL)
  {
    printf("error in opening the file\n");
    return 0;
  }

  while (fgets(line, sizeof line, txt_input) != NULL)
  {
    char *token = strtok(line, " ");

    // faz um split das palavras da linha
    while (token != NULL)
    {

      // printf("%s\n", token);
      limpaString(token);
      list_word = inserePalavra(token, list_word, pcount, &count_words);
      token = strtok(NULL, " ");
    }

    // confere se há uma sequencia de '\n' '\n', (paragrafo)
    if (line[0] == '\n')
    {
      if (temp == 1)
        pcount++;
      temp = 0;
      continue;
    }
    else
    {
      temp = 1;
    }
  }

  printa(list_word, argv[1]);

  printf("\n");

  printaHTML(argv[1], argv[3]);

  return 0;
}