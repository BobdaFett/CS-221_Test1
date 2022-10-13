//
// Created by lvas4 on 10/11/2022.
//

// Messing around with qsort algorithms with a std::list

#include <list>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void stdQSort(int* arr, int first, int last);
int partition(int* arr, int first, int last);
void swap(int* a, int* b);

void listSort(list<int> ls, list<int>::iterator first, list<int>::iterator last);
list<int>::iterator listPartition(list<int> ls, list<int>::iterator first, list<int>::iterator last);
void listSwap(list<int>::iterator *a, list<int>::iterator *b);

void testing(list<int>& ls);

// Functions that are an attempt at following the directions.
void testSort(list<int>& ls);

ostream& operator << (ostream& out, list<int> ls);

int main() {

    cout << "Testing the qsort algorithm." << endl;
    list<int> numbers1, numbers3;
    int numbers2[10];
    for (int i = 0; i < 10; i++)
        numbers1.push_back(rand());
    for (int & i : numbers2)
        i = rand();
//    for (int i = 0; i < 9; i++)
//        numbers3.push_back(rand());
    numbers3 = {32391, 14604, 3902, 292, 153, 12382, 17421, 18716, 19718};

    cout << "Testing stdQSort..." << endl;
    stdQSort(numbers2, 0, 10);
    cout << "Testing listSort..." << endl;
    listSort(numbers1, numbers1.begin(), numbers1.end());
    cout << "Testing testSort..." << endl;
    testing(numbers3);

    cout << "listSort: " << numbers1 << endl;
    cout << "stdQSort: ";
    for (int i : numbers2)
        cout << i << " ";
    cout << "\ntestSort: " << numbers3 << endl;

    return 0;
}

void stdQSort(int* arr, int first, int last) {
    if (first > last) {
        int pi = partition(arr, first, last);

        stdQSort(arr, first, pi - 1);
        stdQSort(arr, pi + 1, last);
    }
}

int partition(int* arr, int first, int last) {
    int pivot = arr[first];
    int i = last - 1;

    for (int j = first; j < last; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i+1], &arr[last]);
    return i + 1;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void listSort(list<int> ls, list<int>::iterator first, list<int>::iterator last) {

    // This condition will never be false. Should compare iter and see if they're larger, not equal
    if (first == last) {
        auto pi = listPartition(ls, first, last);

        listSort(ls, first, prev(pi, 1));
        listSort(ls, next(pi, 1), last);
    }
}

list<int>::iterator listPartition(list<int> ls, list<int>::iterator first, list<int>::iterator last) {
    auto pivot = first, i = last;

    for (auto j = ls.begin(); j != last; j++) {
        if (*j < *pivot) {
            i++;
            std::swap(i, j);
        }
    }
    i++;
    std::swap(i, last);
    return next(i, 1);
}

// Functions that are an attempt at following the directions.
void testSort(list<int>& ls) {
    // less, greater := two empty arrays
    list<int> less, other;
    auto ptr = ls.begin();

    // if length(array) > 1
    if (ls.size() > 1) {
        cout << "Size: " << ls.size() << " " << ls << endl;
        //for each x in array
        for (ptr; ptr != ls.end(); ptr++) {
            // if x < pivot then add x to less
            if (*ptr < *ls.begin())
                less.push_back(*ptr);

            // if x >= pivot then add x to greater
            if(*ptr >= *ls.begin())
                other.push_back(*ptr);
        }

        // quicksort(less/greater)
        testSort(less);
        testSort(other);

        // array := concatenate(less, equal, greater)
        ls.clear();
        ptr = ls.begin();
        for(auto x : less)
            ls.push_back(x);
        for(auto x : other)
            ls.push_back(x);
    } else if (ls.size() <= 1) {
        cout << ls.size() << endl;
    }
}

void testing(list<int>& ls) {
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
    cout << "Size: " << ls.size() << " " << ls << endl;

    if(ls.size() <= 1) return;

    testing(less);
    for (auto x : less)
        ls.insert(ptr++, x);
    ls.insert(ptr++, *pivot);
    testing(other);
    for(auto x : other)
        ls.insert(ptr++, x);
}

ostream& operator << (ostream& out, list<int> ls) {
    list<int>::iterator pos;
    for (pos = ls.begin(); pos != ls.end(); pos++)
        cout << *pos << " ";
    return out;
}