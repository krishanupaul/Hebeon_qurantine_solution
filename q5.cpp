#include <bits/stdc++.h> 
using namespace std; 

void getExprUtil(vector<string>& res, string curExp, 
                 string input, int target, int pos, 
                 int curVal, int last) 
{ 
    if (pos == input.length()) 
    { 
        if (curVal == target) 
            res.push_back(curExp); 
        return; 
    } 
  
    for (int i = pos; i < input.length(); i++) 
    { 
        if (i != pos && input[pos] == '0') 
            break; 
        string part = input.substr(pos, i + 1 - pos); 
        int cur = atoi(part.c_str()); 
  
        if (pos == 0) 
            getExprUtil(res, curExp + part, input, 
                     target, i + 1, cur, cur); 
        else
        { 
            getExprUtil(res, curExp + "+" + part, input, target, i + 1, curVal + cur, cur); 
            getExprUtil(res, curExp + "-" + part, input, target, i + 1, curVal - cur, -cur); 
            getExprUtil(res, curExp + "*" + part, input, target, i + 1, curVal - last + last * cur, last * cur); 
        } 
    } 
} 

vector<string> getExprs(string input, int target) 
{ 
    vector<string> res; 
    getExprUtil(res, "", input, target, 0, 0, 0); 
    return res; 
} 

void printResult(vector<string> res) 
{ 
    for (int i = 0; i < res.size(); i++) 
        cout <<"{"<< res[i] <<"}"; 
    cout << endl; 
} 
 
int main() 
{ 
    string input; 
    int target;
    getline(cin, input);
    cin>>target;
    vector<string> res = getExprs(input, target); 
    printResult(res); 
    return 0; 
} 