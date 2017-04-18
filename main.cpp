
#include "PointCollection.h"
#include "Ship.h"
#include "Board.h"
#include <iostream>

using namespace std;
int main(){
    srand(time(0));
    
    Board b;
    b.display();
    
    int x, y;
    
    do{
        cout << "\nEnter a coordinates: ";
        cin >> x;
        cin.ignore();
        cin >> y;
        
        if (b.fireShot(x, y)) {
            cout << "Hit!!\n";
        }
        
        else  cout << "Miss...\n";
        b.display();
        
    }while (b.unsunkShipCount() != 0);
    
}





