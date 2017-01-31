#ifndef LIST_H
#define LIST_H

typedef struct list {
	void *data;
	struct list *prev;
	struct list *next;
} list_t;

list_t *list_add(list_t *, void *);
/*
 * the function pointer has to return the next item in the list.
 * this is because list_foreach uses it to iterate the list.
 */
void list_foreach(list_t *, list_t *(*func)(list_t *));
void list_foreach2(list_t *, void (*func)(list_t *));
list_t *list_free(list_t *);
list_t *free_list_data(list_t *);
list_t *puts_list(list_t *);
char *strdup(const char *);
int *intp(int);



#endif
