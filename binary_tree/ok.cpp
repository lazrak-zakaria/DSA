#include <iostream>


bool	up(int a, int  b)
{
	return a > b;
}

bool des(int a, int b)
{
	return a < b;
}

void	sort_(int *a, int n,  bool (*f)(int s, int b))
{
	for (int i = 0 ; i < n; ++i)
	{
		int mn = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (f(a[mn], a[j]))
				mn = j;
		}
		int t = a[mn];
		a[mn] = a[i];
		a[i] = t;
	}
}

void	print(int a[][4], int i, int j)
{
	if (i == 3  || j  == 4)
		return ;
	std::cout << a[i][j] << " ";
	print (a, i, j + 1);
	if (j == 0)
		print (a, i + 1, j);
}

int main()
{
	// int a[] = {9,6,9,5,4,7,3,2,1,0};
	// int n= 10;
	// // sort_(a, n, des);
	//  sort_(a, n, up);
	// for (int j =  0; j < n; ++j)
	// 	{
	// 		std::cout << a[j] << " ";
	// 	}

	int a[][4] = {{1, 2, 3 , -2},
				  {4, 5, 6, -2},
				  {7, 8, 9, -2}};
	print(a, 0,0);
	return 0;
}