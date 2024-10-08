#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SIZE = 3;
const int MIN = 10000, MAX = 99999;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        legs = rand() % 2 + 3;
        for (int i = 0; i < SIZE; i++){
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
        }
    Chair(int l, double p[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++){
            prices[i] = p[i];
        }
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++){
            sum += prices[i];
        }
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }

    ~Chair(){
        delete[] prices;
    }
}
};

int main() {
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