/*
*
* by Sabomanq (c) 
*/

#include <iostream>
using namespace std;
class Usel
{
public:
	Usel* rigth;
	Usel* left;
	Usel(int a);
	int key;
};

Usel::Usel(int a):key(a)
{
	rigth = nullptr;
	left = nullptr;
}

class tree
{
public:
	tree();
	~tree();
	void AddUsel(int a);
	Usel Search(int a);
	void Obhod(Usel*t);
	Usel* root;
};

tree::tree()
{
}

tree::~tree()
{
}

void tree::AddUsel(int a)
{
	if (!root)
	{
		root = new Usel(a);
	}
	else
	{
		Usel * nowUsel = root;
		while (true)
		{
			if (a >= nowUsel->key)
			{
				if (nowUsel->rigth)
				{
					nowUsel = nowUsel->rigth;
					continue;
				}
				else 
				{
					nowUsel->rigth = new Usel(a);
					break;
				}
			}
			else
			{
				if (a <= nowUsel->key)
				{
					if (nowUsel->left)
					{
						nowUsel = nowUsel->left;
						continue;
					}
					else
					{
						nowUsel->left = new Usel(a);
						break;
					}
				}
			}
		}

	}
}

void tree::Obhod(Usel *t)
{
	cout << t->key << endl;
	if (t->left)
		Obhod(t->left);
	if (t->rigth)
		Obhod(t->rigth);
}

int main()
{

	tree oak;
	
	oak.AddUsel(12);
	
	oak.AddUsel(9);
	
	oak.AddUsel(15);

	oak.AddUsel(17);

	oak.AddUsel(10);

	oak.AddUsel(8);
	
	oak.AddUsel(20);
	
	oak.Obhod(oak.root);
	//cout << oak.root->key << endl;
	
    return 0;
}

