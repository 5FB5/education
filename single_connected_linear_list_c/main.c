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

void add_node_front(node_t** list, int number) {
	if (list != NULL) {
		node_t* node_front = (node_t*)malloc(sizeof(node_t));
		node_front->number = number;
		node_front->next_node_ptr = (*list)->next_node_ptr; // change head's pointer to a new node and set new node's pointer from head
		(*list)->next_node_ptr = node_front;

		assert(node_front != NULL);
		list_counter++;
	}
}

void add_node(node_t** list, int number) {
	node_t* current_node = *list;

	if (current_node != NULL) {
		while (current_node->next_node_ptr) {
			current_node = current_node->next_node_ptr;
		}

		// create new node
		current_node->next_node_ptr = (node_t*)malloc(sizeof(node_t));
		current_node->next_node_ptr->number = number;
		current_node->next_node_ptr->next_node_ptr = NULL;

		assert(current_node->next_node_ptr != NULL);
		list_counter++;
	}
	else {
		// create new node
		*list = (node_t*)malloc(sizeof(node_t));
		(*list)->number = number;
		(*list)->next_node_ptr = NULL;

		assert(list != NULL);
		list_counter++;
	}
}

int pop_front(node_t** list) {
	if (*list == NULL) {
		printf("\npop_front(): can't pop_front NULL list!");
	}

	node_t* tmp_list = (*list)->next_node_ptr;
	int num = (*list)->number;
	
	free(*list);
	
	(*list) = tmp_list;
	
	printf("\npop_front()");
	return num;
}

int pop_back(node_t** list) {
	if (*list == NULL) {
		printf("pop_back(): can't pop_back NULL list!");
		return;
	}

	int num = 0;
	node_t* current_node = (*list);

	while (current_node->next_node_ptr != NULL) {
		if (current_node->next_node_ptr->next_node_ptr == NULL) {
			num = current_node->next_node_ptr->number;
			free(current_node->next_node_ptr->next_node_ptr);
			current_node->next_node_ptr = NULL;
		}
		else {
			current_node = current_node->next_node_ptr;
		}
	}

	printf("\npop_back()");
	return num;
}

int value_at(node_t** list, int index) {
	node_t* current_node = *list;

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

int size() {
	return ++list_counter;
}

void free_list(node_t** list) {
	if (*list == NULL) {
		printf("\nfree_list(): can't delete NULL list!");
		return;
	}

	node_t* current_node = *list;

	while (current_node->next_node_ptr != NULL) {
		current_node = current_node->next_node_ptr;
		free(*list);
		*list = current_node;
	}

	free(*list);

	printf("\nfree_list()");
}

void show_list(node_t** list) {
	node_t* current_node = *list;

	printf("\nPrinting list... ");
	while (current_node != NULL) {
		printf("\n%d", current_node->number);
		current_node = current_node->next_node_ptr;
	}
}

int main() {
	/*
	node_t* myList = (node_t*)malloc(sizeof(node_t));
	myList->number = 0;
	myList->next_node_ptr = NULL;
	*/

	node_t* myList = NULL;

	for (int i = 1; i < 6; ++i) {
		add_node(&myList, i);
	}

	add_node_front(&myList, 9);

	show_list(&myList);

	printf("\nList's size: %d", size());
	printf(empty(myList) == true ? "\nList is empty!" : "\nList isn't empty!");
	printf("\nValue at 3 node is: %d", value_at(&myList, 3));

	printf("\n______________________");

	pop_front(&myList);

	show_list(&myList);

	printf("\nValue at 3 node is: %d", value_at(&myList, 3));

	pop_back(&myList);

	show_list(&myList);

	free_list(&myList);

	return 0;
}
