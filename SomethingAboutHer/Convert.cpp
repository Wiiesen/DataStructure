#include <iostream>
using namespace std;

int i = 0;
string str;

void Turn(unsigned int x);

void turn(int y);

int main() {

    unsigned int x = -10;
    cout << x << endl;
    Turn(x);
    for (int j = str.length() - 1; j >= 0; j--)
        cout << str[j];
    int y;
    y = (int) x;
    cout<<endl;
    cout<<y<<endl;
    turn(y);
    for(int j = str.length()-1;j>=0;j--)
        cout<<str[j];
}

void turn(int y) {
    if(y == 0) return ;
    else
    {
        int j = (y%16);
        if(j == 0)
            str+="0";
        if(j>0&&j<10)
            str+=(j+'0');
        if(j>=10)
        {
            str += ('A'+(j-10));
        }
        turn(y/16);
    }
}

void Turn(unsigned int x) {
    if(x == 0) return ;
    else
    {
        int j = (x%16);
        if(j == 0)
            str+="0";
        if(j>0&&j<10)
            str+=(j+'0');
        if(j>=10)
        {
            str += ('A'+(j-10));
        }
        Turn(x/16);
    }
}
