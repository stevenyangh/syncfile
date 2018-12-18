#include<new>
#include<string>
#include<iostream>

#define DATATYPE int
#define EMPTY 0

typedef struct{
    DATATYPE data;
    DATATYPE *next;
}node;

typedef struct{
    int Length;
    node *elem;
}linklist;

void Error(std::string s){
    std::cout << s << std::endl;
    exit(1);
}

void initList_ll(linklist &l)
{
    l.Length = 0;
    l.elem = nullptr;
}

node* newNode(const DATATYPE e)
{
    
}

node* insertNode(linklist &l, int pos, const DATATYPE e)
{
    if(pos < 0)
    {
	std::string a = "Wrong position.\n";
	Error(a);
    }
    else if(pos == 0)
    {
	
    }
    else
    {
	node *p = l.elem;
	for(int i = 1; i < pos && i < l.Length; i++)
	    p = p -> next;

	node *newp = new node;
	if(newp != nullptr)
	{
	    if(pos > Length)
	    {
		for(int i = 1; i <= pos - Length)
		{
		    p ->
		}
	    }
	    else
	    {
		newp -> next = p -> next;
		p -> next = newp;
		newp -> data = e;
	    }
	}
	else
	{
	    std::string b = "Memory overflow\n\0";
	    Error(b);
	}
    }
}
