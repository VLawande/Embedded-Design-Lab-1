//Viraj Lawande
//EECE2160
//Assignment 1.1

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
    cout<<"Vector grown";
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
    // make the old vector
    v = nv;
}
void PrintVector(){
    //print out the elements of the old vector using a for loop
    for (int b = 0; b<=count-1; b++){
        cout<<"\nv["<<b<<"] = "<<v[b];
    }
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

    Finalize();

    return 0;
}
