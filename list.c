#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

list_t *list_add(list_t *list, void *data)
{
	list_t *elem, *head;

	if ((elem = malloc(sizeof(list_t))) == NULL)
		return NULL;
	
	if (list == NULL)
	    head = elem;
	else {
		head = list;
		for (; list->next != NULL; list = list->next)
			;
		list->next = elem;
	}

	elem->prev = list;
	elem->next = NULL;
	elem->data = data;

	return head;
}

void list_foreach(list_t *list, list_t *(*func)(list_t *))
{
	for (; list != NULL; list = func(list))
		;
}

void list_foreach2(list_t *list, void (*func)(list_t *))
{
	list_t *next;

	for  (; list != NULL; list = next) {
		next = list->next;
		func(list);
	}
}

list_t *list_free(list_t *list)
{
	list_t *next = list->next;
	free(list);
	return next;
}

list_t *free_list_data(list_t *list)
{
	free(list->data);
	return list->next;
}

list_t *puts_list(list_t *list)
{
	puts(list->data);
	return list->next;
}

char *strdup(const char *s)
{
	char *dst = malloc(strlen(s) + 1);
	if (dst != NULL)
		strcpy(dst, s);
	return dst;
}

int *intp(int i)
{
	int *p = malloc(sizeof(int));
	if (p != NULL)
		*p = i;
	return p;
}
