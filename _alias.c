#include "main.h"


#define MAX_ALIAS_NAME_LENGTH 50
#define MAX_ALIAS_VALUE_LENGTH 100

typedef struct Alias {
  char name[MAX_ALIAS_NAME_LENGTH];
  char value[MAX_ALIAS_VALUE_LENGTH];
  struct Alias* next;
} Alias;

Alias* aliases = NULL;

void print_alias(Alias* alias) {
  printf("%s='%s'\n", alias->name, alias->value);
}

void print_all_aliases() {
  Alias* alias = aliases;
  while (alias != NULL) {
    print_alias(alias);
    alias = alias->next;
  }}

void print_selected_aliases(char* alias_name) {
  Alias* alias = aliases;
  while (alias != NULL) {
    if (strcmp(alias->name, alias_name) == 0) {
      print_alias(alias);
    }
    alias = alias->next;
  }
}

Alias* find_alias(char* alias_name) {
  Alias* alias = aliases;
  while (alias != NULL) {
    if (strcmp(alias->name, alias_name) == 0) {
      return alias;
    }
    alias = alias->next;
  }
  return NULL;
}

void define_alias(char* alias_name, char* alias_value) {
  Alias* alias = find_alias(alias_name);
  if (alias != NULL) {
    strcpy(alias_name, alias_value);
  } else {
    alias = (Alias*) malloc(sizeof(Alias));
    strcpy(alias->name, alias_name);
    strcpy(alias->value, alias_value);
    alias->next = aliases;
    aliases = alias;
  }
}
