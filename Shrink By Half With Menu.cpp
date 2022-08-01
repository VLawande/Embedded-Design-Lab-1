//Viraj Lawande
//EECE2160
//Lab 1

#include <iostream>
#include <string>

using namespace std;

//initialize all global variables
double *v;
int count;
int size;


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
    //delete the memory space associated with vector v;
    delete[] v;
}

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
    // make the old vector
    v = nv;
}

void Shrink() {
    //this function uses the same code as the Grow()function above it
    cout<<"\nShrinking Vector";
    cout<<"\nPrevious Capacity: "<<size<<" elements";
    //The only difference is that the size of the array is halved rather than doubled
    size = size/2;
    cout<<"\nNew Capacity: "<<size<<" elements";
    double *nv;
    nv = new double[size];
    for (int temp=0;temp<=size-1;temp++){
        nv[temp]=v[temp];
    }
    Finalize();
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
    for (int b = 0; b<=count-1; b++){                       //print out the elements of the old vector using a for loop
    cout<<"\nv["<<b<<"] = "<<v[b];
    }
}

void RemoveElement(){
    cout<<"\n\nRemoving last Element";
    // if there are no elements left to print, print error message to the user
    if (count==0){
        cout<<"\\nYour vector is empty, so we cannot remove an element as there are no elements left to remove";
    } else {
        count--;    //decrease the value of count by 1, so that when the user prints out the vectort hey are blocked from seeing
        float c = count*1.0;    //the element that they "removed" even though it is still in the cache for the array
        float d = size*1.0;
        if (c/d <=0.3){     //if the number of values in the array is less than 30 percent of the total capacity of the array
            Shrink();   //reduce the capacity of the array to save memory space
        }
    }
}

void InsertElement(){
    cout<<"\n\nInserting new element";
    //if inserting another element into the array would fill all the spaces in the array, double the size of the new array
    if (count == size){
        size = size*2;
    }
    //create variables to store the index and value of the element we are adding
    int index;
    int newElement;
    //prompt user to input index and value of the new element
    cout<<"\nEnter the index of the new array: ";
    cin>>index;
    cout<<"Enter the new element: ";
    cin>>newElement;
    double *nv;
    nv = new double[size];
    //fill array with elements from the old array up to the index of the new element
    for (int a=0; a<index; a++){
        nv[a] = v[a];
    }
    //set the value for the new element with the correct index
    nv[index]=newElement;
    count++;
    //fill the array with the remaining elements from the old array
    for (index; index<=size-1; index++){
        nv[index+1] = v[index];
    }
    Finalize();
    v = nv;
}

int main(){
    Initialize();
    int response;
    while (response != 5){
        cout<<"\nMain Menu:\n\n";
        cout<<"1. Print the array";
        cout<<"\n2. Append element at the end";
        cout<<"\n3. Remove last element";
        cout<<"\n4. Insert one element";
        cout<<"\n5. Exit\n";
        cout<<"Please select an option: ";
        cin>>response;
        switch (response){
            case 1:
                cout<<"You selected print the array"<<endl;
                PrintVector();
                break;
            case 2:
                cout<<"You selected append element at the end"<<endl;
                //if the number of elements in the array is equal to the size of the array
                //we must call Grow() to double the size of the array to make room for new elements
                if (count==size){
                Grow();
                }
                AddElement();
                break;
            case 3:
                cout<<"You selected remove last element"<<endl;
                RemoveElement();
                break;
            case 4:
                cout<<"You selected insert one element"<<endl;
                InsertElement();
                break;
            case 5:
                cout<<"You selcted exit"<<endl;
                Finalize();
                break;
            default:
                cout<<"Please enter either 1, 2, 3, 4, or 5"<<endl;
        }
    }
    return 0;
}
