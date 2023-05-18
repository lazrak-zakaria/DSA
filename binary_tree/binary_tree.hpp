#ifndef B__T__
#define B__T__

#include <exception>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>


using namespace std;

// class _exception : public exception
// {
// 	public:
// 		virtual const char *what()
// 		{
// 			return ("Error\n");
// 		}
// };

class node
{
	private :
		int			data;
		node	*left;
		node	*right;
		node();
	public :
		node(int data);

		void	print_inorder() const;
		void	print_preorder() const;
		void	print_postorder() const;

		size_t	tree_height() const;
		void	print_level_order() const;
	//	size_t	tree_height_by_level_order() const; TODO

		void	insert(node *new_node); // insert by node
		void	insert(int new_node);	// insert by data

		void	node_delete(int data);  // TODO

		
//		ex04 level order in spiral form
//		{
		void	print_spiral1(); // using recursion TODO
		void	print_spiral2(); // using stack
		void	print_spiral3();
//		}
};

#endif