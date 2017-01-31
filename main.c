#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
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

int main(void)
{
	list_t *l = NULL;

	for (int i = 0; i < 1024; i++) {
		list_t *ll = NULL;
		for (int j = 0; j < 1024; j++)
			ll = list_add(ll, intp(j));
		l = list_add(l, ll);
	}

	list_foreach(l->data, free_list_data);
	list_foreach(l, free_list_data);
}
