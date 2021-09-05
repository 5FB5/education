// Single linear connected list (last node's pointer to the next node is NULL)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cassert>

typedef struct node_t {
	int number;
	int id;
	struct node_t* next_node_ptr;
} node_t;

int list_counter = 0;

void add_node(node_t* list, int number) {
	if (list != NULL) {
		if (list->next_node_ptr == NULL) {
			list->next_node_ptr = (node_t*)malloc(sizeof(node_t));
			list->next_node_ptr->number = number;
			list->next_node_ptr->id = list_counter;
			list->next_node_ptr->next_node_ptr = NULL;

			assert(list->next_node_ptr != NULL);
			list_counter++;
		}
		else {
			add_node(list->next_node_ptr, number);
		}
	}
}

int value_at(node_t* list, int n) {
	if (list != NULL) {
		if (list->id == n) {
			return list->number;
		}
		else {
			value_at(list->next_node_ptr, n);
		}
	}
}

bool empty(node_t* list) {
	return list != NULL ? false : true;
}

int size(node_t* list) {
	return list_counter;
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
	node_t* myList = (node_t*)malloc(sizeof(node_t));
	myList->number = 0;
	myList->id = 0;
	myList->next_node_ptr = NULL;

	for (int i = 1; i < 6; ++i) {
		add_node(myList, i);
	}

	show_list(myList);
	printf("\nList's size: %d", size(myList));

	if (empty(myList) == true) {
		printf("\nList is empty!");
	}
	else {
		printf("\nList isn't empty!");
	}

	printf("\nValue at 3 node is: %d", value_at(myList, 3));

	free_list(myList);

	return 0;
}
