#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool is_char(char c){
    if(c <= 'Z' and c >= 'A'){
        return true;
    }
    return false;
}

bool is_num(char c){
    if(c < 58 and c > 47){
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s; cin >> s;
    
    if(s.length() > 8){
        cout << "1\n"
        return 0;
    }
    
    for(int i = 0; i < 3; i++){
        if(!is_char(s[i])){
            cout << "0\n";
            return 0;
        }
    }

    if(s[3] == '-'){
        if(s.length() != 8){
            cout << "1\n";
            return 0;
        }
        for(int i = 4; i < 8; i++){
            if(!is_num(s[i])){
                cout << "0\n";
                return 0;
            }
        }
        cout << "1\n";
        return 0;
    }

    if(is_num(s[3])){
        if(!is_char(s[4]) or !is_num(s[5]) or !is_num(s[6]) or s.length() != 7 ){
            cout << "0\n";
            return 0;
        }
        cout << "2\n";
        return 0;
    }

    cout << "0\n";
    return 0;
}