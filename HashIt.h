/* HashIt.h
This is the definition of a class that will be used
to hash given values and store them in a container.
Written by Christopher D. Muench
December 2016
C++ (MinGW G++)
Hash function used = ((first) + (last))%ARRAY_SIZE
*/

#include <iostream>
#include <string>

#ifndef HASHIT
#define HASHIT
using namespace std;

const int ARRAY_SIZE = 23;
const int NUM_STRINGS = 15;

class HashIt
{
public:
    //Data Members
    string hashTable[ARRAY_SIZE];
    //Function members
    void construct()
    { //Constructs an array to store hashed values
        int loop = 0;
        for(loop = 0; loop < ARRAY_SIZE; loop++) //enter loop to fill table with a base value
        {
            hashTable[loop] = "\0";
        }

    }

    void hashInput()
    { //hashInput function takes argument of first + last character of string, and string to input
        string hashedString;
        char first;
        char last;
        for (int loopCount = 0; loopCount < NUM_STRINGS; loopCount++) //enter loop to hash user input values into table
            {
                cout << "Please enter a string to be hashed: "; //get string to hash
                cin >>hashedString;
                string::iterator firstIterator = hashedString.begin(); //get first letter of string
                string::iterator lastIterator = hashedString.end() - 1; //get last letter of string
                first = *firstIterator;
                last = *lastIterator;
                int hashPosition = 0;
                hashPosition = ((first) + (last))%ARRAY_SIZE; //use has function to set best case
                if (hashTable[hashPosition] == "\0") //test if hash position holds "empty" value
                    {
                        hashTable[hashPosition] = hashedString; //place string in position
                    }
                else //if ideal spot filled, move into while loop to move through array until "empty" spot is found
                {    //then deposit string in nearest empty spot
                    while (hashTable[hashPosition] != "\0")
                    {
                        hashPosition++;
                        if (hashPosition > ARRAY_SIZE - 1)
                        {
                            hashPosition = 0;
                        }

                        if (hashTable[hashPosition] == "\0" ) //places string in next sequentially available space
                        {
                            hashTable[hashPosition] = hashedString;
                            break;
                        }
                    }
                }
            }

    }

    void findValue()
    { //function to search array for desired string and display whether it is present or not
        string searchFor;
        char first,last;
        while (searchFor != "quit")
        {
            bool found = false; //flag value
            cout <<"Please enter a string to search hash table for."<<endl
            <<"Enter 'quit' to stop searching: "; //get string to search for, establish sentinel condition
            cin >>searchFor;
            if (searchFor == "quit")
            {
                break;
            }
            string::iterator firstIterator = searchFor.begin(); //get first letter of string
            string::iterator lastIterator = searchFor.end() - 1; //get last letter of string
            first = *firstIterator;
            last = *lastIterator;
            int hashPosition = 0; //set hash position to 0
            hashPosition = ((first) + (last))%ARRAY_SIZE; //rehash value to know where to begin search
            if (hashTable[hashPosition] == searchFor) //if value is at expected position (best case), found set to true
            {
                found = true;
            }
            else
            {
                int maxSearch = 0;
                while (maxSearch < ARRAY_SIZE && found == false) //perform one full traversal of the array to test
                {                                                //if value is present, if it is drop out
                    hashPosition++;
                    if (hashPosition > ARRAY_SIZE - 1)       //dont allow hashposition to go beyond bounds of array
                    {
                        hashPosition = 0;
                    }

                    if (hashTable[hashPosition].compare(searchFor) == 0) //if found flag set to true
                    {
                        found = true;
                    }
                    maxSearch++;
                }
            }
            if (found == true) //determine whether value is present or not and display
            {
                cout <<"Value found: "<<boolalpha<<found<<" Position: "<<hashPosition<<endl;
            }
            else
            {
                cout <<"Value found: "<<boolalpha<<found<<endl;
            }

        }
    }

    void display()
    { //function to display all elements of array
        for (int showIt = 0; showIt < ARRAY_SIZE; showIt++) //iterate through the array and print each position
        {
            cout <<"Position: "<<showIt<<" Value: "<< hashTable[showIt]<< endl;
        }
    }
};
#endif // HASH
