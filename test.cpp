#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"
int main(void){
    // Variables declaration
    List* patients = new List();  // Heap-allocated List object
    // List patients;
    // Stack-allocated List object
    
    Patient p2345678901("2345678901");
    p2345678901.setName("Allen");
    p2345678901.setPhone("6047812161");
    p2345678901.setAddress("2902 Meadowvista Place");
    p2345678901.setEmail("wei.youmn@gmail.com");
    
    
    Patient p3456789012("3456789012");
    p3456789012.setName("Allens");
    p3456789012.setPhone("60478121612");
    p3456789012.setAddress("2902 Meadowvista Place3for");
    p3456789012.setEmail("wei.youmn@gmail.com3");
    
    Patient p5678901234("5678901234");
    p5678901234.setName("Allens");
    p5678901234.setPhone("60478121612");
    p5678901234.setAddress("2902 Meadowvista Place4");
    p5678901234.setEmail("wei.youmn@gmail.com33hello");
    
    Patient p1678901234("1678901");
    p1678901234.setName("Allens");
    p1678901234.setPhone("60478121612");
    p1678901234.setAddress("2902 Meadowvista Place4");
    p1678901234.setEmail("wei.youmn@gmail.com3");
    
    
    cout << "\nTest case 1: Add Patient 2345678901 to an empty List."<<endl;
    patients->insert(p2345678901);
    patients->printList();
    
    
    cout<<"----------------------------------------------"<<endl;
    
    cout << "Test case 2: Add Patient 5678901234 to a List already containing one element."<<endl;
    patients->insert(p5678901234);
    patients->printList();
    
    cout<<"----------------------------------------------"<<endl;
    
    cout << "Test case 3: Add Patient 3456789012 to a List already containing two elements."<<endl;
    patients->insert(p3456789012);
    patients->printList();
    
    cout<<"----------------------------------------------"<<endl;
    
    cout << "Test case 4: Add Patient 3456789012 to a List already containing three elements."<<endl;
    patients->insert(p1678901234);
    patients->printList();
    cout<<patients->getElementCount()<<endl;
    
    cout<<"----------------------------------------------"<<endl;
    
    cout << "Test case 5: Add Patient 3456789012 to a List already containing four elements. Again"<<endl;
    patients->insert(p3456789012);
    patients->printList();
    
    cout<<patients->getElementCount()<<endl;
    
    
    cout << "Test case 5: Remove Patient 5678901234 from the List.";
    patients-> remove(p5678901234);
    cout << "Expected result: patient 5678901234 no longer on the List:";
    cout << "\nActual result: There are now " << patients->getElementCount() << " patients in List." << endl;
    patients->printList();
    
    cout<<patients->getElementCount()<<endl;
    
    cout<<"test case  : search user"<<endl;
    Patient* person = patients->search(p2345678901);
    person->setPhone("new");
    cout<<person->getPhone()<<endl;
    cout<<"----------------------------------------------"<<endl;
    patients->printList();
    cout << "Test case 6: Remove All the Patients from the List.";
    patients-> removeAll();
    cout << "Expected result: All patients removed from the List:";
    cout << "\nActual result: There are now " << patients->getElementCount() << " patients in List." << endl;
    patients->printList();
    
    
   
    
    delete patients;  // Heap-allocated List object
    
    
    
    
    return 0;
}
