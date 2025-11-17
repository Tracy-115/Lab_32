#include "Cars.h"//included the Car.h file
#include <deque> //added deque to my code
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Your code has created the array of deques, and tests operations on this complex data structure to validate it.

int main(){
    const int leave = 46, join = 39, shift = 15;
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
    for (int t=0; t < 20; t++){
        cout << "Time: " << t+1 << endl;
        int n = 1;
        int percent = rand() % 100;
        for(int i =0; i < lane; i++){
            cout << endl;
            cout << "Lane " << n << endl;
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
            n++;
        }
        for(int i =0; i < lane; i++){
            if (percent < leave){ //the paid and joined loops are pretty similar to the onees above
                cout << "Paid: ";
                Cque[i].front().print();
                cout << endl;
                Cque[i].pop_front();
            }
            else if (percent < leave + join){
                Cque[i].push_back(Car());
                cout << "Joined: ";
                Cque[i].back().print();
            }
            else if (percent < leave + join + shift){
                Car temp = Cque[i].back(); //what i did here was I stored one data into temp and then remove it from the initial lanne, and then add it into a new lane
                Cque[i].pop_back();
                int Lane;
                Lane = rand()%lane;
                Cque[Lane].push_back(temp);
                cout << "Switched: ";
                Cque[Lane].back().print();

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
        }
}
/*The three possible operations and their probabilities are:

46% probability that the car at the head of the queue pays its toll and leaves the queue
39% probability that another car joins the queue
15% probability that the rear car will shift lanes
All these probability values need to be stored as constants defined in your program, never in hard-coding.*/
    return 0;
}
