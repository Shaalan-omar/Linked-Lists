//
//  Normal LL.hpp
//  Linked Lists shaalan
//
//  Created by Omar shaalan on 4/13/20.
//  Copyright © 2020 Omar shaalan. All rights reserved.
//

#ifndef Normal_LL_hpp
#define Normal_LL_hpp

#include <iostream>
#include <stdio.h>
using namespace std;

struct node // Creating a node consisting of 2 objects, a key and a pointer of type node that stores the data and points to the direction of the next node
{
    int key; // The data stored in the node
    node *next; //A pointer of type node that stores a key and a direction that points to the next node
};

class Linked_List //Implemnting the the linked lists concept through the classes
{
private:
    int size; // The size of the linked list.
    node *  head; // A pointer that ALWAYS points to the first node.
public:
    Linked_List(); //constructer
    int getSize(); // A function that returns the size of the linked lists.
    void Add_First(int value); //A function that creats the first node.
    void Add_Last(int value); // A function that creats the second node.
    void Insert(int value, int poisiton); // A function that inserts a node.
    void Delete_Last(); // A function that delets the last node.
    void Delete_First(); // A function that delets the first node.
    void Print(); //A function that prints the linked list.
};


Linked_List::Linked_List()
{
    size = 0; // the initial size of the LL is 0.
    head = NULL; //The head pointer points to nothing.
}
int Linked_List::getSize()
{
    return size;
}
void Linked_List::Add_First(int Value)
{
    node *New_Node = new node; /// Allocating a new memory space in the memomry and returns the address of the newly allocated and initialized memory to the New_Node created pointer.
    New_Node -> key = Value; // Storing the value inside the key variable as the New_Node points to the address of the key variable.
    New_Node -> next = head; //The pointer next belonging to the New_Node points to the head pointer.
    head = New_Node; //The head stores and points to the New_Node created.
    size ++; // Incrimenting the size as a new node is created.
}
void Linked_List::Add_Last(int Value)
{
    node *New_Node = new node; /// Allocating a new memory space in the memomry and returns the address of the newly allocated and initialized memory to the New_Node pointer.
    New_Node->key = Value; // Storing the value inside the key variable as the New_Node points to the address of the key variable.
    if(head == NULL) ///In case the Linked List is empty, the New_Node will be the first node and the head pointer will point to it as the head always points to the first node.
        {
            head = New_Node; //Head pointing to the New_Node.
        }
    else // The Linked List is not empty
        {
            node *l = head; ///Declaring a new pointer and copying the head's value which is the address of the First Node, this makes the pointer l points to the forst node just as the head pointer does.
                while(l->next != NULL) //A condition that makes l know where is the last.
                {
                    l = l->next; //Advancing from the first node till it points to the last node.
                }
            New_Node->next = NULL; //Nullifying the New_Node->next as this is supposed to be the last node.
            l->next = New_Node;//Now the l->next points to the New_Node which its next is pointing to Null and its preceeding node is l.
            l = NULL;//Nullfying the l because we want to insert only one node.
        }
    size++; // Incrimenting the size as a new node is inserted.
}
void Linked_List::Insert(int value, int poisiton)
{
    if(head == NULL || poisiton ==0) //In case the Linked List is empty or the user wants to insert the node in the first position
        {
            Add_First(value); //We call the Add_First function
        }
    else
        {
            node *New_Node = new node; /// Allocating a new memory space in the memomry and returns the address of the newly allocated and initialized memory to the New_Node pointer.
            New_Node->key = value; //Assigning the value to the New_Node created.
            node *Temp_Node = head; //Creating a pointer that copies the position of the head pointer and also points on the first node.
            for (int i = 0; i < poisiton - 1; i++)
            {Temp_Node = Temp_Node->next;} //Moving a temp node to the required position
            New_Node->next = Temp_Node ->next; //Copying the position of the Temp_Node next to the New_node next.
            Temp_Node = New_Node; //I cannot understand this!!!!!!!!!!!!!!!
            size++;  // Incrimenting the size as a new node is inserted.
            Temp_Node = NULL; //Nullfying the temp node because it has no use for us now.
        }
}
void Linked_List::Delete_Last()
{
    if(head !=NULL) //The Linked List is note empty.
    {
        node* Temp_Node = head;
        while (Temp_Node->next->next != NULL) //How is this possible to have 2 nexts? We use 2 nexts because we want to move the temp tp the place before the last node.
           Temp_Node = Temp_Node->next; //Moving the temp node to the position before the last node, which means that Temp_node -> next points to the last node.
        node* Temp_Node2 = Temp_Node->next; //Creating A new nTemp_Node2 to point to the Last Node.
        delete Temp_Node2; //
        Temp_Node2 = NULL; //
        Temp_Node2->next = NULL; //
        Temp_Node = NULL;//
        size--; //The size dcreased by one, so we decrement it by one.
    }
}
void Linked_List::Delete_First()
{
    if( head != NULL) //A condition that makes sure that the Linked List is not empty
    {
        node* temp = new node; /// Allocating a new memory space in the memomry and returns the address of the newly allocated and initialized memory to the New_Node pointer.
        temp = head; //The temp points to the first node as the head.
        head = head -> next; //Moving the head to point to the 2nd node so that the first one has no pointer pointing at it except the temp
        delete temp; //Deallocating the memory allocated to the temp fromthe heap
        temp = NULL; //Nullfying the temp to make sure it does not point to something
        size --;  //The size dcreased by one, so we decrement it by one.
    }
}

void Linked_List::Print()
{
    node* temp = head; //The temp points to the first node as the head.
    while(temp !=NULL) //A loop that ends as the temp reaches the end of the Linked List
    {
        cout << temp->key << endl; //Printingthe key of the node pointed to by the temp in Linked List on the screen to the user.
        temp = temp->next; //Advancing the temp pointer to the next node after printing the current one.
    }
    temp = NULL; //Nullfying the temp to make sure it does not point to something
}

#endif /* Normal_LL_hpp */
