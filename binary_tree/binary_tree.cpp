#include "binary_tree.hpp"

node::node(int data) : data(data) , left(nullptr), right(nullptr)
{}

void node::print_inorder() const
{
	if (this->left)
		this->left->print_inorder();
	cout << this->data << "  ";
	if (this->right)
		this->right->print_inorder();
}

void node::print_preorder() const
{
	cout << this->data << "  ";
	if (this->left)
		this->left->print_preorder();
	if (this->right)
		this->right->print_preorder();
}

void node::print_postorder() const
{
	if (this->left)
		this->left->print_postorder();
	if (this->right)
		this->right->print_postorder();
	cout << this->data << "  ";
}

size_t node::tree_height() const
{
	size_t  l;
	size_t	r;

	l = this->left ? this->left->tree_height() : 0; 
	r = this->right ? this->right->tree_height() : 0;

	return (max(l , r) + 1);
}

void	node::print_level_order() const
{
	queue< const node *> q;

	q.push(this);
	while (!q.empty())
	{
		const node *n = q.front();
		q.pop();
		if (n->left)
			q.push(n->left);
		if (n->right)
			q.push(n->right);
		cout << n->data << "  ";
	}
}

void	node::insert(node *new_node)
{
	queue<node *> q;

	q.push(this);
	while (!q.empty())
	{
		node *n = q.front();
		q.pop();
		if (!n->left || !n->right)
		{
			if (!n->left)
				n->left = new_node;
			else
				n->right = new_node;
			return ;
		}
		q.push(n->left);
		q.push(n->right);
	}
}

void	node::insert(int data)
{
	queue< node *> q;

	q.push(this);
	while (!q.empty())
	{
		node *n = q.front();
		q.pop();
		if (!n->left || !n->right)
		{
			if (!n->left)
				n->left = new node(data);
			else
				n->right = new node(data);
			return ;
		}
		q.push(n->left);
		q.push(n->right);
	}
}



//ex03
