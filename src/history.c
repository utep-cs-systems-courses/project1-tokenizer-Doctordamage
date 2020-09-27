#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List *init_history()
{
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  int index = 1;
  Item *node = list->root;
  while (node->next)
    {
      node = node->next;
      index++;
    }
  node->next = malloc(sizeof(Item));
  node->next->str = copy_str(str, string_length(str));
  node->next->id = index;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *node = list->root;
  while (node->next)
    {
      if (node->id == id) 
	return node->str;
      node = node->next;
    }
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item *node = list->root;
  while (node)
    {
      printf("%d. %s", node->id, node->str);
      node = node->next;
    }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *current = list->root;
  while (current)
    {
      Item *next = current->next;
      free(current);
      current = next;
    }
  free(list);
}

