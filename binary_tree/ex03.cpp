#include "binary_tree.hpp"


int main()
{

	node *root =  new node(0);
	for (int i = 1 ; i < 8; ++i)
		root->insert(new node(i));

	root->print_inorder();
	cout << "\n";


	node root_(0);
	for (int i = 1 ; i < 8; ++i)
		root_.insert(i);

	root_.print_inorder();
	

	return 0;
}