///////////////////////////////////////////////////////////////////////////////
//
// Author:           Rachel Vetter
// Email:            racheevee99@gmail.com
// Label:            P01
// Title:            Assignment 4 - Resizing the Stack
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 *      - See class below
 *
 * Usage:
 *      - See main program
 *
 */
class ArrayStack {
private:
    long int* A;           // pointer to array of int's
    int size;         // current max stack size
    int top;          // top of stack 
    int maxSize;  // Keeps track of overall max stack size
    int resize;   //Keeps track of resizes

public:
    /**
     * ArrayStack
     *
     * Description:
     *      Constructor no params
     *
     * Params:
     *     - None
     *
     * Returns:
     *     - NULL
     */
    ArrayStack() {
        size = maxSize = 10;
        A = new long int[size];
        top = -1;
        resize = 0;
    }

    /**
     * ArrayStack
     *
     * Description:
     *      Constructor size param
     *
     * Params:
     *     - int size
     *
     * Returns:
     *     - NULL
     */
    ArrayStack(int s) {
        size = maxSize = s;
        A = new long int[s];
        top = -1;
        resize = 0;
    }

    /**
     * Public bool: Empty
     *
     * Description:
     *      Stack empty?
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [bool] true = empty
     */
    bool Empty() {
        return (top <= -1);
    }

    /**
     * Public bool: Full
     *
     * Description:
     *      Stack full?
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [bool] true = full
     */
    bool Full() {
        return (top >= size - 1);
    }

    /**
     * Public int: Peek
     *
     * Description:
     *      Returns top value without altering the stack
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [int] top value if any
     */
    int Peek() {
        if (!Empty()) {
            return A[top];
        }

        return -99; // some sentinel value
                    // not a good solution
    }

    /**
     * Public int: Pop
     *
     * Description:
     *      Returns top value and removes it from stack
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [int] top value if any
     */
    int Pop() {
        if (!Empty()) {
            if ((top < 0.5 * size) && (size > 10)) {
                ContainerShrink();
            }
            return A[top--];
        }

        return -99; // some sentinel value
                    // not a good solution
    }

    /**
     * Public void: Print
     *
     * Description:
     *      Prints stack to standard out
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      NULL
     */
    void Print() {
        cout << "######################################################################\n"
            << "\tAssignment 4 - Resizing the Stack\n\tCMPS 3013\n\tRachel Vetter\n\n"
            << "\tMax Stack Size: " << maxSize << "\n\tEnd Stack Size: " << size <<
            "\n\tStack Resized: " << resize << " times\n\n"
            << "######################################################################";
    }

    /**
     * Public bool: Push
     *
     * Description:
     *      Adds an item to top of stack
     *
     * Params:
     *      [int] : item to be added
     *
     * Returns:
     *      [bool] ; success = true
     */
    bool Push(long int x) {
        if (Full()) {
            ContainerGrow();
        }
        else{
            A[++top] = x;
            size++;
            if (size > maxSize) {
                maxSize = size;
            }
            return true;
        }

        return false;

    }

    /**
     * Public void: ContainerGrow
     *
     * Description:
     *      Resizes the container for the stack by doubling
     *      its capacity
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      NULL
     */
    void ContainerGrow() {
        int newSize = size * 1.75;    // increases size of memmory by 1.75
        long int* B = new long int[newSize];  // allocate new memory

        for (int i = 0; i < size; i++) {    // copy values to new array
            B[i] = A[i];
        }

        delete[] A;                // delete old array

        size = newSize;             // save new size

        A = B;                      // reset array pointer

        resize++;
    }

    /**
      * Public void: ContainerShrink
      *
      * Description:
      *      Resizes the container for the stack by doubling
      *      its capacity
      *
      * Params:
      *      NULL
      *
      * Returns:
      *      NULL
      */
    void ContainerShrink() {
        int newSize = size * 0.5;    // decreases size of memory by half
        long int* B = new long int[newSize];  // allocate new memory

        for (int i = 0; i < size; i++) {    // copy values to new array
            B[i] = A[i];
        }

        delete[] A;                // delete old array

        size = newSize;             // save new size

        A = B;                      // reset array pointer

        resize++;
    }

};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
    ifstream infile;

    char infileName[40];
    cout << "Please enter the input file name: ";
    cin >> infileName;
    infile.open(infileName);

    ArrayStack stack;
    long int r = 0, er = 0;

    while (infile >> r) {
        if (r % 2 == 0) {
            stack.Push(r);
            if (!stack.Push(r)) {
                cout << "Push failed" << endl;
            }
        }
        else
        {
            er = stack.Pop();
            if (er == -99) {
                cout << "Pop failed" << endl;
            }
        }
    }

    stack.Print();

    //Close files
    infile.close();
}
