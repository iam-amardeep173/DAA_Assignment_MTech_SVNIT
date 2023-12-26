#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <bits/stdc++.h>
#include <random>
#include<chrono>

     
const int MAX_SIZE = 26;
     
using namespace std;

string removeDuplicateLetters(string s) {
    stack<char> st;
    unordered_map<char, int> last_occurrence;
    unordered_map<char, bool> in_stack;

    for (int i = 0; i < s.length(); ++i) {
        last_occurrence[s[i]] = i;
    }

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];

        // Skip characters that are already in the stack.
        if (in_stack[c]) continue;

        // Remove characters from the stack if a smaller character is available later.
        while (!st.empty() && c < st.top() && i < last_occurrence[st.top()]) {
            in_stack[st.top()] = false;
            st.pop();
        }

        // Push the current character onto the stack.
        st.push(c);
        in_stack[c] = true;
    }

    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

string printstring(int n)
{
    char letters[MAX_SIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string ran = "";
    for (int i=0;i<n;i++) 
        ran=ran + letters[rand() % MAX_SIZE];
    return ran;
}

int main(){
    srand(time(NULL));
    int num;
    cout<<"enter the value of num:\n"; cin>>num;
    string s = printstring(num);
    cout <<  s << endl;
    auto start = chrono::high_resolution_clock::now();	
    string result = removeDuplicateLetters(s);
    auto stop = chrono::high_resolution_clock::now();
    cout << "It took " << chrono::duration_cast<chrono::nanoseconds>(stop - start).count() << " nanoseconds" << endl;
    cout << "Smallest lexicographical order without duplicates: " << result << endl;
    return 0;
}