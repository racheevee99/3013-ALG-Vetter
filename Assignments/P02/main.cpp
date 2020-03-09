//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Rachel Vetter
// Email:            racheevee99@gmail.com
// Label:            P02
// Title:            Assignment 6 - Processing in Log Time
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       Using a singly linked list to store words and their definitions
//      then searching through them as each character is entered.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "JsonFacade.hpp"       // need to grab a copy from resources folder
#include <time.h>
#include <chrono> 
#include "Timer.hpp"            // need to grab a copy from resources folder
#include "mygetch.hpp"

using namespace std;

using json = nlohmann::json;

struct WordNode{
		string word;
        string definition;
        WordNode *next;
		WordNode(string w, string d, WordNode *n = NULL){
        word = w;
        definition = d;
        next = n;
        }
};


int main()
{
    WordNode *head = NULL;
    Timer T;
    JsonFacade J("dict_w_defs.json");   // create instance of json class
    head = new WordNode(J.getKey(0), J.getValue(J.getKey(0))); //initialize head
    //load linked list with values using JsonFacade
    for(int i = 1; i < J.getSize(); i++)
    {
        head = new WordNode(J.getKey(i), J.getValue(J.getKey(i)), head);
    }
    int count = 0;                  // initialize counter
    char k;
    string words[10];               //array to hold first 10 matching words
    string key = "";                // key variable to access json object

    //Prompt
    cout << "Begin entering the word you wish to search for." 
     << " Enter a period when you are done.\n\n";
    
    //Loop to search for words as characters are entered
    while((k = getch()) != '.')
    {
        count = 0;      //reset count
        for (int i = 0; i < 10; i++)
        {
            words[i] = "";      //reset words array
        }
        key += k;   //append char to key
        cout << key;        //display current key
        WordNode *temp;
        temp = head;
        T.Start();          //start timer
        while (temp->next != NULL){
            string w = temp->word;
            bool t = true;
            for (int n = 0; t && (n < key.size()); n++){
                if (key[n] == w[n])
                {
                    t = true;       //characters match
                }
                else
                {
                    t = false;
                }  
            }
            if (t)      //if all characters in key match
            {
                if(count < 10)
                {
                    words[count] = w;    //add 1st ten to array
                }
                count++;            //increment count
            }
            temp = temp->next;      //traverse list
        }
        T.End();            //end timer
        double s = T.Seconds();
        cout << endl << count << " words found in " << s << " seconds.\n";
        for (int i = 0; i < 10 && i < count; i++)
        {
            cout << words[i] << " ";    //display 1st ten words
        }
        cout << "\n\n";
    }
    
    //Delete list
    while (head->next != NULL)
    {
        WordNode *temp;
        temp = head;
        head = head->next;
        temp = NULL;
        delete temp;
    }
    return 0;
}