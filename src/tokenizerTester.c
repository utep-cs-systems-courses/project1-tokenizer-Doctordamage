#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char input[250];
  List *userInput = init_history();
  while (1) {
    printf("Input 0 to enter a string.");
    printf("Input 1 for History.");
    fgets(input, 250, stdin);
    
    if (input[0] == '0')
      {
	printf("Waiting for input:");
	fgets(input, 250, stdin);
	char **tokens = tokenize(input);
	print_tokens(tokens);
	add_history(userInput, input);
      }
    else if (input[0] == '1')
      print_history(userInput);
    
  }
}
