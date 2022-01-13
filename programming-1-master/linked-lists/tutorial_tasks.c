#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _ListElement
{
	int value;
	struct _ListElement* next;
}ListElement;

typedef struct _List
{
	ListElement* head;
	ListElement* current;
}List;

ListElement* createElement(int x)
{
	ListElement* new = (ListElement*)malloc(sizeof(ListElement));
	new->value = x;
	new->next = NULL;
	return new;
}
void printelement(ListElement* le)
{
	if (le != NULL)
		printf("%d\n", le->value);
	else
		printf("no such element in list");
}
void addBeg(List* l, ListElement* new)
{
	if (l->head == NULL)
	{
		l->head = new;
		new->next = NULL;
	}
	else
	{
		new->next = l->head;
		l->head = new;
	}
}
void addEnd(List* l, ListElement* new)
{
	if (l->head == NULL)
	{
		l->head = new;
		new->next = NULL;
	}
	else
	{
		ListElement* last = NULL;
		ListElement* current = l->head;
		while (current != NULL)
		{
			last = current;
			current = current->next;
		}
		last->next = new;
		new->next = NULL;
	}
}
void destroylist(List* l)
{
	if (l->head != NULL)
	{
		ListElement* current = l->head;
		ListElement* todestroy = NULL;
		while (current != NULL)
		{
			todestroy = current;
			current = current->next;
			free(todestroy);
		}
		l->head = NULL;
	}
}
void printlist(List* l)
{
	if (l)
	{
		if (l->head == NULL)
			printf("list is empty");
		else
		{
			ListElement* current = l->head;
			while (current != NULL)
			{
				printf("%d ", current->value);
				current = current->next;
			}
			printf("\n");
		}
	}
	else
		printf("list is empty\n");
	
}
void printaftercurrent(List* l, int x)
{
	int n = 0;
	l->current = l->head;
	while (l->current != NULL)
	{
		if (l->current->value == x)
		{
			n += 1;
			break;
		}
		l->current = l->current->next;
	}
	if (n == 1)
	{
		ListElement* now = l->current;
		while (now != NULL)
		{
			printf("%d ", now->value);
			now = now->next;
		}
		printf("\n");
	}
	else
		printf("there is not such element in the list!");
}
void removefirst(List* l)
{
	if (l->head == NULL)
		return;
	else
	{
		ListElement* first = l->head;
		l->head = first->next;
		free(first);
	}

}
void removelast(List* l)
{
	if (l->head == NULL)
		return;
	else
	{
		ListElement* current = l->head;
		ListElement* last;
		while (current->next->next != NULL)
		{
			current = current->next;
		}
		last = current->next;
		current->next = NULL;
		free(last);

	}

}
ListElement* findvalue(List* l, int x)
{
	if (l->head == NULL)
		return NULL;
	else
	{
		ListElement* current = l->head;
		while (current != NULL)
		{
			if (current->value == x)
				return current;
			current = current->next;
		}
		return NULL;
		;

	}
}
ListElement* findindex(List* l, int x)
{
	if (l->head == NULL)
		return NULL;
	ListElement* current = l->head;
	int i = 0;
	while (current != NULL && i < x)
	{
		current = current->next;
		i++;
	}
	return current;
}
void insertafter(List* l, ListElement* current, ListElement* new)
{
	l->current = current;
	if (current == NULL)
		return;
	if (l->current->next == NULL)
		addEnd(l, new);
	new->next = l->current->next;
	l->current->next = new;
}
void insertbefore(List* l, ListElement* current, ListElement* new)
{
	l->current = current;
	if (l->head == NULL)
		return;
	if (l->current == l->head)
		addBeg(l, new);
	else
	{
		ListElement* x = l->head;
		while (x->next != current)
			x = x->next;
		if (x->next == NULL)
			return;
		else
		{
			x->next = new;
			new->next = l->current;
		}
	}
}
void removeaftercurrent(List* l, ListElement* current)
{
	if (l->head == NULL)
		return;
	l->current = current;
	if (current->next != NULL)
	{
		ListElement* delete = current->next;
		current->next = delete->next;
		free(delete);
	}
}
void removecurrent(List* l, ListElement* current)
{
	if (l->head == NULL)
		return;
	l->current = current;
	if (l->current == l->head)
	{
		removefirst(l);
	}
	else if (l->current->next == NULL)
	{
		removelast(l);
	}
	else
	{
		ListElement* x = l->current;
		ListElement* d = l->head;
		while (d->next != l->current)
		{
			d = d->next;
		}
		d->next = l->current->next;
		free(x);
	}
}
void removefirstvalue(List* l, int x)
{
	removecurrent(l, findvalue(l, x));
}
List* splitaftercurrent(List* l, ListElement* current)
{
	List* a = (List*)malloc(sizeof(List));
	List* empty = { NULL };
	if (l->head == NULL)
		return empty;
	else if (current==NULL)
		return empty;
	else
	{
		l->current = current;
		a->head=l->current->next;
		l->current->next = NULL;
		return a;
	}
	
}
List* splitatcurrent(List* l, ListElement* current)
{
	List* a = (List*)malloc(sizeof(List));
	List* empty = { NULL };
	if (l->head == NULL)
		return empty;
	ListElement* new = l->head;
	l->current = current;
	while (new->next != l->current)
		new = new->next;
	if (new == NULL)
		return empty;
	else
	{
		new->next = NULL;
		a->head = l->current;
		return a;
	}	
}
List* catlists(List* b, List* a)
{
	if (a->head == NULL)
		return b;
	else if (b->head == NULL)
		return a;
	else
	{
		ListElement* new = a->head;
		while (new->next != NULL)
			new = new->next;
		new->next = b->head;
		return a;

	}
}
int main(void)
{
	List list = { NULL };
	addBeg(&list, createElement(2));
	addEnd(&list, createElement(3));
	addEnd(&list, createElement(5));
	addEnd(&list, createElement(8));
	addBeg(&list, createElement(4));
	printlist(&list);
	/*printaftercurrent(&list, 5);
	removefirst(&list);
	printlist(&list);
	removelast(&list);
	removelast(&list);
	printlist(&list);*/
	printelement(findvalue(&list, 4));
	//printelement(findindex(&list, 3));
	//insertafter(&list, findvalue(&list, 5), createElement(7));
	//printlist(&list);
	//insertbefore(&list, findvalue(&list, 4), createElement(0));
	//printlist(&list);
	/*removeaftercurrent(&list, findvalue(&list, 7));
	insertbefore(&list, findvalue(&list, 4), createElement(0));
	printlist(&list);
	removecurrent(&list, findvalue(&list, 4));
	printlist(&list);
	removefirstvalue(&list, 0);
	printlist(&list);*/
	/*List* a = splitaftercurrent(&list, findvalue(&list, 5));
	printlist(&list); 
	printlist(a);*/
	//List* b = splitatcurrent(&list, findvalue(&list,7));
	//printlist(&list);
	//printlist(b);
	//printlist(catlists(&list, b));
	return 0;
}