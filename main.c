#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Den nya optimerade listan!
 * Kanske kan optimeras mer...
 * kanske kan läggas till int size./
/*
struct node {
	void *data;
	struct node *prev;
	struct node *next;
};

struct list {
	struct node *head;
	struct node *tail;
};
*/

typedef struct list {
	void *data;
	struct list *prev;
	struct list *next;
} list_t;

list_t *list_create(void);
list_t *list_add(list_t *, void *);
/*
 * the function pointer has to return the next item in the list.
 * this is because list_foreach uses it to iterate the list.
 */
void list_foreach(list_t *, list_t *(*func)(list_t *));
void list_foreach2(list_t *list, void (*func)(list_t *));
list_t *list_free(list_t *list);
list_t *free_list_data(list_t *);
list_t *puts_list(list_t *t);
char *strdup(const char *);
int *intp(int);

int main(void)
{
	list_t *l = NULL;

	for (int i = 0; i < 1024; i++) {
		list_t *ll = NULL;
		for (int j = 0; j < 1024; j++)
			ll = list_add(ll, intp(j));
		l = list_add(l, ll);
	}
}

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

	for (; list != NULL; list = next) {
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
