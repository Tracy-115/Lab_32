#include "Car.h"//included the Car.h file
#include <deque> //added deque to my code
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Add More Lanes: There are now 4 toll booth lanes at play. Use an array to hold the lanes. The array will be of type deque<Car>. When the simulation starts, pre-populate the lanes with 2 cars like before. Each time period will now have operations happening on all lines.

int main(){
    srand(time(0)); //so that it is random
    const int lane = 4; //this is to make sure I don't have over 2 objects
    deque<Car> Cque[4];

    for (int i = 0; i <lane; i++){
        Cque.push_back(Car());
    }
    cout << "Initial Queue" << endl;
    for(auto&c : Cque){
        c.print();
    }
    int n = 1;
    while (!Cque.empty()){
        int percent = rand() % 100;
        cout << endl;
        cout << "Operation " << n << endl;
        if (percent < 45){ //45% that a new car is going to join the back of the queuw
            Cque.push_back(Car());
            cout << "Car just joined: " << endl;
            Cque.back().print();
        }
        else {
            cout << "Just paid and left: " << endl; //I added this before popping because after we pop, there will be a new car at the front 
            Cque.front().print();
            Cque.pop_front();
        }
        if(Cque.empty()){
            cout << "Queue now empty." << endl; //if the que is empty after going through if else statements, this will be printed
        }
        else {
            cout << "Queue: ";
            for (auto&c : Cque){
            c.print(); // the print() comed from Car.h file
            }
        }
        n++;

    }


    /*Milestone 1
    cout << "This is from milestone 1" << endl;
    Cque.push_back(Car());
    Cque.push_back(Car()); // added 2 cars to the back 

    cout << "Initially:" << endl;
    for (auto&c : Cque){
        c.print(); // the print() comed from Car.h file
    }
    Cque.pop_back(); //removing the front
    cout << "After popping:" << endl;
    for (auto&c : Cque){
        c.print();
    } 
    Cque.push_front(Car());
    Cque.pop_front(); //removing the back
    cout << "Size: " << Cque.size() << endl; //this will tell us how many objects are in there
    Cque.front().print(); //printing the front
    Cque.back().print(); //printing the back*/
    
    return 0;
}
