#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int> greedy(vector<int> input, int C)
{
    int n = input.size();
    int res_sum = 0;
    vector<int> result;
    for (int i = n - 1; i >= 0; i--)
    {
        if (res_sum >= C)
        {
            break;
        }
        res_sum += input[i];
        result.push_back(input[i]);
    }
    if (result.size() == n && res_sum < C)
        result.clear(); // truong hop neu nhu tat ca phan tu deu ko lon hon C
    return result;
}

int char_in_string(char c, string P)
{
    for (int i = 0; i < P.size(); i++)
    {
        if (c == P[i])
        {
            return i;
        }
    }
    return -1;
}
vector<int> booyer_moore_horspool(string T, string P)
{
    int v = P.size(), i = P.size();
    int l = 0, r = 0;
    vector<int> result;
    while (i <= T.size())
    {
        int j = i - 1, x = v - 1;
        while (T[j] == P[x])
        {
            j--;
            x--;
        }
        if (x < 0)
        {
            result.push_back(j + 1);
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
    return result;
}

void khoitao(int &n, vector<int> &a, int &C, string &P, string &Q)
{
    n = 10;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x += 3 * 4;
        a.push_back(x);
    }
    C = 200;
    P = "mot";
    Q = "2 mot 3 mot 4 mot nam hai 3";
}
int main()
{
    int n, C;
    vector<int> a;
    string P, Q;
    khoitao(n, a, C, P, Q);
    // y tinh so D
    vector<int> result_greedy = greedy(a, C);
    if (result_greedy.size() == 0)
        cout << "Tong tat ca phan tu trong day khong lon hon C." << endl;
    else
    {
        cout << "So cac so co tong lon hon C la: " << result_greedy.size() << endl;
        cout << "Cac gia tri lay ra co tong lon hon C la:  ";
        int sum = 0;
        for (int i = 0; i < result_greedy.size(); i++)
        {
            sum += result_greedy[i];
            cout << result_greedy[i] << "   ";
        }
        cout << endl;
        cout << "Tong gia tri cac so da lay ra la: " << sum << endl;
    }
    vector<int> result_string = booyer_moore_horspool(Q, P);
    if (result_string.size() == 0)
        cout << "Xau P khong xuat hien trong Q" << endl;
    else
    {
        cout << "Vi tri cua xau P xuat hien trong Q lan luot la: " << endl;
        for (int i = 0; i < result_string.size(); i++)
        {
            cout << "Vi tri cua xau P xuat hien trong Q la " << result_string[i] << endl;
        }
    }
    return 0;
}