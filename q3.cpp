#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define rep(i, a, b) for (int i = a; i <= b; i ++)
using namespace std;
typedef int_least16_t intl;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    std::string s;
    getline(cin, s);

    vector<char> stack(s.begin(), s.end());

    intl iterator = 0, ptr1, ptr2, lastIndex = stack.size();
    
    rep(i, 0, lastIndex-1)
        if(stack[i] == '(') iterator ++;
        
    while(iterator--){
        
        ptr1 = ptr2 = 0;
        
        while(stack[ptr2] != ')'){
            if(stack[ptr2] == '(') ptr1 = ptr2;
            ptr2++;
        }
        
        reverse(stack.begin() + ptr1 + 1, stack.begin() + ptr2 );
        stack.erase(stack.begin() + ptr1);
        stack.erase(stack.begin() + ptr2 - 1);
        
    } 
    
    for (const char &c : stack) 
            cout <<c;
        
    return 0;
}