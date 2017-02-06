#include "doubleLinkedList.h"

doubleLinkedList::doubleLinkedList()
{
    m_size=0;
    m_front=nullptr;
}

doubleLinkedList::~doubleLinkedList()
{
    while(!isEmpty())
    {
        removeFront();
    }
}

int doubleLinkedList::getSize() const
{
    return(m_size);
}

bool doubleLinkedList::isEmpty() const
{
    if(m_front == nullptr)
    {
        return (true);
    }
    else
    {
        return(false);
    }
}

bool doubleLinkedList::search(int val) const
{
     Node* temp=m_front;

	//runs the search as long as the list isn't empty
	if(!isEmpty())
	{
		//runs through the list until it reaches a node looking at nullptr
		//in the case there is more than one node in the list
		while(temp != nullptr)
		{
			//comparing the current Node value to the value taken in
			if(temp->getValue() == val)
			{
				//returns true if they match
				return(true);
			}
			//keeps it moving through the list
			temp=temp->getNext();
		}
	}
	//returns false if none of the values match
	return(false);
}

void doubleLinkedList::addBack(int val)
{
     //checking if the list is empty
	if(isEmpty())
	{
		//if returns true, then starts a new list with the given value
		m_front = new Node();
		m_front->setValue(val);
		//increments the size by one
		m_size++;
	}
	//otherwise, going to add the provided value to the back of the list
	else
	{
		//a new Node pointer to freely manipulate
		Node* temp = m_front;
		//moves through the list until it reaches the last node (looking at nullptr)
		while(temp->getNext() != nullptr)
		{
			//keeps temp moving through the list
			temp=temp->getNext();
		}
		//adding a node at the end with the given value
		Node* last=new Node();
		last->setValue(val);
		temp->setNext(last);
		//moving to the new node
		temp=temp->getNext();
		//setting the new node to look at nullptr
		temp->setNext(nullptr);
		//increments size by one
		m_size++;

	}
}

void doubleLinkedList::addFront(int val)
{
     //checking if the list is empty
  	if(isEmpty())
  	{
  		//if returns true, makes m_front a new list with the given value as the first node
  		m_front = new Node();
  		m_front->setValue(val);
  		//increments size by one
  		m_size++;
  	}
  	//otherwise, adds the given value to the front of the list
  	else
  	{
  		//makes a new node pointer to freely manipulate
  		Node* temp=m_front;

  		//making m_front look at a "new" list with the first node as the given value
  		m_front=new Node();
  		m_front->setValue(val);
  		//setting the next node to equal the list temp is looking at
  		//Thus, reattaching the old list to the new node
  		m_front->setNext(temp);
  		//increments size by one
  		m_size++;
  	}
}

bool doubleLinkedList::removeBack()
{
     //checking if the lsit is empty
	if(isEmpty())
	{
		//if it is in fact empty, returning false, since it removed nothing
		return(false);
	}
	//otherwise, will go through the process to remove the last node
	else
	{
		//making two new node pointers to manipulate
		Node* temp1=m_front;
		Node* temp2=m_front;

		//moving temp1 through the list to reach the last node
		while(temp1->getNext() != nullptr)
		{
			//keeping temp moving through the current list
			temp1=temp1->getNext();
               if(temp1->getNext() != nullptr)
               {
                    temp2 = temp2->getNext();
               }
		}
		//setting the second to the last node to look at nullptr
		temp2->setNext(nullptr);
		//deletes the last node
		delete temp1;
		//sets temp1 to look at nullptr, so we know where it's looking
		temp1=nullptr;
		//decrements the size by one
		m_size--;
		//returning true since it did remove a node
		return(true);

	}
}

bool doubleLinkedList::removeFront()
{
     //checking if the list is empty
	if(isEmpty())
	{
		//returning false, since it removed nothing
		return(false);
	}
	//otherwise, go through the process of removing the front node
	else
	{
		//creating a new node to manipulate
		Node* temp=m_front;

		//m_front looking at the second node
		m_front=m_front->getNext();
		//deleting the first node
		delete temp;
		//set temp to look at null ptr, so we know where it's looking
		temp=nullptr;
		//decrements size by one
		m_size--;
		//returning true, since it did remove the front node
		return(true);
	}
}

bool doubleLinkedList::removeSelected(int val)
{
    //checking if the list is empty
    if(isEmpty())
    {
         //returning false, since it removed nothing
         return(false);
    }
    //otherwise, go through the process of removing the front node
    else
    {
         //creating a new node to manipulate
         Node* temp=m_front;

         if(temp->getValue() == val)//check the first node
         {
              removeFront();
              m_size--;
              return(true);
         }
         else
         {
              Node* tempPrev = m_front;
              temp = temp->getNext();

             while(temp != nullptr)
             {
                  if(temp->getValue() == val)
                  {
                       tempPrev->setNext(temp->getNext());
                       delete temp;
                       temp = nullptr;
                       m_size--;
                       return(true);
                  }
                  else
                  {
                       tempPrev=tempPrev->getNext();
                       temp=temp->getNext();
                  }
             }
             return(false);
         }
    }
}

void doubleLinkedList::printList() const
{
     std::cout<<"List: ";
     if(isEmpty())
     {
          std::cout<<"EMPTY\n\n";
     }
     else
     {
          Node* temp=m_front;
          while(temp != nullptr)
          {
               std::cout<<temp->getValue()<<" ";
               temp=temp->getNext();
          }
     }
     std::cout<<"\n\n";
}

std::vector<int> doubleLinkedList::toVector() const
{
     Node* temp=m_front;
	std::vector<int> v;

	//only runs the method if the list is not empty
	if(!isEmpty())
	{
		//For the case, there's more than one Node
		//continues through the list while the current Node isn't pointing to nullptr
		while(temp->getNext() != nullptr)
		{
			//adds the value to the established vector, v
			v.push_back(temp->getValue());
			//keeps moving through the list
			temp=temp->getNext();
		}
		//if only one Node, adds that value to the established vector, v
		if(temp != nullptr)
		{
			v.push_back(temp->getValue());
		}
	}

	//returns the vector, v
	return(v);
}
