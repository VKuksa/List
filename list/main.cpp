#include <iostream>
#include <string>

using std::cout; 
using std::endl;


class Element
{
public:
	virtual void output() = 0;
};

template<typename T>
class Info : public Element
{
public:
	Info(T info) { this->info = info; }
	void output() { cout << info << endl; }
private:
	T info;
};

class List
{
public:
	List(Element * p_obj, List * p) { ptr_obj = p_obj; next = p; }
	Element * get_ptr_obj() { return ptr_obj; }
	List * get_next() { return next; }
private:
	Element * ptr_obj;
	List * next;
};

void main()
{
	const int n = 3;
	Element* ptr_obj[n] = { new Info<int>(5), new Info<double>(3.14), new Info<std::string>("ABCDEF") };
	List *head = NULL, *p;

	for (int i = 0; i < n; ++i)
	{
		p = new List(ptr_obj[i], head);
		head = p;
	}

	cout << "Object outputing:" << endl;
	p = head;
	while (p != NULL)
	{
		p->get_ptr_obj()->output();
		p = p->get_next();
	}
	cout << endl;
	 
		while (head != NULL)
		{
			p = head;
			head = head->get_next();
			delete p->get_ptr_obj();
			delete p;
		}

}