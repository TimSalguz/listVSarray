// Вариант 1.
// Создайте односвязный список из N = 10000 целых чисел и реализуйте операцию поиска в нем элемента k. Выполните M = 1000 поисковых запросов.
// Реализуйте такую же операцию для массива. Сравните производительность.

#include <iostream>
#include "timer.hpp"

struct T_List
{
	T_List* next;
	//std::string surname;
	int age;
};

void ADD(T_List* head, int age)
{
	T_List* p = new T_List;
	p->age = age;

	p->next = head->next;
	head->next = p;
}

void PRINT(T_List* head)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->age << std::endl;
		p = p->next;
	}
}

void DELETE(T_List* head)
{
	T_List* tmp;
	T_List* p = head;
	while (p->next != nullptr)
	{
		if (p->next->age % 2 == 0)
		{
			tmp = p->next;
			p->next = p->next->next;
			delete tmp;
		}
		else
			p = p->next;
	}
}

void CLEAR(T_List* head)
{
	T_List* tmp;
	T_List* p = head->next;
	while (p != nullptr)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}
}

void DUPLICATE(T_List* head)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		if (p->age % 2 == 1)
		{
			T_List* q = new T_List;
			q->next = p->next;
			p->next = q;
			q->age = p->age;
			p = p->next;
		}
		p = p->next;
	}
}

bool SEARCH(T_List* head, int number)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		if(p->age == number)
        {
            return 1;
        }
		p = p->next;
	}
    return 0;
}

void SWAPSORT(T_List* head)
{
	//for(int i=0;i<n-1;i++)
	//	for(int j=i+1;j<n;j++)

	T_List* p = head->next;
	while (p->next->next != nullptr)
	{
		T_List* q = p->next;
		while (q->next != nullptr)
		{
			if (p->age > q->age)
				std::swap(p->age, q->age);
			q = q->next;
		}
		p = p->next;
	}
}

bool ARRAYSEARCH(int* array, int number)
{
    for(int i = 0; i < 10000; i++)
    {
        if(array[i] == number)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
	T_List* head = new T_List;
	head->next = nullptr;

	//  
	for (int i = 0; i < 10000; i++)
    {
        ADD(head, i*3);
    }
    //PRINT(head);

    Timer t;
    for(int i = 0; i < 1000; i++)
    {
        std::cout << SEARCH(head, i*2) << " ";
    }
    std::cout << std::endl;
    std::cout << "LIST Time elapsed: " << t.elapsed() << '\n';


	CLEAR(head);
	delete head;




    int* array = new int[10000];
    for (int i = 0; i < 10000; i++)
    {
        array[i] = i*3;
    }
    t.reset();
    for (int i = 0; i < 1000; i++)
    {
        std::cout << ARRAYSEARCH(array, i*2) << " ";
    }
    std::cout << std::endl;

    std::cout << "ARRAY Time elapsed: " << t.elapsed() << '\n';
    delete[] array;



	return 0;
}

// struct list
// {
//     void Add(int data) {
//         node[0][0] = data;
//         int* nextNode[2];
//         node[1] = &*nextNode[0];
//         std::cout<< "nextnode 1 = " << nextNode[1] << std::endl;
//         std::cerr<< "node 1 = " << node[1] << std::endl;
//         // int* TEST = node[1];
//         // int*TEST2 = nextNode[0];


//         nextNode[0] = new int;
//         std::cout << "nextNode" << std::endl;
//         nextNode[1] = nullptr;
//         size++;
//         std::cout << &node <<std::endl;
//         //node[] = nextNode;
//     }

//     list() {
//         node[0] = new int;
//     }
//     ~list() {
//     }

//     int* node[2];
//     int* head = node[0];
//     int size = 0;
//     int* nextNode[2];
// };

// int main() {

//     list Spisok;
//     Spisok.Add(15);

//     // int* node[2];
//     // node[0] = new int;
//     // node[0][0] = 10;
//     // node[1] = nullptr;


//     // int* node2[2];
//     // node2[0] = new int;
//     // node2[0][0] = 25;
//     // node2[1] = nullptr;

//     // node[1] = &*node2[0];

//     std::cout << "node[0]  "    << &Spisok.node[0]        << std::endl
//               << "node[1]  "    << *Spisok.node[1]        << std::endl;
//     std::cout << "otvt[0]  "    << Spisok.node[0][0]     << std::endl;

//     std::cout << "nextNode[0] " << &Spisok.nextNode[0]    << std::endl
//               << "nextNode[1] " << *Spisok.nextNode[1]    << std::endl;
//     std::cout << "nextOtvt[0] " << Spisok.nextNode[0][0] << std::endl;