#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;
string encrypt(string encrptawd)
{
    int len = encrptawd.length();
    char str[len];
    for(int i=0;i<len;i++)
    {
        str[i] = (encrptawd[i]+len);
    }
    string s = "";
    for (int i = 0; i < len; i++) {
        s = s + str[i];
    }
    return s;
}
string decrypt(string encrptawd)
{
    int len = encrptawd.length();
    char str[len];
    for(int i=0;i<len;i++)
    {
        str[i] = (encrptawd[i]-len);
    }
    string temp = "";
    for (int i = 0; i < len; i++) {
        temp = temp + str[i];
    }
    return temp;
}
int main(){
	string s,ss;
	cin>>s;
	cout<<encrypt(s);
	cin>>ss;
	cout<<decrypt(ss);
}
