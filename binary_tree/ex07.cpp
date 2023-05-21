#include "binary_tree.hpp"


int main()
{

	node *root =  new node(10);
	root->insert(11);
	root->insert(9);
	root->insert(7);
	root->insert(12);
	root->insert(15);
	root->insert(8);

	root->node_delete(11);
	root->print_inorder();
	cout << "\n";
	root->print_level_order();
	

	return 0;
}