#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SIZE = 3;
//constant for random prices
const int MIN = 10000, MAX = 99999;

class Chair {
private:
//legs on chair
    int legs;
//price history
    double * prices;
public:
    // constructors
    Chair() {
    //random number of legs, 3 or 4, random prices
        prices = new double[SIZE];
        legs = rand() % 2 + 3;
        for (int i = 0; i < SIZE; i++){
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
        }
    }
//set to specifc nuber of legs and price history
//arguments: l- legs, p[SIZE]- prices
    Chair(int l, double p[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++){
            prices[i] = p[i];
        }
    }

    // setters and getters
    //set number legs on chair
    //arguments: l- number of legs
    void setLegs(int l)      { legs = l; }
    //get number of legs o chair
    //return: number of legs
    int getLegs()            { return legs; }
    //set prices for price history
    //arguemnts: p1, p2, p3- price values
    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }
    //get average price history
    //return: average price
    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++){
            sum += prices[i];
        }
        return sum / SIZE;
    }
//print info of chair
    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++){
            cout << prices[i] << " ";
        }
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
//destructor- frees up memory
    ~Chair(){
        delete[] prices;
    }
};

int main() {
    //random generator for time
    srand(time(0));
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->print();
    delete chairPtr;

    //creating dynamic chair object with constructor
    double prices[SIZE]= {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, prices);
    livingChair->print();
    delete livingChair;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++){
        collection[i].print();
    }
    delete[] collection;
    
    return 0;
}