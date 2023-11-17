#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(int data);
	int find_element(LinkedList lst, int data);
	bool add_element(int data);
	void print_list(LinkedList lst);
	bool insert(int data, int position);
	bool delete_element(int position);
	~LinkedList();
private:
	Node* first;
	Node* last;
};


LinkedList::LinkedList()
{
	first = nullptr;
	last = nullptr;
}

LinkedList::LinkedList(int data)
{
	Node* nd = new Node{ data };
	first = nd;
	last = nd;
	last->next = nullptr;
}


LinkedList::~LinkedList(){}

int LinkedList::find_element(LinkedList lst, int data)
{
	int place = 0;
	Node* elem = first;
	while (elem != NULL)
	{
		++place;
		if((elem->data) == data)
		{
			return place;
		}
		elem = elem->next;
	}
	return 0;
}

bool LinkedList::add_element(int data)
{
	Node* nd = new Node{ data, nullptr };
	if(last == nullptr)
	{
		first = nd;
		last = nd;
		return true;
	}
	last->next = nd;
	last = nd;
	return true;
}

void LinkedList::print_list(LinkedList lst)
{
	Node* elem = first;
	while(elem != NULL)
	{
		cout << elem->data << " ";
		elem = elem -> next;
	}
}

bool LinkedList::insert(int data, int position)
{
	int i = 0, a = 0, count_elem = 0;
	Node* elem = first;
	while (elem != NULL)
	{
		++count_elem;
		elem = elem->next;
	}

	if (position == 1)
	{
		Node* elem = new Node{ data, nullptr };
		elem->data = data;
		elem->next = first;
		first = elem;
	}

	if (position == count_elem + 1)
	{
		Node* elem = new Node{ data, nullptr };
		elem->data = data;
		elem->next = nullptr;
		last->next = elem;
		last = elem;
	}

	if (position < count_elem + 1 && position > 1)
	{
		Node* elem = new Node{ data, nullptr };
		elem->data = data;
		elem->next = first;
		first = elem;
		for(int a = 1; a <= position; ++a)
		{
			elem->data = (elem->next)->data;
			if(a == position)
			{
				elem->data = data;
			}
			elem = elem->next;
		}
	}
	return true;
}

bool LinkedList::delete_element(int position)
{
	int i = 0, a = 0, count_elem = 0;
	Node* elem_f = first;
	Node* elem_l = last;
	while (elem_f != NULL)
	{
		++count_elem;
		elem_f = elem_f->next;
	}

	if (position == 1)
	{
		first = first->next;
		delete elem_f;
	}

	if (position == count_elem)
	{
		Node* elem_f1 = first;
		Node* elem_f2 = first->next;
		while (elem_f2->next != NULL) 
		{
			elem_f2 = elem_f2->next;
			elem_f1 = elem_f1->next;
		}
		elem_f1->next = NULL;
		last = elem_f1;
		delete elem_f2;
	}

	if (position < count_elem && position > 1)
	{
		Node* elem_f1 = first;
		Node* elem_f2 = first->next;
		for (int i = 1; i < position - 1; ++i)
		{
			elem_f2 = elem_f2->next;
			elem_f1 = elem_f1->next;
		}
		elem_f1->next = elem_f2->next;
		delete elem_f2;
		return true;
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	LinkedList lst;
	int x = 0, count = 0, add = 0, find = 0, place = 0, place_insert = 0, insert = 0, del_elem = 0;
	cout << "Введите количество символов в списке: ";
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		x = rand() % 10;
		lst.add_element(x);
	}
	cout << "\nCписок: ";
	lst.print_list(lst);
	cout << "\n\nКакой элемент вы хотите добавить в конец списка?: ";
	cin >> add;
	lst.add_element(add);
	cout << "\nCписок с добавленным элементом: ";
	lst.print_list(lst);
	cout << endl;
	cout << "\nКакой элемент вы хотите найти?: ";
	cin >> find;
	if(lst.find_element(lst, find) > 0)
	{
		place = lst.find_element(lst, find);
		cout << "\nДа, этот элемент присутствует в списке, впервые он встречается на " << place << " месте";
	}
	else
	{
		cout << "\nЭтого элемента в списке нет";
	}
	cout << endl;
	cout << "\nНа какую позицию списка вы хотите поставить элемент, и какой?: ";
	cin >> place_insert >> insert;
	lst.insert(insert, place_insert);
	cout << "\nCписок с добавленным элементом: ";
	lst.print_list(lst);
	cout << endl;
	cout << "\nНа каком месте вы хотите удалить элемент?: ";
	cin >> del_elem;
	lst.delete_element(del_elem);
	cout << "\nCписок с удалённым элементом: ";
	lst.print_list(lst);
	cout << endl;
	return 0;
}