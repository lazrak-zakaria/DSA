#include "binary_tree.hpp"



// inorder traversal;
int main()
{
	node *root =  new node(15);
	node *n1 =    new node(10);
	node *n2 =    new node(22);
	node *n3 =    new node(4);
	node *n4 =    new node(12);
	node *n5 =    new node(18);
	node *n6 =    new node(24);

	root->left = n1;
	root->right = n2;

	n1->left = n3;
	n1->right = n4;

	n2->left = n5;
	n2->right = n6;

	// node *j = nullptr;
	// j->print_inorder();

	root->print_inorder();
	cout << "\n\n";

	root->print_preorder();
	
	cout << "\n\n";
	root->print_postorder();

}