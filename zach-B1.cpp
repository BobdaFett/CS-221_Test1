// Name: Zachary Macey
// Email: macey011@wcsu.edu
// Test 1 Part B RESUBMISSION (program 1)
// Edited slightly by Lucas Vas - 10/13/2022

#include <string>
#include <list>
#include <iostream>
#include <ctime>

using namespace std;

ostream& operator << (ostream& out, list<int> lst);
void GenerateList(list<int>& numbers, int length);
void DisplayList(list<int> numbers);
void QuickSort(list<int>& numbers);

int main() {
    list<int> numbers;

    cout << "Generating list...\n";
    GenerateList(numbers, 25);
    cout << "List generated.\n\n";

    cout << "Unsorted list: ";
    cout << numbers;

    cout << "\n\nSorting list...\n";
    QuickSort(numbers);
    cout << "List sorted.\n\n";

    cout << "Sorted list: ";
    cout << numbers;

    cout << "\n\n-END OF PROGRAM-";
    return 0;
}

ostream& operator << (ostream& out, list<int> lst) {
    list<int>::iterator pos;
    for (pos = lst.begin(); pos != lst.end(); pos++)
        cout << *pos << " ";
    return out;
}

void GenerateList(list<int>& numbers, int length) {
    srand(time(NULL));
    for(int i = 0; i < length; i++)
        numbers.push_back(rand()%100);
}

void QuickSort(list<int>& numbers) {
    if (numbers.front() == numbers.back()) return;

    list<int> a, b;
    auto point = numbers.begin();
    int pivot = *point;
    point++;

    for (point; point != numbers.end(); point++) {
        if (*point < pivot)
            a.push_back(*point);
        else
            b.push_back(*point);
    }

    point = numbers.begin();

    if (!a.empty()) {
        QuickSort(a);
        for (int i : a) {
            *point = i;
            point++;
        }
    }

    *point = pivot;
    point++;

    if (!b.empty()) {
        QuickSort(b);
        for (int i : b) {
            *point = i;
            point++;
        }
    }
}