/*
* Course: COEN 2220 - Programming 2
* Name: Eduardo Vega 
* Lab: Lab 7 - Abstract Data Types 
* Description: Guided example - ADT contract, implementacion, and client code
* Due date: 10/1/2016
*/

#include <iostream>
#include <string>
using namespace std;

/*
* BookHoldlog ADT
*
* Data:
* A sequence of up to four book hold IDs.
*
* Operations:
* addHold(id): Adds one book hold ID when space remains; return whether it was added.
* contains(id): Reports whether an equal book hold ID is stored.
* size(): Returns the number of stored hold IDs.
* isEmpty(): Reports whether no hold IDs are stored.
*/

class BookHoldLog
{
private:
    static const int CAPACITY = 4;
    string holdIds[CAPACITY];  // the implementation stores IDs in a fixed array.
    int count;                 // the implementation tracks used array positions.
    
public:
    BookHoldLog()
    {
        count = 0;            // A new log begins with no stored hold IDs.
    }

    int size() const
    {
        return count;        // client code may ask for the count, but cannot change it.
    }

    bool isEmpty() const
    {
        return count == 0;   // the log is empty exactly when no ids are stored.
    }
     // --- B3: Add one book hold ID ---
    
    bool addHold(const string& holdId)
{
    if (count == CAPACITY)
    {
        return false;     // Do not write outside the fixed array capacity.
    }

    holdIds[count] = holdId;
    count++;
    return true;
}
    // --- B4: Search stored book hold IDs ---
    
    bool contains(const string& holdId) const
{
    for (int index = 0; index < count; index++)
    {
        if (holdIds[index] == holdId)
        {
            return true;  // Stop as soon as one matching ID is found.
        }
    }

    return false;         // No stored ID matched the requested value.
}
};

int main()
{
    cout << boolalpha;        // Print bool results as true or false.

    BookHoldLog holds;        // Client code creates one empty log object.

    cout << "Stored holds: " << holds.size() << endl;
    cout << "Log is empty: " << holds.isEmpty() << endl;

    // --- B3: Add book hold IDs through the public interface ---
    holds.addHold("BK-104");
    holds.addHold("BK-215");

cout << "Stored holds: " << holds.size() << endl;
    // --- B4: Search through the public interface ---
    cout << "Contains BK-215: " << holds.contains("BK-215") << endl;
    cout << "Contains BK-310: " << holds.contains("BK-310") << endl;

    return 0;
}