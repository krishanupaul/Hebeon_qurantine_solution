#include<algorithm>
#include<iostream>
#include<vector>
#define rep(i, a, b) for(int i = a; i <= b; i ++)
typedef int_fast32_t intf;

int main(){
    
    intf i, j, m, n, count = 0;
    std::cin>>m>>n;

    std::vector<std::vector<char>> matrix;
    rep(i, 0, m - 1){
        std::vector<char> row;
        rep(j, 0, n - 1){
            char value;
			std::cin >> value;
			row.push_back(value);
        }
        matrix.push_back(row);    
    }
    
    std::cout << "Vector contents are: \n";
	rep(i, 0, m - 1){
        rep(j, 0, n - 1){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	
    rep(i, 0, m - 1){
        rep(j, 0, n - 1){
            if(matrix[i][j] == '*') count++;
            if((i > 0 && j > 0) && (i <= m && j <= n) && (matrix[i][j] == '*') && (matrix[i-1][j-1] == '*') && (matrix[i-1][j] == '*') && (matrix[i][j-1] == '*')) count ++;
        }
    }

    std::cout<<"\n"<<count;
    return 0;
}