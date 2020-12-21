#include <iomanip>
#include <iostream>
using namespace std;
typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};
void Insert(Elem*& L, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	if (L != NULL)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link; // 3
		T->link = tmp; // 4
	}
	else
	{
		L = tmp; // 5
	}
	tmp->link = L; // 6
}
Info Remove(Elem*& L)
{
	Elem* T = L;
	while (T->link != L)
		T = T->link; // 1
	Info value = L->info; // 2
	if (T != L)

	{
		Elem* tmp = L->link; // 3
		delete L; // 4
		L = tmp; // 5

		T->link = L; // 6

	}
	else

	{
		delete L; // 4
		L = NULL; // 7

	}
	return value;
}// 8 
int Count(Elem* first, Elem* L)
{
	int k = 1;
	if (L == NULL)
		return 0;
	else	
	if (k % 2 == 0)
		if (L->link != first)
			return 1 + Count(first, L->link);
		else
			return 1;
}
void Print(Elem* L)
{
	if (L == NULL)
		return;
	Elem* first = L;
	cout << setw(4) << L->info;
	while (L->link != first)

	{
		L = L->link;
		cout << setw(4) << L->info;

	}
	cout << endl;
}
int main()
{
	Elem* L = NULL;
	for
		(int i = 0; i < 10; i++)
		Insert(L, i);
	cout << Count(L, L) << endl;
	Print(L);
	while (L != NULL)
		cout << setw(4) << Remove(L);
	cout << endl;
	return 0;
}