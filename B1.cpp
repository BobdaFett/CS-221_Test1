//
// Created by Lucas Vas on 10/11/2022.
//

#include <string>
#include <list>
#include <iostream>
#include <algorithm>
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
    cout << numbers << endl;

    // Call your function to sort the list implementing
    // the Quick Sort algorithm with pivot the first element
    // and partitioning using temporary lists
    quickSort(numbers);

    //Print the sorted list
    cout << numbers << endl;

    return 0;
}

/// This whole sort doesn't work... and not for lack of trying.
/// Duplicates some items while not sorting any of the rest.
void quickSort(list<int>& ls) {
    auto ptr = ls.begin();
    list<int> less, other;

    auto pivot = ptr++;
    if(*ptr >= *pivot) {
        other.push_back(*ptr);
        ptr++;
    } else if (*ptr < *pivot) {
        less.push_back(*ptr);
        ptr++;
    }

    ptr = ls.begin();

    if(ls.size() <= 1) return;

    quickSort(less);
    for (auto x : less)
        ls.insert(ptr++, x);
    ls.insert(ptr++, *pivot);
    quickSort(other);
    for(auto x : other)
        ls.insert(ptr++, x);
}

ostream& operator << (ostream& out, list<int> lst) {
    list<int>::iterator pos;
    for (pos = lst.begin(); pos != lst.end(); pos++)
        cout << *pos << " ";
    return out;
}
