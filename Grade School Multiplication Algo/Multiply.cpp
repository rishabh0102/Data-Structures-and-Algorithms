//
//  Multiply.cpp
//  Multiply
//
//  Created by Rishabh on 19/05/17.
//  Copyright © 2017 Rishabh. All rights reserved.
//

#include <stdio.h>
#include "/Users/rishabh/stdc++.h"
using namespace std;

string Multiply(string num1, string num2){
    
    int n1 = num1.size();
    int n2 = num2.size();
    
    if (n1 == 0 || n2 == 0) {
        return "0";
    }
    
    vector<int> product(n1+n2,0);
    int i_n1 = 0;
    int i_n2 = 0;
    
    for (int i = n2-1; i>=0; i--) {
        int carry = 0;
        int d2 = num2[i] - '0';
        i_n1 = 0;
        
        for (int j = n1-1; j>=0; j--) {
            int d1 = num1[j]-'0';
            
            int sum = d1*d2 + product[i_n1 + i_n2] + carry;
            
            carry = sum/10;
            product[i_n1+i_n2] = sum % 10;
            
            i_n1++;
            
        }
        if (carry > 0)
            product[i_n1 + i_n2] += carry;
        i_n2++;

    }

    int i = product.size() - 1;
    while (i>=0 && product[i] == 0)
        i--;
    

    if (i == -1)
        return "0";
    
    string s = "";
    while (i >= 0)
        s +=to_string(product[i--]);
    
    return s;
}
//Driver Code
int main()
{
    string str1 = "111";
    string str2 = "111";
    cout << Multiply(str1, str2)<<endl;
    return 0;
}

    
    
    
    
    
    
