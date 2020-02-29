#include <iostream>
#include <string>
#include "JsonFacade.hpp"       // need to grab a copy from resources folder
#include <time.h>
#include <chrono> 
#include "Timer.hpp"            // need to grab a copy from resources folder
#include "mygetch.hpp"

using namespace std;


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
    T.Start();
    JsonFacade J("dict_w_defs.json");   // create instance of json class
    head = new WordNode(J.getKey(0), J.getValue(J.getKey(0)));
    for(int i = 1; i < J.getSize(); i++)
    {
        head->next = new WordNode(J.getKey(i), J.getValue(J.getKey(i)));
    }
    T.End(); 
    double s = T.Seconds();
    long m = T.MilliSeconds();

    cout <<s << " seconds" <<endl;
    cout <<m << " milli" <<endl;
    int index = 0;                      // 
    char k;
    string key;                        // key variable to access json object

    vector<string> keys = J.getKeys();

    while((k = getch()) != '.')
    {
        key += k;   //append char to key
        for(int i =0; i < J.getSize(); i++)
     {
         if (key == keys.at(i))
         {
             cout << keys.at(i);
         }
     }
    }
    
    cout<<keys.size()<<endl;
    index = rand() % keys.size();
    key = J.getKey(index);

    cout<<key<<" = "<<J.getValue(key)<<endl;
    return 0;
}