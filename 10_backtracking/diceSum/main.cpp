#include <iostream>
#include <vector>
using namespace std;
/*
 * https://www.youtube.com/watch?v=jHLz-9RxlhE&index=16&list=PLnfg8b9vdpLn9exZweTJx44CII1bYczuk
 *
 * print all possible outcomes of a rolling
 * six-sided dice in {#, #, #} format
 *
 * chosen: pass by reference, the thing we need to remember from previous calls
 */

void diceSumHelper(int dice, int desiredSum, int sumSoFar, vector<int>& chosen);

void diceSumHelper(int dice, int desiredSum, int sumSoFar, vector<int>& chosen){
    //no dice left to roll
    if(dice == 0){
        if(sumSoFar == desiredSum){
            for (int i = 0; i<chosen.size(); i++){
                cout<< chosen[i];
            }
            cout<<endl;
        }
    }else{
        //some dice left to roll
        // hadle one die
        // for each value that die could have:
        for (int i = 1; i<=6; i++){
            //avoid bad path,
            // too big: sumSoFar + i + 1*(dice-1) <= desiredSum
            // too small: sumSoFar + i + 6*(dice-1) >= desiredSum
            if(sumSoFar + i + 1*(dice-1) <= desiredSum && sumSoFar + i + 6*(dice-1) >= desiredSum){
                //  choose
                chosen.push_back(i);
                //  explore
                diceSumHelper(dice - 1, desiredSum, sumSoFar+i, chosen);
                //  unchoose
                chosen.pop_back();
            }

        }
    }
}
void diceSum(int dice, int desiredSum){
    vector<int> chosen;
    diceSumHelper(dice, desiredSum, 0, chosen);
}

int main() {
    diceSum(2, 8);
    return 0;
}