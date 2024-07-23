#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    stack<char> st;
    cin>>s;
    for(char c:s){
        if(c=='(') st.push(c);
        else if(c == ')'){
            while (true)
            {
                if(st.empty()) break;
                if(st.top() == '(') {
                    st.pop();
                    break;
                }
                cout<<st.top();
                st.pop();
            }
        }
        else if(c == '+' || c=='-'){
            while(true){
                if(st.empty()) break;
                if (st.top() == '(') break;
                cout<<st.top();
                st.pop();
            }
            st.push(c);
        }
        else if(c=='/' || c=='*'){
            while(true){
                if(st.empty())break;
                if (st.top() == '(') break;
                if(st.top() == '+' || st.top() == '-') break;
                cout<<st.top();
                st.pop();
            }
            st.push(c);
        }
        
        else cout<<c;
        
    }
    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    
    return 0;
}