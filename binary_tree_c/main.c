#include <stdio.h>
#include <stdlib.h>
#include <cassert>

typedef struct node_t {
	int number;
	struct node_t* l, * r;
} node_t;

void show(node_t* root) {
	if (root != NULL) {
		printf("%d \n", root->number);
		show(root->l);
		show(root->r);
	}
}

void add_node(node_t* root, int number) {
	if (root != NULL) {
		if (number < root->number) {
			if (root->l != NULL) {
				add_node(root->l, number);
			}
			else {
				root->l = malloc(sizeof(node_t));
				root->l->number = number;
				root->l->l = root->l->r = NULL;
				return;
			}
		}
		else if (number > root->number) {
			if (root->r != NULL) {
				add_node(root->r, number);
			}
			else {
				root->r = malloc(sizeof(node_t));
				root->r->number = number;
				root->r->l = root->r->r = NULL;
				return;
			}

		}
	}
}

void delete_tree(node_t* root) {
	if (root != NULL) {
		delete_tree(root->l);
		delete_tree(root->r);
		free(root);
	}
}

int main() {
	node_t* myTree = malloc(sizeof(node_t));
	myTree->number = 0;
	myTree->l = myTree->r = NULL;

	if (myTree != NULL) {
		for (int i = 0; i < 5; ++i) {
			add_node(myTree, i);
			assert(myTree != NULL);
		}

		show(myTree);
		delete_tree(myTree);
	}
	else {
		printf("myTree is NULL\n");
	}

	return 0;
}
