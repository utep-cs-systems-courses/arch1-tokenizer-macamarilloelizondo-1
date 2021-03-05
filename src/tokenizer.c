#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

/* Return true (non-zero) if c is a non-whitespace character
   ('\t' or ' ').
   Zero terminator are not printable (therefore false) */
int space_char(char c){
  if(c == '\t' || c == ' ' || c == '\0' || c == 'n')
    return 1;
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if(c == '\t' || c == ' ' || c == '\0' || c == '\n')
    return 0;
  return 1;
}

/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str. Return a zero pointer if
   str does not contain any words.*/
char *word_start(char *word){
  if(*word != '\0'){
    char *np = word; //np means new pointer
    while(space_char(*np) != 1){
      np++;
    }
    return np;
  }
  return word;
}

/* Returns a pointer terminator char following *word. */
char *word_terminator(char *word){
  if(*word != '\0'){
    char *np = word; //np means new pointer
    while(non_space_char(*np) != 1){
      np++;
    }
    return np;
  }
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *str){
  char *np = str; //np means new pointer
  int count = 0;
  while(*np){
     np = word_start(np);
     np = word_terminator(np);
     count++;
  }
  return count;
}

/* Returns a freshly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *np = malloc(sizeof(char) * (len + 1)); //np means new pointer
  for(int i = 0; i < len; i++){
    np[i] = inStr[i];
  }
  np[len] = '\0';
  return np;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.

   For example, tokenize ("hello world string") would result in:
       tokens[0] = "hello"
       tokens[1] = "world"
       tokens[2] = "string"
       tokens[3] = 0
*/
char **tokenize(char* str){

}

/*Prints all tokens. */
void print_tokens(char **tokens){
  for(int i = 0; tokens[i] != 0; i++){
    printf("%s \n", tokens[i]);
  }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens){
  for(int i = 0; tokens[i] != 0; i++){
    free(tokens[i]);
  }
  free(tokens);
}

void print(char *str){
  printf("String: %s", str);
}
