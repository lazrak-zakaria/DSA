#include "binary_tree.hpp"


int main()
{

	node *root =  new node(0);
	for (int i = 1 ; i < 15; ++i)
		root->insert(new node(i));

	root->print_Rlevel_order();

	

	return 0;
}