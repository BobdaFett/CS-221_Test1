//
// Created by Lucas Vas on 10/11/2022.
//

#include <string>
#include <list>
#include <iostream>
using namespace std;

void quickSort(list<int>& ls);
ostream& operator << (ostream& out, list<int> lst);

int main()
{
    list<int> numbers;
    auto pos = numbers.begin(); // IDE says to use auto typing.
    //Generate random numbers to populate the list
    for (int i = 0; i < 10; i++)
        numbers.push_back(rand());

    //Print the list
    cout << "Created list: ";
    cout << numbers << endl;

    // Call your function to sort the list implementing
    // the Quick Sort algorithm with pivot the first element
    // and partitioning using temporary lists
    quickSort(numbers);

    //Print the sorted list
    cout << "Sorted list: ";
    cout << numbers << endl;

    return 0;
}

/// This whole sort doesn't work... and not for lack of trying.
/// Duplicates some items while not sorting any of the rest.
/// Edit: works. Commented the changes next to the line that was causing the issue, and why.
void quickSort(list<int>& ls) {
    if (ls.front() == ls.back()) return;

    auto ptr = ls.begin();
    int pivot = *ptr; // This was originally an iterator
    list<int> less, other;
    ptr++; // forgot to increment this iterator

    for (ptr; ptr != ls.end(); ptr++) {
        if (*ptr < pivot)
            less.push_back(*ptr);
        else
            other.push_back(*ptr);
    }

    ptr = ls.begin();

    // Didn't have this if statement
    if (!less.empty()) {
        quickSort(less);
        for (auto x : less) {
            // This messes things up. Simply set iterator equal to.
//            ls.insert(ptr++, x);
            *ptr = x;
            ptr++;
        }
    }

//    ls.insert(ptr++, pivot);
    *ptr = pivot;
    ptr++;

    // Didn't have this if statement
    if (!other.empty()) {
        quickSort(other);
        for(auto x : other) {
//            ls.insert(ptr++, x);
            *ptr = x;
            ptr++;
        }
    }
}

ostream& operator << (ostream& out, list<int> lst) {
    list<int>::iterator pos;
    for (pos = lst.begin(); pos != lst.end(); pos++)
        cout << *pos << " ";
    return out;
}
