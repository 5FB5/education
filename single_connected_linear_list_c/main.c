// Single linear connected list (last node's pointer to the next node is NULL)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cassert>

typedef struct node_t {
	int number;
	struct node_t* next_node_ptr;
} node_t;

int list_counter = 0;

void add_node_front(node_t* list, int number) {
	if (list != NULL) {
		node_t* node_front = (node_t*)malloc(sizeof(node_t));
		node_front->number = number;
		node_front->next_node_ptr = list->next_node_ptr; // change head's pointer to a new node and set new node's pointer from head
		list->next_node_ptr = node_front;

		assert(node_front != NULL);
		list_counter++;
	}
}

void add_node(node_t* list, int number) {
	if (list != NULL) {
		if (list->next_node_ptr == NULL) {
			list->next_node_ptr = (node_t*)malloc(sizeof(node_t));
			list->next_node_ptr->number = number;
			list->next_node_ptr->next_node_ptr = NULL;

			assert(list->next_node_ptr != NULL);
			list_counter++;
		}
		else {
			add_node(list->next_node_ptr, number);
		}
	}
}

int value_at(node_t* list, int index) {
	node_t* current_node = list;

	int counter = 0;

	while (current_node != NULL) {
		if (counter == index) {
			return current_node->number;
		}

		counter++;
		current_node = current_node->next_node_ptr;
	}

}

bool empty(node_t* list) {
	return list == NULL ? true : false;
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
	myList->next_node_ptr = NULL;

	for (int i = 1; i < 6; ++i) {
		add_node(myList, i);
	}

	add_node_front(myList, 9);

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
