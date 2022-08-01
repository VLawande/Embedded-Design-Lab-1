//Viraj Lawande
//EECE2160
//Assignment 1.3

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


double *v;
int count;
int size;

void Grow() {
    cout<<"\nVector grown";
    cout<<"\nPrevious Capacity: "<<size<<" elements";
    size = size*2;
    cout<<"\nNew Capacity: "<<size<<" elements";
    //create new local pointer
    double *nv;
    //create new vector assigned to the pointer
    nv = new double[size];
    //assign old vector components to new vector
    for (int temp=0;temp<=size-1;temp++){
        nv[temp]=v[temp];
    }
    //free memory allocated for the old vector
    delete[] v;
    //set the old pointer to point to the new memory space
    v = nv;
}

void AddElement(){
    //create new local Element
    int newElement;
    //prompt user to enter new Element
    cout<<"\nEnter the new Element: ";
    cin>>newElement;
    //set the user input as the next free bit in the array
    v[count] = newElement;
    //increase the bit counter by 1
    count++;
}


void PrintVector(){
    //print out the elements of the old vector using a for loop
    for (int b = 0; b<=count-1; b++){
        cout<<"\nv["<<b<<"] = "<<v[b];
    }
}

void RemoveElement(){
    //decrease the value of count by 1, so that when the user prints out the vector
    //they are blocked from seeing the element that they "removed"
    //even though it is still in the cache for the array
    count--;
}

void Initialize() {
    //initialize a size for the vector, and create a vector of said size
    size = 2;
    v = new double[size];
    //prompt the user to assign values for the various bits in the vector
    for (int a = 0; a <= size-1; a++){
        cout<<"v["<<a<<"]= ";
        cin>>v[a];
        count++;
    }
}

void Finalize() {
    //make sure that the memory space used for v is deleted
    delete[] v;
}

int main() {
    Initialize();

    //call function Grow()
    Grow();

    //call function PrintVector()
    PrintVector();

    AddElement();

    PrintVector();

    RemoveElement();

    PrintVector();

    Finalize();
    return 0;
}
