#include <iostream>
#include <string>
using namespace std;

int char_in_string(char c, string P)
{
    for (int i = 0; i < P.size(); i++)
    {
        if (c == P[i])
            return i;
    }

    return -1;
}

int boyer_moore_horspool(string T, string P)
{
    int i = P.size(), v = P.size();
    int cnt = 0;
    while (i <= T.size())
    {
        int x = v - 1, j = i - 1;
        while (T[j] == P[x] && x > -1)
        {
            x--;
            j--;
        }
        if (x < 0)
        {
            cnt++;
            i += v;
        }
        else
        {
            int k = char_in_string(T[j], P);
            if (k < 0)
            {
                i += v;
            }
            else
            {
                i += v - x;
            }
        }
    }
    return cnt;
}

int booyer_moore_horspool2(string T, string P) {
    int i = P.size(), v = P.size();
    int cnt = 0;
    while (i <= T.size()) {
        int j = i - 1, x = v - 1;
        while (T[j] == P[x]) {
            j--;
            x--;
        }
        if (x < 0) {
            cnt++;
            i+=v;
        }
        else {
            int k = char_in_string(T[j], P);
            if (k < 0) {
                i+=v;
            }
            else {
                i+= v-x;
            }
        }
    }
}
int main()
{
    string T = "ABCDEAMEFDHKEVDEFGHK",
           P = "DEFGHK";

    cout << "T = " << T << endl;
    cout << "P = " << P << endl;
    cout << "So lan P xuat hien trong T: " << boyer_moore_horspool(T, P) << endl;

    return 0;
}