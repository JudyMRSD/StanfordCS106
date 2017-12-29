#include <iostream>
#include <vector>
using namespace std;
/*
 * print all possible outcomes of a rolling
 * six-sided dice in {#, #, #} format
 */

void diceHelper(int dice, vector<int>& chosen){
    //no dice left to roll
    cout<<"diceHelper"<<dice<<endl;
    if(dice == 0){
        for (int i = 0; i<chosen.size(); i++){
            cout<< chosen[i];
        }
        cout<<endl;
    }else{
        //some dice left to roll
        // hadle one die
        // for each value that die could have:
        for (int i = 1; i<=6; i++){
            //  choose
            chosen.push_back(i);
            //  explore
            diceHelper(dice - 1, chosen);
            //  unchoose
            chosen.pop_back();
        }
    }
}
void diceRolls(int dice){
    vector<int> chosen;
    diceHelper(dice, chosen);
}

int main() {
    diceRolls(2);
    return 0;
}