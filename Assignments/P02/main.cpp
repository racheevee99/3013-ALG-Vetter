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
    head = new WordNode(J.getKey(0), J.getValue(J.getKey(0)));
    for(int i = 1; i < J.getSize(); i++)
    {
        head = new WordNode(J.getKey(i), J.getValue(J.getKey(i)), head);
    }
    int count = 0;                      // 
    char k;
    string words[10];
    string key = "";                        // key variable to access json object

    cout << "Begin entering the word you wish to search for." 
     << " Enter a period when you are done.\n\n";
    
    while((k = getch()) != '.')
    {
        count = 0;      //reset count
        for (int i = 0; i < 10; i++)
        {
            words[i] = "";      //reset words array
        }
        key += k;   //append char to key
        cout << key;
        WordNode *temp;
        temp = head;
        T.Start();
        while (temp->next != NULL){
            string w = temp->word;
            bool t = true;
            for (int n = 0; t && (n < key.size()); n++){
                if (key[n] == w[n])
                {
                    t = true;
                }
                else
                {
                    t = false;
                }  
            }
            if (t)
            {
                if(count < 10)
                {
                    words[count] = w;
                }
                count++;
            }
            temp = temp->next;
        }
        T.End(); 
        double s = T.Seconds();
        cout << endl << count << " words found in " << s << " seconds.\n";
        for (int i = 0; i < 10 && i < count; i++)
        {
            cout << words[i] << " ";
        }
        cout << "\n\n";
    }
    
    
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