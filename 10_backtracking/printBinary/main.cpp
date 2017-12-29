#include <iostream>
#include <string>
using namespace std;

/**
 * prints every binary numbers that has exactly the given number of digits
 *
 * digits: number of digits left that need to be apended to the output
 * printBinary(3, "")
 *      printBinary(2,"0")
 *          printBinary(1,"00")
 *              printBinary(0,"000")
 *              printBinary(0,"001")
 *          printBinary(1,"01")
 *      printBinary(2,"1")
 */

//function prototype declarations, default value in the declaration
void printBinary(int digits, string prefix = "");
void printDecimalV1(int digits, string prefix = "");
void printDecimalV2(int digits, string prefix = "");

//it will use the default value in the declaration
void printBinary(int digits, string prefix){
    cout << "printBinary (" << digits<<","<<prefix<<")"<<endl;
    if(digits == 0){
        //base case
        cout<<prefix<<endl;
    } else{
        printBinary(digits - 1, prefix + "0");
        printBinary(digits - 1, prefix + "1");
    }

}

void printDecimalV1(int digits, string prefix){

    if(digits == 0){
        //base case
        cout<<prefix<<endl;
    } else{
        printDecimalV1(digits - 1, prefix + "0");
        printDecimalV1(digits - 1, prefix + "1");
        printDecimalV1(digits - 1, prefix + "2");
        printDecimalV1(digits - 1, prefix + "3");
        printDecimalV1(digits - 1, prefix + "4");
        printDecimalV1(digits - 1, prefix + "5");
        printDecimalV1(digits - 1, prefix + "6");
        printDecimalV1(digits - 1, prefix + "7");
        printDecimalV1(digits - 1, prefix + "8");
        printDecimalV1(digits - 1, prefix + "9");
    }

}

//use for loop
void printDecimalV2(int digits, string prefix){

    if(digits == 0){
        //base case
        cout<<prefix<<endl;
    } else{
        for (int i = 0; i<10; i++){
            printDecimalV2(digits - 1, prefix + to_string(i));
        }


    }

}

int main() {
    cout << "printBinary(3):" <<endl;
    printBinary(3);
    cout<<endl;

    //cout << "printDecimalV1(2):" <<endl;
    //printDecimalV1(2);
    //cout<<endl;

    cout << "printDecimalV2(2):" <<endl;
    printDecimalV2(2);
    cout<<endl;
    return 0;
}