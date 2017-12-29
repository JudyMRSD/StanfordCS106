#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void permute(string s);
void permuteHelper(string s, string chosen);
void permuteRepeat(string s);
void permuteRepeatHelper(string s, set<string>& printed, string chosen);


int main() {
    cout<<endl;
    cout<<"permute:"<<endl;
    permute("MARTY");
    permuteRepeat("google");
    return 0;
}

void indent(int n){
    for (int i = 0; i<n; i++){
        cout <<"       ";
    }

}


//----input string has no repeating characters-----------------------------------------------------
void permute(string s){
    permuteHelper(s, "");
}



void permuteHelper(string s, string chosen){
    indent(chosen.length());
    cout << "permuteHelper ("<<s<<","<<chosen<<"  )"<<endl;
    //Base case
    if (s.empty()){
        cout << chosen <<endl;
    } else{
        //choose / explore/ unchoose
        // 1 letter
        for (int i = 0; i<s.length(); i++){
            //choose
            char c = s[i];
            //add the character to chosen. and remove it from s
            chosen += c;
            //Erases the portion of the string value that begins at the character position pos
            //and spans len characters (or until the end of the string
            s.erase(i,1);
            //explore
            permuteHelper(s, chosen);
            //unchoose
            s.insert(i, 1, c);
            chosen.erase(chosen.length()-1, 1);
        }

    }
}

//--------input string has repeating characters--------

void permuteRepeat(string s){
    set<string> printed;
    permuteRepeatHelper(s, printed, "");
}
//google
//google will be printed twice, since the two "O" are considered different
void permuteRepeatHelper(string s, set<string>& printed, string chosen){
    indent(chosen.length());
    cout << "permuteHelper ("<<s<<","<<chosen<<"  )"<<endl;
    //Base case
    if (s.empty()){
        if (printed.find(chosen)!=printed.end()){
            cout << chosen <<endl;
            printed.insert(chosen);
        }

    } else{
        //choose / explore/ unchoose
        // 1 letter
        for (int i = 0; i<s.length(); i++){
            //choose
            char c = s[i];
            //add the character to chosen. and remove it from s
            chosen += c;
            //Erases the portion of the string value that begins at the character position pos
            //and spans len characters (or until the end of the string
            s.erase(i,1);
            //explore
            permuteRepeatHelper(s, printed, chosen);
            //unchoose
            s.insert(i, 1, c);
            chosen.erase(chosen.length()-1, 1);
        }

    }
}

