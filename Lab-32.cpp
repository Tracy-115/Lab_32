#include "Car.h"//included the Car.h file
#include <deque> //added deque to my code
using namespace std;

int main(){

    deque <Car> Cque;
    Cque.push_back(Car());
    Cque.push_back(Car()); // added 2 cars to the back 

    cout << "Initially:" << endl;
    for (auto&c : Cque){
        Cque.print();
    }


    Cque.pop_back(); //removing the front
    Cque.push_front(Car());
    Cque.pop_front(); //removing the back
    cout << Cque.size() << endl; //this will tell us how many objects are in there
    Cque.front(); //accessing the front
    Cque.back(); //accessing the back

}
