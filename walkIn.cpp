#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"

//Description: model a walk-ln clinic system
//Author:Allen
//date: 1/23/2019


int main(void){
    
    string patient_name;
    string patient_Phone1,patient_Phone2, patient_Phone3;
    string patient_Email;
    string patient_Address;
    
    List* list = new List();
    
    string escape;
    std::cout<<"do you wanna escape? if yes, press Y else press N: ";
    getline(cin,escape);
    
    
    int maxelement = list->getMAXELEMENT();
    
    while (escape != "Y") {
        
        string choice;
        cout<<"Press 1 to insert, Press 2 to remove, Press 3 to remove all , Press 4  to search, Press 5 to print list , Press 6 to getElementCount"<<endl;
        getline(cin,choice);
        int count = list->getElementCount() ;
        if (choice == "1") {
            if (count < maxelement) {
                string careCard;
                std::cout<<"Enter care care number with at least 10 digits: ";
                getline(cin,careCard);
                Patient person (careCard);
                
                std::cout<<"Enter patient name: ";
                getline(cin,patient_name);
                person.setName(patient_name);
                
                std::cout<<"Enter patient Phone(first three numbers): ";
                getline(cin,patient_Phone1);
                std::cout<<"Enter patient Phone(middle three numbers): ";
                getline(cin,patient_Phone2);
                std::cout<<"Enter patient Phone(last four numbers): ";
                getline(cin,patient_Phone3);
                string phone_num = patient_Phone1+"-"+patient_Phone2+"-"+patient_Phone3;
                person.setPhone(phone_num);
                
                std::cout<<"Enter patient Email: ";
                getline(cin,patient_Email);
                person.setEmail(patient_Email);
                
                std::cout<<"Enter patient Address: ";
                getline(cin,patient_Address);
                person.setAddress(patient_Address);
                
                list->insert(person);
                
                std::cout<<"----------------------------"<<endl;
                list->printList();
                std::cout<<"----------------------------"<<endl;
                
            }else{
                std::cout<<"List is full"<<endl;
            }
            
        }else if (choice == "2"){
            string careCardNum;
            std::cout<<"Enter the careCard num: ";
            getline(cin , careCardNum);
            Patient person(careCardNum);
            bool check = list->remove(person);
            if (check == false) {
                std::cout<<careCardNum<<" is removed"<<endl;
                list->printList();
            }else{
                std::cout<<"person is not found"<<endl;
            }
            
        }else if (choice == "3"){
            list->removeAll();
        }else if (choice == "4"){
            string careCardNum;
            std::cout<<"Enter the careCard num: ";
            getline(cin , careCardNum);
            Patient person(careCardNum);
            Patient* tempperson = list->search(person);
            if(tempperson == NULL){
                cout<<"person not found"<<endl;
            }else{
                cout<<*tempperson<<endl;
                
                string notdone;
                cout<<"would you like to modify this person's info? Press Y to escape and N for no"<<endl;
                getline(cin , notdone);
                while (notdone != "Y") {
                    cout<<"Press 1 to modify this person's address"<<endl;
                    cout<<"Press 2 to modify this person's phone number"<<endl;
                    cout<<"Press 3 to modify this person's Email"<<endl;
                    cout<<"Press 4 to modify this person's Name"<<endl;
                    cout<<"Press 5 to modify this person's CareCard number"<<endl;
                    string options;
                    getline(cin,options);
                    string input;
                    if (options == "1") {
                        cout<<"Please enter new address"<<endl;
                        getline(cin,input);
                        tempperson->setAddress(input);
                    }else if (options == "2"){
                        cout<<"Please enter new phone number"<<endl;
                        getline(cin,input);
                        tempperson->setPhone(input);
                    }else if (options == "3"){
                        cout<<"Please enter new email"<<endl;
                        getline(cin,input);
                        tempperson->setEmail(input);
                    }else if (options == "4"){
                        cout<<"Please enter new Name"<<endl;
                        getline(cin,input);
                        tempperson->setEmail(input);
                    }else if (options == "5"){
                        cout<<"Please enter new care card number"<<endl;
                        string newnum;
                        getline(cin,newnum);
                        tempperson->resetCareCard(newnum);
                        
                    }
                    cout<<"would you like to escape? Press Y for yes else Press N "<<endl;
                    getline(cin, notdone);
                }
                
            }
            
        }else if (choice == "5"){
            list->printList();
        }else if (choice == "6"){
            cout<<list->getElementCount()<<" number of Patient(s)"<<endl;
        }
        std::cout<<"do you wanna escape? if yes, press Y else press N: ";
        getline(cin,escape);
    }
    
    delete list;
    
}
