#include <stdio.h>
#include "tokenizer.h"

/* Test case for space_char() method */


int main()
{
  char in[1000];
  printf("Welcome to Tokenizer \n");
  printf("Enter for tokenizing: \n >>");
  fgets(in, 1000, stdin);
  int num  = count_words(in);
  printf("How many words to tokenize: %d\n", num);
}
