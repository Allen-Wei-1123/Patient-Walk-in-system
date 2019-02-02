#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
//Author: Chen-Yu,Wei
//Last modification: 1/23/2019
//filename:List.cpp
//cpp file for List.h
List:: List(){};
int List::getElementCount() const{
    return elementCount;
}




bool List::insert(const Patient& newElement){
    
    for (int i = 0 ; i<elementCount; i++) {
        if (elements[i] == newElement ) {
            return false;
            
        }
    }
    
    bool check = true;
    if (elementCount == 0) {
        elements[0] = newElement;
        elementCount = elementCount + 1;
    }else{
        elements[elementCount] = newElement;
        int storei =0;
        bool check = true;
        for (int i = elementCount; i>0; i--) {
            if (elements[i-1] >  elements[i] ) {
                Patient temp = elements[i];
                elements[i] = elements[i-1];
                elements[i-1] = temp;
            }else {
                break;
            }
        }
        elementCount = elementCount+1;
    }
    return check;
}
bool List:: remove(const Patient& toBeRemoved){
    int count = 0;
    bool check = true;
    for (int i = 0 ; i<elementCount; i++) {
        Patient person = elements[i];
        if (person == toBeRemoved == false) {
            //
            elements[count] = person;
            count = count + 1 ;
        }else{
            check = false;
        }
    }
    elementCount = count;
    
    return check;
}

void List::removeAll(){
    elementCount = 0;
}

Patient* List::search(const Patient& target){
    if (elementCount == 0) {
        return NULL;
    }
    for (int i = 0; i < elementCount; i++) {
        Patient  *person = &elements[i];
        if (elements[i] == target) {
            return person;
        }
    }
    return NULL;
}

void List::printList(){
    for (int i = 0 ; i<elementCount; i++) {
        Patient person = elements[i];
        cout<<  person;
    }
}

void List::setCapacity(int size){
    capacity = size;
}

int List::getMAXELEMENT(){
    return MAX_ELEMENTS;
}


List::~List(){
    cout<<"list is deleted"<<endl;
}
