// Single linear connected list (last node's pointer to the next node is NULL)
#include <stdio.h>
#include <stdlib.h>
#include <cassert>

typedef struct node_t {
	int number;
	struct node_t* next_node_ptr;
} node_t;

void add_node(node_t* list, int number) {
	if (list != NULL) {
		if (list->next_node_ptr == NULL) {
			list->next_node_ptr = malloc(sizeof(node_t));
			list->next_node_ptr->number = number;
			list->next_node_ptr->next_node_ptr = NULL;
		}
		else {
			add_node(list->next_node_ptr, number);
		}
	}
}

void free_list(node_t* list) {
	if (list != NULL) {
		free_list(list->next_node_ptr);
		free(list);
	}
}

void show_list(node_t* list) {
	if (list != NULL) {
		printf("%d\n", list->number);
		show_list(list->next_node_ptr);
	}
}

int main() {
	node_t* myList = malloc(sizeof(node_t));
	myList->number = 0;
	myList->next_node_ptr = NULL;

	for (int i = 1; i < 6; ++i) {
		add_node(myList, i);
	}

	show_list(myList);
	free_list(myList);

	return 0;
}
