#include<iostream>
using namespace std;


template <class T>
struct node
{
	T Data;
	struct node *Next;
};


template <class T>
class Functions
{
public:
	T Max(struct node<T> *Head, int iSize);
	T Min(struct node<T> *Head, int iSize);
	bool Find(struct node<T> *Head, int iSize, T No);
	int Count(struct node<T> *Head, int iSize, T No);
};


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Max
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : Address of Head, size of LinkedList  
// Description      : This function is used to find the Maximum value from LinkedList
// Returns          : Maximum Element
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T Functions<T> ::  Max(struct node<T> *Head, int iSize)
{
	struct node<T> *Temp = Head;
	T tMax = Temp->Data;

	Temp = Temp->Next;

	for(int i=2;i<=iSize;i++)
	{
		if(Temp->Data > tMax)
		{
			tMax = Temp->Data;
		}
		Temp = Temp->Next;
	}

	return tMax;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Min
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : Address of Head, size of LinkedList  
// Description      : This function is used to find the Minimum value from LinkedList
// Returns          : Minimum Element
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T Functions<T> ::  Min(struct node<T> *Head, int iSize)
{
	struct node<T> *Temp = Head;
	T tMin = Temp->Data;

	Temp = Temp->Next;

	for(int i=2;i<=iSize;i++)
	{
		if(Temp->Data < tMin)
		{
			tMin = Temp->Data;
		}
		Temp = Temp->Next;
	}

	return tMin;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Find
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : Address of Head, size of LinkedList, Element to search  
// Description      : This function is used to search the element in LinkedList
// Returns          : boolean value
//
/////////////////////////////////////////////////////////////////////////

template <class T>
bool Functions<T> :: Find(struct node<T> *Head, int iSize, T No)
{
	struct node<T> *Temp = Head;
	int i = 0;

	for(i=1;i<=iSize;i++)
	{
		if(Temp->Data == No)
			break;

		Temp = Temp->Next;
	}

	if(i > iSize)
		return false;
	else
		return true;
} 


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Count
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : Address of Head, size of LinkedList, Element  
// Description      : This function is used to count the frequency of element from LinkedList
// Returns          : Frequency
//
/////////////////////////////////////////////////////////////////////////

template <class T>
int Functions<T> :: Count(struct node<T> *Head, int iSize, T No)
{
	struct node<T> *Temp = Head;
	int iCnt = 0;

	for(int i=1;i<=iSize;i++)
	{
		if(Temp->Data == No)
		{
			iCnt++;
		}
		Temp = Temp->Next;
	}
	return iCnt;
}


////////////////////////////////////////////////////////////////////////////////
//                      Singly Linear LinkedList
////////////////////////////////////////////////////////////////////////////////

template <class T>
class Singly_Linear_LinkedList : public Functions<T>
{
private:
	struct node<T> *Head;
	int iSize;

public:
	Singly_Linear_LinkedList();
	~Singly_Linear_LinkedList();
	void InsertFirst(T no);
	void InsertLast(T no);
	void InsertAtPosition(T no, int pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int pos);
	void DisplayElements();
	int CountNoElements();
	T Maximum();
	T Minimum();
	bool Search(T No);
	int Frequency(T No);
};

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Singly_Linear_LinkedList
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is constructor of class Singly_Linear_LinkedList   
//					  It initalises the characteristics of 
//					  Singly_Linear_LinkedList class					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
Singly_Linear_LinkedList<T> :: Singly_Linear_LinkedList()
{
	Head = NULL;
	iSize = 0;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : ~Singly_Linear_LinkedList
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is destructor of class Singly_Linear_LinkedList
//					  It Deletes the memory allocated for Singly_Linear_LinkedList   					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
Singly_Linear_LinkedList<T> :: ~Singly_Linear_LinkedList()
{
	delete []Head;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DisplayElements
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This Function is used to display the Singly Linear
//					  Linked List   					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Linear_LinkedList<T> :: DisplayElements()
{
	struct node<T> *Temp = Head;                
	while(Temp != NULL)
	{
		cout<<Temp->Data<<"\t";
		Temp = Temp->Next;
	}
	cout<<"\n";
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : CountNoElements
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This Function is used to count number of elements in  
//					  Singly Linear Linked List   
//					
// Returns          : int
//					  Number of elements in Singly Linear LinkedList
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int Singly_Linear_LinkedList<T> :: CountNoElements()
{
	return iSize;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : InsertFirst
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered
//
// Description      : This Function is used to insert element at the first 
//                    position in Singly Linear Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Linear_LinkedList<T> :: InsertFirst(T No)
{
	struct node<T> *Newn = new struct node<T>;
	Newn->Data = No;
	Newn->Next = NULL;

	Newn->Next = Head;
	Head = Newn;
	iSize++;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : InsertLast
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered
//
// Description      : This Function is used to insert element at last 
//                    position in Singly Linear Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Linear_LinkedList<T> :: InsertLast(T No)
{
	struct node<T> *Newn = new struct node<T>;
	Newn->Data = No;
	Newn->Next = NULL;

	if(iSize == 0)
	{
		Head = Newn;
	}
	else if(iSize == 1)
	{
		Head->Next = Newn;
	}
	else
	{
		struct node<T> *Temp = Head;
		while(Temp->Next != NULL)
		{
			Temp = Temp->Next;
		}
		Temp->Next = Newn;
	}
	iSize++;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : InsertAtPosition
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered and position at which data should 
//					  be entered
//
// Description      : This Function is used to insert element at last 
//                    position in Singly Linear Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Linear_LinkedList<T> :: InsertAtPosition(T No, int Pos)
{
	if((Pos<0) || (Pos>(iSize+1)))
	{
		return;
	}

	if(Pos == 0)
	{
		InsertFirst(No);
	}
	else if(Pos == (iSize+1))
	{
		InsertLast(No);
	}
	else
	{
		struct node<T> *Temp = Head;
		struct node<T> *Newn = new struct node<T>;
		Newn->Data = No;
		Newn->Next = NULL;
		
		for(int i=1;i<Pos-1;i++)
		{
			Temp = Temp->Next;
		}
		Newn->Next = Temp->Next;
		Temp->Next = Newn;
		iSize++;
	}
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DeleteFirst
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// Description      : This Function is used to delete element at first 
//                    position in Singly Linear Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Linear_LinkedList<T> :: DeleteFirst()
{
	struct node<T> *Temp = Head;
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		Head = NULL;
		delete Temp;
		iSize--;
	}
	else
	{
		Head = Head->Next;
		delete Temp;
		iSize--;
	}
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DeleteLast
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// Description      : This Function is used to delete element at last 
//                    position in Singly Linear Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Linear_LinkedList<T> :: DeleteLast()
{
	struct node<T> * Temp = Head;
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		Head = NULL;
		delete Temp;
		iSize--;
	}
	else
	{
		while(Temp->Next->Next != NULL)
		{
			Temp = Temp->Next;
		}
		delete Temp->Next;
		Temp->Next = NULL;
		iSize--;
	}
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DeleteAtPosition
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Position at which data should be deleted
//
// Description      : This Function is used to delete element at given 
//                    position in Singly Linear Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Linear_LinkedList<T> :: DeleteAtPosition(int Pos)
{
	if((Pos<1) || (Pos>iSize))
	{
		return;
	}

	if(Pos == 1)
	{
		DeleteFirst();
	}
	else if(Pos == iSize)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *Temp = Head;
		struct node<T> *Temp1 = NULL;

		for(int i=1;i<Pos-1;i++)
		{
			Temp = Temp->Next;
		}

		Temp1 = Temp->Next;
		Temp->Next = Temp->Next->Next;
		delete Temp1;
		iSize--;
	}
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Maximum
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Max function
// Returns          : Maximum Element
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T Singly_Linear_LinkedList<T> :: Maximum()
{
	return this->Max(Head, iSize);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Minimum
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Min function
// Returns          : Minimum Element
//
/////////////////////////////////////////////////////////////////////////
template <class T>
T Singly_Linear_LinkedList<T> :: Minimum()
{
	return this->Min(Head, iSize);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Search
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Find function
// Returns          : boolean value
//
/////////////////////////////////////////////////////////////////////////
template <class T>
bool Singly_Linear_LinkedList<T> :: Search(T No)
{
	return this->Find(Head, iSize, No);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Frequency
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Count function
// Returns          : Frequency of number
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int Singly_Linear_LinkedList<T> :: Frequency(T No)
{
	return this->Count(Head, iSize, No);
}


////////////////////////////////////////////////////////////////////////////////
//                      Singly Circular Linked List
////////////////////////////////////////////////////////////////////////////////

template <class T>
class Singly_Circular_LinkedList : public Functions<T>
{
private:
	struct node<T> *Head;
	struct node<T> *Tail;
	int iSize;

public:
	Singly_Circular_LinkedList();
	~Singly_Circular_LinkedList();
	void InsertFirst(T no);
	void InsertLast(T no);
	void InsertAtPosition(T no, int pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int pos);
	void DisplayElements();
	int CountNoElements();
	T Maximum();
	T Minimum();
	bool Search(T No);
	int Frequency(T No);
};

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Singly_Circular_LinkedList
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// 
// Description      : This is constructor of class Singly_Circular_LinkedList 
//					  It initalises the characteristics of 
//					  Singly_Circular_LinkedList class
//					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
Singly_Circular_LinkedList<T> :: Singly_Circular_LinkedList()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : ~Singly_Circular_LinkedList
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is destructor of class Singly_Circular_LinkedList
//					  It Deletes the memory allocated for Singly Circular LinkedList   					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
Singly_Circular_LinkedList<T> :: ~Singly_Circular_LinkedList()
{
	delete []Head;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DisplayElements
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This Function is used to display the Singly Circular
//					  Linked List   					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Circular_LinkedList<T> :: DisplayElements()
{
	struct node<T> *Temp = Head;                
	for(int i=1;i<=iSize;i++)
	{
		cout<<Temp->Data<<"\t";
		Temp = Temp->Next;
	}
	cout<<"\n";
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : CountNoElements
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This Function is used to count number of elements in  
//					  Singly circular Linked List   
//					
// Returns          : int
//					  Number of elements in Singly circular LinkedList
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int Singly_Circular_LinkedList<T> :: CountNoElements()
{
	return iSize;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : InsertFirst
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered
//
// Description      : This Function is used to insert element at the first 
//                    position in Singly circular Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Circular_LinkedList<T> :: InsertFirst(T No)
{
	struct node<T> *Newn = new struct node<T>;
	Newn->Data = No;
	Newn->Next = NULL;

	if(iSize == 0)
	{
		Head = Newn;
		Tail = Newn;
	}
	else 
	{
		Newn->Next = Head;
		Head = Newn;
	}
	iSize++;
	Tail->Next = Head;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : InsertLast
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered
//
// Description      : This Function is used to insert element at last 
//                    position in Singly Circular Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Circular_LinkedList<T> :: InsertLast(T No)
{
	struct node<T> *Newn = new struct node<T>;
	Newn->Data = No;
	Newn->Next = NULL;

	if(iSize == 0)
	{
		Head = Newn;
		Tail = Newn;
	}
	else
	{
		Tail->Next = Newn;
		Tail = Newn;
	}
	iSize++;
	Tail->Next = Head;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : InsertAtPosition
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered and position at which data should 
//					  be entered
//
// Description      : This Function is used to insert element at given
//                    position in Singly Circular Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Circular_LinkedList<T> :: InsertAtPosition(T No, int Pos)
{
	if((Pos<0) || (Pos>(iSize+1)))
	{
		return;
	}

	if(Pos == 0)
	{
		InsertFirst(No);
	}
	else if(Pos == (iSize+1))
	{
		InsertLast(No);
	}
	else
	{
		struct node<T> *Temp = Head;
		struct node<T> *Newn = new struct node<T>;
		Newn->Data = No;
		Newn->Next = NULL;
		
		for(int i=1;i<Pos-1;i++)
		{
			Temp = Temp->Next;
		}
		Newn->Next = Temp->Next;
		Temp->Next = Newn;
		iSize++;
	}
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DeleteFirst
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// Description      : This Function is used to delete element at first 
//                    position in Singly Circular Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Circular_LinkedList<T> :: DeleteFirst()
{
	
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
		iSize--;
	}
	else
	{
		Head = Head->Next;
		delete Tail->Next;
		iSize--;
		Tail->Next = Head;
	}
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DeleteLast
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// Description      : This Function is used to delete element at last 
//                    position in Singly Circular Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Circular_LinkedList<T> :: DeleteLast()
{

	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
		iSize--;
	}
	else
	{
		struct node<T> * Temp = Head;
		while(Temp->Next != Tail)
		{
			Temp = Temp->Next;
		}
		delete Temp->Next;
		Tail = Temp;
		iSize--;
		Tail->Next = Head;
	}
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DeleteAtPosition
// Function Date    : 25/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Position at which data should be deleted
//
// Description      : This Function is used to delete element at given 
//                    position in Singly Circular Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Singly_Circular_LinkedList<T> :: DeleteAtPosition(int Pos)
{
	if((Pos<1) || (Pos>iSize))
	{
		return;
	}

	if(Pos == 1)
	{
		DeleteFirst();
	}
	else if(Pos == iSize)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *Temp = Head;
		struct node<T> *Temp1 = NULL;

		for(int i=1;i<Pos-1;i++)
		{
			Temp = Temp->Next;
		}

		Temp1 = Temp->Next;
		Temp->Next = Temp->Next->Next;
		delete Temp1;
		iSize--;
	}
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Maximum
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Max function
// Returns          : Maximum Element
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T Singly_Circular_LinkedList<T> :: Maximum()
{
	return this->Max(Head, iSize);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Minimum
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Min function
// Returns          : Minimum Element
//
/////////////////////////////////////////////////////////////////////////
template <class T>
T Singly_Circular_LinkedList<T> :: Minimum()
{
	return this->Min(Head, iSize);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Search
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Find function
// Returns          : boolean value
//
/////////////////////////////////////////////////////////////////////////
template <class T>
bool Singly_Circular_LinkedList<T> :: Search(T No)
{
	return this->Find(Head, iSize, No);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Frequency
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Count function
// Returns          : Frequency of number
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int Singly_Circular_LinkedList<T> :: Frequency(T No)
{
	return this->Count(Head, iSize, No);
}

//----------------------------------------------------------------------------------------------

template <class T>
struct Node
{
	T Data;
	struct Node * Next;
	struct Node *Prev;
};


template <class T>
class Function
{
public:
	T Max(struct Node<T> *Head, int iSize);
	T Min(struct Node<T> *Head, int iSize);
	bool Find(struct Node<T> *Head, int iSize, T No);
	int Count(struct Node<T> *Head, int iSize, T No);
};

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Max
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : Address of Head, size of LinkedList  
// Description      : This function is used to find the Maximum value from LinkedList
// Returns          : Maximum Element
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T Function<T> ::  Max(struct Node<T> *Head, int iSize)
{
	struct Node<T> *Temp = Head;
	T tMax = Temp->Data;

	Temp = Temp->Next;

	for(int i=2;i<=iSize;i++)
	{
		if(Temp->Data > tMax)
		{
			tMax = Temp->Data;
		}
		Temp = Temp->Next;
	}

	return tMax;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Min
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : Address of Head, size of LinkedList  
// Description      : This function is used to find the Minimum value from LinkedList
// Returns          : Minimum Element
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T Function<T> ::  Min(struct Node<T> *Head, int iSize)
{
	struct Node<T> *Temp = Head;
	T tMin = Temp->Data;

	Temp = Temp->Next;

	for(int i=2;i<=iSize;i++)
	{
		if(Temp->Data < tMin)
		{
			tMin = Temp->Data;
		}
		Temp = Temp->Next;
	}

	return tMin;
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Find
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : Address of Head, size of LinkedList, Element to search  
// Description      : This function is used to search the element in LinkedList
// Returns          : boolean value
//
/////////////////////////////////////////////////////////////////////////

template <class T>
bool Function<T> :: Find(struct Node<T> *Head, int iSize, T No)
{
	struct Node<T> *Temp = Head;
	int i = 0;

	for(i=1;i<=iSize;i++)
	{
		if(Temp->Data == No)
			break;

		Temp = Temp->Next;
	}

	if(i > iSize)
		return false;
	else
		return true;
} 

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Count
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : Address of Head, size of LinkedList, Element  
// Description      : This function is used to count the frequency of element from LinkedList
// Returns          : Frequency
//
/////////////////////////////////////////////////////////////////////////

template <class T>
int Function<T> :: Count(struct Node<T> *Head, int iSize, T No)
{
	struct Node<T> *Temp = Head;
	int iCnt = 0;

	for(int i=1;i<=iSize;i++)
	{
		if(Temp->Data == No)
		{
			iCnt++;
		}
		Temp = Temp->Next;
	}
	return iCnt;
}


////////////////////////////////////////////////////////////////////////////////
//                      Doubly Linear LinkedList
////////////////////////////////////////////////////////////////////////////////

template <class T>
class Doubly_Linear_LinkedList : public Function<T>
{
private:
	struct Node<T> * Head;
	int iSize;

public:
	Doubly_Linear_LinkedList();
	~Doubly_Linear_LinkedList();
	void InsertFirst(T No);
	void InsertLast(T No);
	void InsertAtPosition(T No, int Pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int Pos);
	void DisplayElements();
	int CountNoElements();
	T Maximum();
	T Minimum();
	bool Search(T No);
	int Frequency(T No);
};


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Doubly_Linear_LinkedList
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// 
// Description      : This is constructor of class Doubly_Linear_LinkedList 
//					  It initalises the characteristics of 
//					  Doubly_Linear_LinkedList class
//					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
Doubly_Linear_LinkedList<T> :: Doubly_Linear_LinkedList()
{
	Head = NULL;
	iSize = 0;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : ~Doubly_Linear_LinkedList
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE
//  
// Description      : This is destructor of class ~Doubly_Linear_LinkedList
//					  It Deletes the memory allocated for ~Doubly Linear LinkedList  					
//
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
Doubly_Linear_LinkedList<T> :: ~Doubly_Linear_LinkedList()
{
	delete []Head;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DisplayElements
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This Function is used to display the Doubly Linear
//					  Linked List   					
//
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Linear_LinkedList<T> :: DisplayElements()
{
	struct Node<T> * Temp = Head;
	while(Temp != NULL)
	{
		cout<<Temp->Data<<"\t";
		Temp = Temp->Next;
	}
	cout<<"\n";
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : CountNoElements
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This Function is used to count number of elements in  
//					  Doubly Linear Linked List   
//					
// Returns          : int
//					  Number of elements in Doubly Linear LinkedList
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int Doubly_Linear_LinkedList<T> :: CountNoElements()
{
	return iSize;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : InsertFirst
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered
//
// Description      : This Function is used to insert element at the first 
//                    position in Doubly Linear Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Linear_LinkedList<T> :: InsertFirst(T No)
{
	struct Node<T> *Newn = new struct Node<T>;
	Newn->Data = No;
	Newn->Next = NULL;
	Newn->Prev = NULL;

	if(iSize == 0)
	{
		Head = Newn;
	}
	else 
	{
		Newn->Next = Head;
		Head = Newn;
		Head->Next->Prev = Newn;
	}
	iSize++;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : InsertLast
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered
//
// Description      : This Function is used to insert element at last 
//                    position in Doubly Linear Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Linear_LinkedList<T> :: InsertLast(T No)
{
	struct Node<T> *Newn = new struct Node<T>;
	Newn->Data = No;
	Newn->Next = NULL;
	Newn->Prev = NULL;

	if(iSize == 0)
	{
		Head = Newn;
	}
	else if(iSize == 1)
	{
		Head->Next = Newn;
		Newn->Prev = Head;
	}
	else
	{
		struct Node<T> *Temp = Head;
		while(Temp->Next != NULL)
		{
			Temp = Temp->Next;
		}
		Temp->Next = Newn;
		Newn->Prev = Temp;
	}
	iSize++;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : InsertAtPosition
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered and position at which data should 
//					  be entered
//
// Description      : This Function is used to insert element at given
//                    position in Doubly Linear Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Linear_LinkedList<T> :: InsertAtPosition(T No, int iPos)
{
	if((iPos < 0) || (iPos > iSize+1))
	{
		return;
	}

	if(iPos == 0)
	{
		InsertFirst(No);
	}
	else if(iPos == iSize+1)
	{
		InsertLast(No);
	}
	else
	{
		struct Node <T> * Temp = Head;
		struct Node<T> * Newn = new struct Node <T>;
		Newn->Data = No;
		Newn->Prev = NULL;
		Newn->Next = NULL;

		for(int i=1;i<iPos-1;i++)
		{
			Temp = Temp->Next;
		}
		Newn->Next = Temp->Next;
		Temp->Next->Prev = Newn;
		Temp->Next = Newn;
		Newn->Prev = Temp;

		iSize++;
	}
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DeleteFirst
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// Description      : This Function is used to delete element at first 
//                    position in Doubly Linear Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Linear_LinkedList<T> :: DeleteFirst()
{
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Head;
		Head = NULL;
		iSize--;
	}
	else
	{
		struct Node <T> * Temp = Head;
		Head = Head->Next;
		delete Temp;
		Head->Prev = NULL;
		iSize--; 
	}
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DeleteLast
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// Description      : This Function is used to delete element at last 
//                    position in Doubly Linear Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Linear_LinkedList<T> :: DeleteLast()
{
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Head;
		Head = NULL;
		iSize--;
	}
	else
	{
		struct Node <T> * Temp = Head;
		while(Temp->Next->Next != NULL)
		{
			Temp = Temp->Next;
		}
		delete Temp->Next;
		Temp->Next = NULL;
		iSize--; 
	}
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DeleteAtPosition
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Position at which data should be deleted
//
// Description      : This Function is used to delete element at given 
//                    position in Doubly Linear Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Linear_LinkedList<T> :: DeleteAtPosition(int iPos)
{
	if((iPos < 0) || (iPos > iSize))
	{
		return;
	}

	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DeleteLast();
	}
	else
	{
		struct Node <T> * Temp = Head;
		for(int i=1;i<iPos-1;i++)
		{
			Temp = Temp->Next;
		}
		Temp->Next = Temp->Next->Next;
		delete Temp->Next->Prev;
		Temp->Next->Prev = Temp;
		iSize--;
	}
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Maximum
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Max function
// Returns          : Maximum Element
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T Doubly_Linear_LinkedList<T> :: Maximum()
{
	return this->Max(Head, iSize);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Minimum
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Min function
// Returns          : Minimum Element
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T Doubly_Linear_LinkedList<T> :: Minimum()
{
	return this->Min(Head, iSize);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Search
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Find function
// Returns          : boolean value
//
/////////////////////////////////////////////////////////////////////////
template <class T>
bool Doubly_Linear_LinkedList<T> :: Search(T No)
{
	return this->Find(Head, iSize, No);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Frequency
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Count function
// Returns          : Frequency of number
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int Doubly_Linear_LinkedList<T> :: Frequency(T No)
{
	return this->Count(Head, iSize, No);
}


////////////////////////////////////////////////////////////////////////////////
//                      Doubly Circular LinkedList
////////////////////////////////////////////////////////////////////////////////

template <class T>
class Doubly_Circular_LinkedList : public Function<T>
{
private:
	struct Node<T> * Head;
	struct Node<T> * Tail;
	int iSize;

public:
	Doubly_Circular_LinkedList();
	~Doubly_Circular_LinkedList();
	void InsertFirst(T No);
	void InsertLast(T No);
	void InsertAtPosition(T No, int Pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int Pos);
	void DisplayElements();
	int CountNoElements();
	T Maximum();
	T Minimum();
	bool Search(T No);
	int Frequency(T No);
};


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Doubly_Circular_LinkedList
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// 
// Description      : This is constructor of class Doubly_Circular_LinkedList 
//					  It initalises the characteristics of 
//					  Doubly_Circular_LinkedList class
//					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
Doubly_Circular_LinkedList<T> :: Doubly_Circular_LinkedList()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : ~Doubly_Circular_LinkedList
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is destructor of class Doubly_Circular_LinkedList
//					  It Deletes the memory allocated for Doubly Circular LinkedList   					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
Doubly_Circular_LinkedList<T> :: ~Doubly_Circular_LinkedList()
{
	delete []Head;
}

/////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DisplayElements
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This Function is used to display the Doubly Circular
//					  Linked List   					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Circular_LinkedList<T> :: DisplayElements()
{
	struct Node<T> * Temp = Head;
	for(int i=1;i<=iSize;i++)
	{
		cout<<Temp->Data<<"\t";
		Temp = Temp->Next;
	}
	cout<<"\n";
}



//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : CountNoElements
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This Function is used to count number of elements in  
//					  Doubly circular Linked List   
//					
// Returns          : int
//					  Number of elements in Singly circular LinkedList
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int Doubly_Circular_LinkedList<T> :: CountNoElements()
{
	return iSize;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : InsertFirst
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered
//
// Description      : This Function is used to insert element at the first 
//                    position in Doubly circular Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Circular_LinkedList<T> :: InsertFirst(T No)
{
	struct Node<T> *Newn = new struct Node<T>;
	Newn->Data = No;
	Newn->Next = NULL;
	Newn->Prev = NULL;

	if(iSize == 0)
	{
		Head = Newn;
		Tail = Newn;
	}
	else 
	{
		Newn->Next = Head;
		Head = Newn;
		Head->Next->Prev = Newn;
	}
	iSize++;
	Tail->Next = Head;
	Head->Prev = Tail;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : InsertLast
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered
//
// Description      : This Function is used to insert element at last 
//                    position in Doubly Circular Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Circular_LinkedList<T> :: InsertLast(T No)
{
	struct Node<T> *Newn = new struct Node<T>;
	Newn->Data = No;
	Newn->Next = NULL;
	Newn->Prev = NULL;

	if(iSize == 0)
	{
		Head = Newn;
		Tail = Newn;
	}
	else 
	{
		Tail->Next = Newn;
		Newn->Prev = Tail;
		Tail = Newn;
	}
	iSize++;
	Tail->Next = Head;
	Head->Prev = Tail;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : InsertAtPosition
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered and position at which data should 
//					  be entered
//
// Description      : This Function is used to insert element at given
//                    position in Doubly Circular Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Circular_LinkedList<T> :: InsertAtPosition(T No, int iPos)
{
	if((iPos < 0) || (iPos > iSize+1))
	{
		return;
	}

	if(iPos == 0)
	{
		InsertFirst(No);
	}
	else if(iPos == iSize+1)
	{
		InsertLast(No);
	}
	else
	{
		struct Node <T> * Temp = Head;
		struct Node<T> * Newn = new struct Node <T>;
		Newn->Data = No;
		Newn->Prev = NULL;
		Newn->Next = NULL;

		for(int i=1;i<iPos-1;i++)
		{
			Temp = Temp->Next;
		}
		Newn->Next = Temp->Next;
		Temp->Next->Prev = Newn;
		Temp->Next = Newn;
		Newn->Prev = Temp;

		iSize++;
	}
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DeleteFirst
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// Description      : This Function is used to delete element at first 
//                    position in Doubly Circular Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Circular_LinkedList<T> :: DeleteFirst()
{
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		struct Node <T> * Temp = Head;
		Head = Head->Next;
		delete Temp;
	}
	iSize--;
	Tail->Next = Head;
	Head->Prev = Tail;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DeleteLast
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// Description      : This Function is used to delete element at last 
//                    position in Doubly Circular Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Circular_LinkedList<T> :: DeleteLast()
{
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
		iSize--;
	}
	else
	{
		Tail = Tail->Prev;
		delete Tail->Next;
		iSize--;
		Tail->Next = Head;
		Head->Prev = Tail;
	}
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DeleteAtPosition
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Position at which data should be deleted
//
// Description      : This Function is used to delete element at given 
//                    position in Doubly Circular Linked List   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Doubly_Circular_LinkedList<T> :: DeleteAtPosition(int iPos)
{
	if((iPos < 0) || (iPos > iSize))
	{
		return;
	}

	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DeleteLast();
	}
	else
	{
		struct Node <T> * Temp = Head;
		for(int i=1;i<iPos-1;i++)
		{
			Temp = Temp->Next;
		}
		Temp->Next = Temp->Next->Next;
		delete Temp->Next->Prev;
		Temp->Next->Prev = Temp;
		iSize--;
	}
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Maximum
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Max function
// Returns          : Maximum Element
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T Doubly_Circular_LinkedList<T> :: Maximum()
{
	return this->Max(Head, iSize);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Minimum
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Min function
// Returns          : Minimum element
//
/////////////////////////////////////////////////////////////////////////
template <class T>
T Doubly_Circular_LinkedList<T> :: Minimum()
{
	return this->Min(Head, iSize);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Search
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Find function
// Returns          : boolean value
//
/////////////////////////////////////////////////////////////////////////
template <class T>
bool Doubly_Circular_LinkedList<T> :: Search(T No)
{
	return this->Find(Head, iSize, No);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Frequency
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Count function
// Returns          : Frequency of number
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int Doubly_Circular_LinkedList<T> :: Frequency(T No)
{
	return this->Count(Head, iSize, No);
}



////////////////////////////////////////////////////////////////////////////////
//                      Stack
////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack : public Functions<T>
{
private :
	struct node <T> *Head;
	int iSize;

public:
	Stack();
	~Stack();
	void Push(T No);
	void Pop();
	void DisplayElements();
	int CountNoElements();
	T Maximum();
	T Minimum();
	bool Search(T No);
	int Frequency(T No);
};


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Stack
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// 
// Description      : This is constructor of class Stack
//					  It initalises the characteristics of Stack class
//					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
Stack<T> :: Stack()
{
	Head = NULL;
	iSize = 0;
}



//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : ~Stack
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is destructor of class Stack
//					  It Deletes the memory allocated for Stack  					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
Stack<T> :: ~Stack()
{
	delete []Head;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : CountNoElements
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This Function is used to count number of elements in  
//					  Stack 
//					
// Returns          : int
//					  Number of elements in Stack
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T> :: CountNoElements()
{
	return iSize;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DisplayElements
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This Function is used to display the Stack
//					    					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T> :: DisplayElements()
{	
	if(iSize == 0)
	{
		cout<<"Stack is empty\n";
		return;
	}
	else
	{
		struct node <T> * Temp = Head;

		while(Temp != NULL)
		{
			cout<<Temp->Data<<"\t";
			Temp = Temp->Next;
		}
		cout<<"\n";
	}
	
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Push
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered
//
// Description      : This Function is used to insert element in Stack   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T> :: Push(T No)
{
	struct node <T> * Newn = new struct node<T>;
	Newn->Data = No;
	Newn->Next = NULL;

	Newn->Next = Head;
	Head = Newn;
	iSize++;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Pop
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE
//
// Description      : This Function is used to delete element from Stack   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T> :: Pop()
{
	if(iSize == 0)
	{
		cout<<"Stack is Empty\n";
		return;
	}
	else
	{
		struct node<T> * Temp = Head;
		Head  = Head->Next;
		delete Temp;
		iSize--;
	}
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Maximum
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Max function
// Returns          : Maximum Element
//
/////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T> :: Maximum()
{
	return this->Max(Head, iSize);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Minimum
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Min function
// Returns          : Minimum Element
//
/////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T> :: Minimum()
{
	return this->Min(Head, iSize);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Search
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Find function
// Returns          : boolean value
//
/////////////////////////////////////////////////////////////////////////
template <class T>
bool Stack<T> :: Search(T No)
{
	return this->Find(Head, iSize, No);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Frequency
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Count function
// Returns          : Frequency of number
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T> :: Frequency(T No)
{
	return this->Count(Head, iSize, No);
}


////////////////////////////////////////////////////////////////////////////////
//                      Queue
////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue : public Functions<T>
{
private :
	struct node <T> *Head;
	struct node <T> *Tail;
	int iSize;

public:
	Queue();
	~Queue();
	void Enqueue(T No);
	void Dequeue();
	void DisplayElements();
	int CountNoElements();
	T Maximum();
	T Minimum();
	bool Search(T No);
	int Frequency(T No);
};


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Queue
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE 
// 
// Description      : This is constructor of class Queue
//					  It initalises the characteristics of Queue class
//					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
Queue<T> :: Queue()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : ~Queue
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is destructor of class Queue
//					  It Deletes the memory allocated for Queue 					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
Queue<T> :: ~Queue()
{
	delete []Head;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : CountNoElements
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This Function is used to count number of elements in  
//					  Queue
//					
// Returns          : int
//					  Number of elements in Queue
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int Queue<T> :: CountNoElements()
{
	return iSize;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : DisplayElements
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This Function is used to display the Queue
//					    					
// Returns          : NONE
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void Queue<T> :: DisplayElements()
{	
	if(iSize == 0)
	{
		cout<<"Queue is empty\n";
		return;
	}
	else
	{
		struct node <T> * Temp = Head;

		while(Temp != NULL)
		{
			cout<<Temp->Data<<"\t";
			Temp = Temp->Next;
		}
		cout<<"\n";
	}
	
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Enqueue
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : 
//					  Data to be entered
//
// Description      : This Function is used to insert element in Queue   					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Queue<T> :: Enqueue(T No)
{
	struct node <T> * Newn = new struct node<T>;
	Newn->Data = No;
	Newn->Next = NULL;

	if(iSize == 0)
	{
		Head = Newn;
		Tail = Newn;
	}
	else
	{
		Tail->Next = Newn;
		Tail = Newn;
	}
	iSize++;
}


//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Dequeue
// Function Date    : 26/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE
//
// Description      : This Function is used to delete element from Queue 					
//
// Returns          : NONE
//
//////////////////////////////////////////////////////////////////////////
template <class T>
void Queue<T> :: Dequeue()
{
	if(iSize == 0)
	{
		cout<<"Queue is Empty\n";
		return;
	}
	else
	{
		struct node<T> * Temp = Head;
		Head  = Head->Next;
		delete Temp;
		iSize--;
	}
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Maximum
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Max function
// Returns          : Maximum Element
//
/////////////////////////////////////////////////////////////////////////

template <class T>
T Queue<T> :: Maximum()
{
	return this->Max(Head, iSize);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Minimum
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Min function
// Returns          : Minimum Element
//
/////////////////////////////////////////////////////////////////////////
template <class T>
T Queue<T> :: Minimum()
{
	return this->Min(Head, iSize);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Search
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Find function
// Returns          : boolean value
//
/////////////////////////////////////////////////////////////////////////
template <class T>
bool Queue<T> :: Search(T No)
{
	return this->Find(Head, iSize, No);
}

//////////////////////////////////////////////////////////////////////////
// 
// Function Name    : Frequency
// Function Date    : 27/05/2021
// Function Author  : Atharva Argade
// Parameters       : NONE  
// Description      : This is wrapper function which calls Count function
// Returns          : Frequency of number
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int Queue<T> :: Frequency(T No)
{
	return this->Count(Head, iSize, No);
}

