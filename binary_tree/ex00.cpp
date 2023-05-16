#include "binary_tree.hpp"




int	main()
{
	node* root = new node(1);
	node* n1   = new node(2);
	node* n2   = new node(3);
	node* n4   = new node(4);

	root->left = n1;
	root->right = n2;

	n1->left = n4;

// 	    1
//     / \
//    2   3
//   /
//  4


	cout << root->left->left->data << "\n";
	
	
}