//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Rachel Vetter
// Email:            racheevee99@gmail.com
// Label:            H02
// Title:            Assignment 7 - Heapify
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       This program implements a heap.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

/**
 * Class Heap
 * 
 * @methods:
 *      constructors:
 *          Heap        : default constructor
 *          Heap(int)   : overload constructor with heap size
 *      private:
 *          BubbleUp    : puts a value in its proper place 
 *                          by swapping it up th heap
 *          Left        : finds index of left child
 *          OnHeap      : checks if index is on heap
 *          Parent      : finds parent of an index
 *          Right       : finds index of right child
 *          Swap        : swaps 2 places in heap
 *          /// Fix These:
 *          SinkDown    : puts a value in its proper place 
 *                          by swapping it down the heap
 *          PickChild   : Picks smallest child, if there are children
 *      public:
 *          Insert      : inserts value in heap
 *          Print       : prints out heap 
 *          Remove      : removes value from heap
 */
class Heap {
private:
    int size; // size of the array
    int *H;   // array pointer
    int end;  // 1 past last item in array

    /**
   * BubbleUp
   * 
   * @description: 
   *    This puts one value into its proper
   *    place in the heap.
   * 
   * @param  {int} index : index to start bubbling at
   * @return             : void
   */
    void BubbleUp(int index) {
        // check parent is not of beginning of array
        if (Parent(index) >= 1) {
            // index is on array and value is less than parent
            while (index > 1 && H[index] < H[Parent(index)]) {
                // do a swap
                Swap(index, Parent(index));

                // update index to values new position
                index = Parent(index);
            }
        }
    }

    /**
     * Left
     * @description:
     *      Calculates index of left child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of left child
     */
    int Left(int index) {
        return 2 * index;
    }

    /**
     * OnHeap
     * @description:
     *      Checks if an index is on the array (past the end).
     * 
     * @param  {int} index : index to check
     * @return {bool}      : 0 = off heap / 1 = on heap
     */
    bool OnHeap(int index) {
        return index < end;
    }

    /**
     * Parent
     * @description:
     *      Calculates parent of a given index.
     * 
     * @param  {int} index : index to check
     * @return {int}       : parent index
     */
    int Parent(int index) {
        return index / 2;
    }

    /**
     * Right
     * @description:
     *      Calculates index of right child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of right child
     */
    int Right(int index) {
        return 2 * index + 1;
    }

    /**
     * Swap
     * 
     * @description: 
     *      Swaps to values in the heap
     * 
     * @param  {int} i  : index in array
     * @param  {int} j  : index in array
     * @return          : void
     */
    void Swap(int i, int j) {
        int temp = H[i];
        H[i] = H[j];
        H[j] = temp;
    }

    ////////////////////////////
    //Fix These Methods
    ////////////////////////////

    /**
     * Heapify
     * 
     * @description: 
     *      
     * 
     * @param  {int*} A   :  array pointer with unsorted values to make into a heap
     * @param  {int} size :  size of new heap
     */
    void Heapify(int* A, int size) {
        // do it!
        for (int i = 1; i >= size; i++)
        {int left = 2*i, right = (2*i) + 1;
        int smallest = i;

        if(A[left] >= size && A[left] < A[smallest])
        {
            smallest = left;
        }
        if(A[right] >= size && A[right] < A[smallest])
        {
            smallest = right;
        }
        
        if(smallest != i)
        {
            int temp = A[i];
            A[i] = A[smallest];
            A[smallest] = temp;
        }
        }
    }

    /**
     * SinkDown
     * @description:
     *      Places one heap item into its proper place in the heap
     *      by bubbling it down to it proper location.
     * 
     * @param  {int} index  : index to start from in the array
     * @return              : void 
     */
    void SinkDown(int index) {
        if (index >= 1){ 
            while(index <=end && H[index] > H[PickChild(index)]){
                Swap(index, PickChild(index));
                index = PickChild(index);
            }
       }
    }

    /**
     * PickChild
     * @description:
     *      If one child exists, return it.
     *      Otherwise, return the smaller of the two.
     * 
     * @param  {int} index  : index of parent in the array
     * @return              : index to child 
     */
    int PickChild(int index) {
        //If there are 2 children, return smallest
        if(Right(index) <= end)
        {
            if (H[Right(index)] < H[Left(index)])
            {
                return Right(index);
            }
            else
            {
                return Left(index);
            }
            
        }
        //Return left if only 1 child
        else if (Left(index) <= end)
        {
            return Left(index);
        }
        else{
            cout << "No children.";
        }
       return index; //if no children return itself
    }

public:
    /**
   * Heap constructor
   */
    Heap() {
        size = 100;
        H = new int[size];
        end = 1;
    }

    /**
   * Heap constructor
   * 
   * @param  {int} s : heap size 
   */
    Heap(int s) {
        size = s;
        H = new int[s];
        end = 1;
    }

    /**
   * InsertAtEnd
   * 
   * @description:
   *        Add a value to the end of the heap.
   * 
   * @param  {int} x : value to Insert
   * @return         : void
   */
    void InsertAtEnd(int x) {
        H[end] = x;
        BubbleUp(end);
        end++;
    }

    /**
   * InsertAtFront
   * 
   * @description:
   *        Add a value to the end of the heap.
   * 
   * @param  {int} x : value to Insert
   * @return         : void
   */
    void InsertAtFront(int x) {
        for (int i = end; i >= 1; i--)
        {
          H[i+1] = H[i];
        }
        H[1] = x;
        SinkDown(1);
        end++;
    }

    /**
     * For test our heap !!!  
     */
    void Print() {
        for (int i = 1; i <= end - 1; i++) {
            cout << H[i];
            if (i < end - 1) {
                cout << "->";
            }
        }
    }

    /**
     * Remove
     * @description:
     *      Removes item from top of heap
     * 
     * @return {int}  : top of heap
     */
    int Remove() {
        int temp = H[1];
        H[1] = H[end];
        --end;

        return temp;
    }
};

int main() {
    Heap H;

    H.InsertAtEnd(17);
    H.InsertAtEnd(11);

    for (int i = 1; i <= 10; i++) {
        H.InsertAtEnd(i);
    }
H.Print();
cout << "\n\n";

  //Only made to test SinkDown
   H.InsertAtFront(20);
  H.InsertAtFront(12);

    H.Print();
}