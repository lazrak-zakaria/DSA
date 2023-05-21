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



//ex04

void	node::print_spiral2()
{
	stack < node* > s1;
	stack < node* > s2;
	node	*temp;
	s1.push(this);
	while (!s1.empty() || !s2.empty()) // if one of them is not empty
	{
		while (!s1.empty())
		{
			temp = s1.top();
			s1.pop();
			cout << temp->data << " ";
			if (temp->right)
				s2.push(temp->right);
			if (temp->left)
				s2.push(temp->left);
		}
		while (!s2.empty())
		{
			temp = s2.top();
			s2.pop();
			cout << temp->data << " ";
			if (temp->left)
				s1.push(temp->left);
			if (temp->right)
				s1.push(temp->right);
		}
	}
	cout << "\n";
}

void	node::print_spiral3()
{
	deque <node*> dq;
	node*	temp;
	size_t	dq_size;
	dq.push_front(this);

	bool k = true;
	while (!dq.empty())
	{
		dq_size = dq.size();
		if (k)
		{
			while (dq_size--)
			{
				temp = dq.back();
				dq.pop_back();
				if (temp->right)
					dq.push_front(temp->right);
				if (temp->left)
					dq.push_front(temp->left);
				cout << temp->data << " ";
			}
			k = false;
		}
		else
		{
			while (dq_size--)
			{
				temp = dq.front();
				dq.pop_front();
				if (temp->left)
					dq.push_back(temp->left);
				if (temp->right)
					dq.push_back(temp->right);
				cout << temp->data << " ";
			}
			k = true;
		}
	}
}

void	node::print_Rlevel(int	l, int i)
{
	if (i == l)
	{
		cout << this->data << " ";
		return ;
	}
	if (this->left)
		this->left->print_Rlevel(l, i + 1);
	if (this->right)
		this->right->print_Rlevel(l, i + 1);
	
}

void	node::print_Rlevel_order()
{
	size_t	h = this->tree_height();

	for (int i = h; i ; i--)
	{
		this->print_Rlevel(i, 1);
	}
}


void	node::node_delete(int data)
{
	queue<node*> q;
	node*	to_delete = nullptr;
	node* tmp;
	node *del = nullptr;
	bool r = 0;
	bool l = 0;
	q.push(this);
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		if (data == tmp->data && to_delete == nullptr)
			to_delete = tmp;
		if (tmp->left)
			q.push(tmp->left);
		if (tmp->right)
			q.push(tmp->right);
		if (tmp->left)
		{
			if (!tmp->left->right && !tmp->left->left)
				del = tmp;
			r = 0;
			l = 1;
		}
		if (tmp->right)
		{
			if (!tmp->right->right && !tmp->right->left)
				del = tmp;
			r = 1;
			l = 0;
		}
	}

	if (r)
	{
		to_delete->data = del->right->data;
		delete del->right;
		del->right = nullptr;
	}
	if (l)
	{
		// if (to_delete->data)
		// 	cout << "to_delete->data\n";
		to_delete->data = del->left->data;
		delete del->left;
		del->left = nullptr;
	}
}
