///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Rachel Vetter
// Email:            racheevee99@gmail.com
// Label:            A02
// Title:            Comments
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       This program implements a class that allows a linked list to be used just like 
//       an array. It overloads the "[]" (square brackets) to simulate accessing seperate 
//       array elements, but really it traverses the list to find the specified node using
//       an index value. It also overloads the "+" sign allowing a user to "add"
//       or "push" items onto the end of the list.
//
// Files:            none
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int A[100];         //global array of 100 integers

/**
 * Struct Node
 * 
 * Description:
 *      creates nodes used in a linked list
 * 
 * Public Methods:
 *                  Node()
 *                  Node(int n)
 *      
 */
struct Node {
    int x;          //integer stored in node
    Node *next;     //node that this node points to
    Node() {
        x = -1;
        next = NULL;
    }
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/**
 * Class List
 * 
 * Description:
 *      Description of your class and what it does
 * 
 * Public Methods:
 *                  List()
 *      void        Push(int val)
 *      void        Insert(int val)
 *      void        PrintTail()
 *      string      Print()
 *      int         Pop()
 *      List        operator+(const List &Rhs)
 *      int         operator[](int index)
 *      friend      ostream &operator<<(ostream &os, List L)
 * 
 * Private Methods:
 *      Node        Head
 *      Node        Tail
 *      int         Size
 * 
 * Usage: 
 * 
 *      Push(int val);      inserts a node onto the tail of the list
 *      Insert(int val);    inserts a node at the head of the list
 *      PrintTail();        prints the value at the tail of the list
 *      Print();            print the values in the list
 *      Pop();              decrements size of list    
 */
class List {
private:
    Node *Head;     //Pointer to the head of the list
    Node *Tail;     //Pointer to the tail of the list
    int Size;       //size of the list

public:
    /**
     * Public : List
     * 
     * Description:
     *      Default constructor
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      none
     */
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    /**
     * Public : Push
     * 
     * Description:
     *      inserts a node at the tail end of the list
     * 
     * Params:
     *      [int]   :   value
     * 
     * Returns:
     *      void
     */
    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    /**
     * Public : Insert
     * 
     * Description:
     *      inserts a node onto the tail of the list
     * 
     * Params:
     *      [int]   :   value
     * 
     * Returns:
     *      void
     */
    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // inserts node at the head of the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

    /**
     * Public : PrintTail
     * 
     * Description:
     *      prints the value of the node at the tail of the list
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      void
     */
    void PrintTail() {
        cout << Tail->x << endl;
    }

    /**
     * Public : Print
     * 
     * Description:
     *      inserts a node onto the tail of the list
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      [string] list   :   the list as a string 
     */
    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    /**
     * Public : Pop
     * 
     * Description:
     *      decrements size
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      [int] 0     :   the integer value of 0
     */
    // not implemented
    int Pop() {
        Size--;
        return 0; 
    }

    /**
     * Public : operator+
     * 
     * Description:
     *      overloads the + operator
     * 
     * Params:
     *      [List]   :   const &Rhs
     * 
     * Returns:
     *      [List] NewList      :   new concatenated version of lists
     */
    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    /**
     * Public : operator[]
     * 
     * Description:
     *      overloads the [] operator
     * 
     * Params:
     *      [int]   :   index
     * 
     * Returns:
     *      [int] Temp->x   :   the value in temp node
     */
    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    /**
     * Public : operator<<
     * 
     * Description:
     *      
     * 
     * Params:
     *      [ostream]   :   &os
     *      [List]      :   L
     * 
     * Returns:
     *      [ostream] os    :   ostream
     */
    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {
    List L1;        //default instantiation of a List
    List L2;        //default instantiation of a List

    for (int i = 0; i < 25; i++) {
        L1.Push(i);         //stores values 0-25 into List1
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);         //stores values 50-100 into List2
    }

    //cout << L1 << endl;
    L1.PrintTail();     //Prints tail of list 1
    L2.PrintTail();     //Prints tail of list 2

    List L3 = L1 + L2;      //Adds List1 and List2 and 
    cout << L3 << endl;     //Displays List3

    cout << L3[5] << endl;  //Displays element 5 in List3
    return 0;
}
