#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if(c == ' ' || c == '\t' || c == '\0')
      return 1;
  else
      return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
  if(c == ' ' || c == '\t' || c == '\0')
    return 0;
  else
    return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  while(*str != '\0')
    {
      if (non_space_char(*str) == 1)
	{
	  return str;
	}
      else if (*str == '\0')
	{
	  return str;
	}
      str++;
    }
  return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  while(*word != '\0')
    {
      if (non_space_char(*word) == 0)
	return word;
      else if (*word == '\0')
	return word;
      word++;
    }
  return word;
}

/* Counts the number of words in the string argument. */
int *count_words(char *str)
{
  int word_count=0;
  while(*str != '\0')
    {
      if(non_space_char(*str) != 0)
	{
	  word_count++;
	}
      str++;
    }
  return word_count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *dupe = malloc((len+1) * sizeof(char));
  int index = 0;
  while (index < len)
    {
      dupe[index] = inStr[index];
      index++;
    }
  dupe[index] ='\0';
  return dupe;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  int index = 0;
  int length = 0;
  int wordTotal = count_words(str);
  char **tokens = malloc((wordTotal+1) * sizeof(char *));
  char *temp = str;
  while (index < wordTotal)
    {
      temp = word_start(temp);
      length = word_length(temp);
      tokens[index] = copy_str(temp, length);
      temp = word_terminator(temp);
      index++;
    }
  tokens[index] = 0;
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int index = 0;
  while(tokens[index] != 0)
    {
      printf("%s\n", tokens[index]);
      index++;
    }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  int index = 0;
  while (tokens[index] != 0)
    {
      free(tokens[index]);
      index++;
    }
  free(tokens);
}

short string_length(char *str)
{
  int index = 0;
  short length = 0;
  while(*(str+index) != '\0')
    {
      length += 1;
      index++;
    }
  return length;
}

int word_length(char *str)
{
  int index = 0;
  int length = 0;
  while(*(str+index) != '\0')
    {
      if (non_space_char(*(str+index)))
	length++;
      else
	break;
      index++;
    }
  return length;
}
