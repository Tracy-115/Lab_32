#include "Car.h"//included the Car.h file
#include <deque> //added deque to my code
using namespace std;

int main(){

    deque <Car> Cque;
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
    Cque.back().print(); //printing the back
    return 0;
}
