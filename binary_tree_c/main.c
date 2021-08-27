#include <stdio.h>
#include <stdlib.h>

struct node_t {
	int number;
	struct node_t* l, * r;
};

struct node_t* new_node(int number) {
	struct node_t* node_temp = (struct node_t*)malloc(sizeof(struct node_t));
	node_temp->number = number;
	node_temp->l = node_temp->r = NULL;
	return node_temp;
}

// very strange logic that I don't understand now
struct node_t* insert(struct node_t* node, int number) {
	if (node == NULL) {
		return new_node(number);
	}

	if (number < node->number) {
		node->l = insert(node->l, number);
	}
	else if (number > node->number) {
		node->r = insert(node->r, number);
	}
	return node;
}

void show(struct node_t* root) {
	if (root != NULL) {
		show(root->l);
		printf("%d \n", root->number);
		show(root->r);
	}
}

void delete_tree(struct node_t* root) {
	if (root != NULL) {
		delete_tree(root->l);
		delete_tree(root->r);
		free(root);
	}
}

void main(void) {
	struct node_t* myTree = NULL;

	for (int i = 0; i < 5; ++i) {
		myTree = insert(myTree, i);
	}

	show(myTree);
	delete_tree(myTree);
}
