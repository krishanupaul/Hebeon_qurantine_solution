#include<bits/stdc++.h> 
using namespace std; 
  
void insertInNonDecOrder(deque<char> &dq, char ch) 
{  
    if (dq.empty()) 
        dq.push_back(ch); 
  
    else
    { 
        char temp = dq.back();  
        while( temp > ch && !dq.empty()) 
        { 
            dq.pop_back(); 
            if (!dq.empty()) 
                temp = dq.back(); 
        } 
        dq.push_back(ch); 
    } 
    return; 
} 

string buildLowestNumber(string str, int n) 
{ 
    int len = str.length();  
    int k = len - n; 
    deque<char> dq; 
    string res = "";  
    int i; 
    for (i=0; i<=len-k; i++)  
        insertInNonDecOrder(dq, str[i]);  
    while (i < len) 
    {  
        res += dq.front();  
        dq.pop_front(); 
        insertInNonDecOrder(dq, str[i]); 
        i++; 
    }  
    res += dq.front(); 
    dq.pop_front(); 
    return res; 
} 
 
int main() 
{ 
    string str; 
    int n;
    cin >> noskipws;
    char c;
    while (cin >> c)
    {
        if(c == ' ')
             break;
        str.push_back(c);
    }
    cin>>n;
    cout << buildLowestNumber(str, n)<< endl; 
    return 0; 
} 