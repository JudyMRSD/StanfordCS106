#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permute(string s);
void permuteHelper(string s, string chosen);
void combin(string s, int len);

int main() {
    cout<<endl;
    cout<<"permute:"<<endl;
    permute("MARTY");
    return 0;
}

void permute(string s){
    permuteHelper(s, "");
}

void permuteHelper(string s, string chosen){
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
