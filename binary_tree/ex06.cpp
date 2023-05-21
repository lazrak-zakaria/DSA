//https://practice.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1

#include "binary_tree.hpp"


bool nodeCousin(node *root, int n1, int n2)
{
	queue<node*> q;
	q.push(root);
	node *pn1 = nullptr;
	int	l1 = -1 , l2 = -1;
	node *pn2 = nullptr;

	int sz = q.size();
	for ( int lvl = 0 ; !q.empty(); ++lvl, sz = q.size())
	{
		while (sz--)
		{
			node *t = q.front();
			q.pop();
			if (t->left)
			{
				if (t->left->data == n1)
				{pn1 = t; l1 = lvl;}
				else if (t->left->data == n2)
				{	pn2 = t;  l2 = lvl;}
				q.push(t->left);
				
			}
			if (t->right)
			{
				if (t->right->data == n1)
				{	pn1 = t;  l1 = lvl;}
				else if (t->right->data == n2)
				{	pn2 = t;  l2 = lvl;}
				q.push(t->right);
			}
		}
		if (pn1 && pn2)
		{
			if (pn1 != pn2 && l1 == l2)
				return true;
		}
	}
	return false;
}

/*
               A

             /    \ 

           B        C

         /   \       \    

        D     E       B     

                     /  \    

                    D    E


*/
int main()
{

	node *root =  new node(0);
	for (int i = 1 ; i < 15; ++i)
		root->insert(new node(i));

	cout << nodeCousin(root, 7, 9) << "\n";

	

	return 0;
}
