#include "Car.h"//included the Car.h file
#include <deque> //added deque to my code
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Your code has created the array of deques, and tests operations on this complex data structure to validate it.

int main(){
    srand(time(0)); //so that it is random
    const int lane = 4; //this is to make sure I don't have over 2 objects
    deque<Car> Cque[4];
    // adding cars to wach of the lanes
    for (int i = 0; i <lane; i++){ //this goes through each lane
        for (int c= 0; c<2; c++){ //this addes 2 cars
            Cque[i].push_back(Car());
        }
    }

    //printing to see if it works this is a part of milestone 2
    cout << "Initial Queue" << endl;
    for (int i = 0; i <lane; i++){ //this one goes through all 4 lanes
        for(auto&c : Cque[i]){ //this one access the cars in each lane
        c.print();
        }
        cout << endl;
    }//because of the change in the first loop, this loop pack is going to print 2 cars for each lane

    int n = 1;
    for(int i =0; i < lane; i++){
        int percent = rand() % 100;
        cout << endl;
        cout << "Operation " << n << endl;
        if (percent < 50){ //changed to 50%
            Cque[i].push_back(Car());
            cout << "Car just joined: " ;
            Cque[i].back().print();
        }
        else {
            cout << "Just paid and left: "; //I added this before popping because after we pop, there will be a new car at the front 
            Cque[i].front().print();
            Cque[i].pop_front();
        }
        if(Cque[i].empty()){
            cout << "Queue now empty." << endl; //if the que is empty after going through if else statements, this will be printed
        }
        else {
            cout << "Queue: " << endl;
            for (auto&c : Cque[i]){
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
