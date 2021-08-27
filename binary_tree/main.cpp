#include <iostream>
#include <cassert>

typedef struct node_t {
	int number = 0;
	node_t* l, * r = nullptr;
};

void add_node(node_t*& tree, int number) {
	if (tree == nullptr) {
		tree = new node_t;
		assert(tree != nullptr);
		tree->number = number;
		tree->l = tree->r = nullptr;
		
		return;
	}

	// create left node
	if (number < tree->number) {
		if (tree->l != nullptr) {
			add_node(tree->l, number);
		}
		else {
			tree->l = new node_t;
			assert(tree->l != nullptr);
			tree->l->number = number;
			tree->l->l = tree->l->r = nullptr;
		}
	}
	// create right node
	else if (number >= tree->number) {
		if (tree->r != nullptr) {
			add_node(tree->r, number);
		}
		else {
			tree->r = new node_t;
			assert(tree->r != nullptr);
			tree->r->number = number;
			tree->r->l = tree->r->r = nullptr;
		}
	}
}

void freemem(node_t*& tree) {
	if (tree != nullptr) {
		freemem(tree->l);
		freemem(tree->r);

		delete tree;
	}
}

void show_tree(node_t*& tree) {
	if (tree != nullptr) {
		std::cout << tree->number << "\n";
		show_tree(tree->l);
		show_tree(tree->r);
	}
}

void search_tree(node_t*& tree, int number) {
	if (tree != nullptr) {
		if (tree->number == number) {
			std::cout << "Search: " << tree->number << "\n";
		}
		else {
			if (number < tree->number) {
				search_tree(tree->l, number);
			}
			else if (number >= tree->number) {
				search_tree(tree->r, number);
			}
		}
	}
}

int main() {
	node_t* myTree = nullptr;

	for (int i = 0; i < 5; ++i) {
		add_node(myTree, i);
	}

	show_tree(myTree);
	std::cout << "Searching 3... ", (search_tree(myTree, 3));

	freemem(myTree);
	std::cout << "freemem()\n";

	system("pause");
	return 0;
}