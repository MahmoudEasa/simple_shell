#include "main.h"

/**
 * add_str - a function that push node at the end
 * @head: a pointer to pointer
 * @str: a string input
*/
void add_str(list_t **head, const char *str)
{
	list_t *newNode = NULL;
	list_t *temp;


	temp = *head;
	newNode = (list_t *)malloc(sizeof(list_t));
	if (!newNode)
		return;
	newNode->string = strdup(str);

	newNode->next = NULL;
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = newNode;
}

