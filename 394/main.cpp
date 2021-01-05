#include <iostream>
#include <map>
#include <stack>
using namespace std;

map<string, int> m;


string decodeString(string s) {
    stack<string> st;
    stack<int> in;
   string ans;
   int i = 0;
    int num = 0;
    string str;

   while (i < s.length()) {

       if (isdigit(s[i])) {
           num = num*10+s[i]-'0';
       }

       else if (isalpha(s[i])) {
           str += s[i];
       }
       else if (s[i] == '[') {
           in.push(num);
           num=0;
           st.push(str);
           str="";
       }
       else {
           int times=in.top();
           in.pop();
           while (times--)
               st.top() += str;
           str = st.top();
           st.pop();
       }
       i++;
   }
   return str;
}



int main() {
    stack<string>s;
    s.top() += "aaa";
    cout << s.top();
    std::cout << decodeString("3[a2[c]]") << std::endl;
    return 0;
}
