#ifndef B__T__
#define B__T__

#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

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
		node();

	public :
		int			data;
		node	*left;
		node	*right;
		node(int data);

		void	print_inorder() const;
		void	print_preorder() const;
		void	print_postorder() const;

		size_t	tree_height() const;
		void	print_level_order() const;
};



#endif