#include <iostream>
#include <vector>
using namespace std;

vector<int> zfunction(string combined_string)
{
    int n = combined_string.size();
    vector<int> result(n, 0);
    int l = 0;
    int r = 0;
    for (int k = 1; k < n; k++)
    {
        if (k > r)
        {
            l = r = k;
            while (r < n && combined_string[r] == combined_string[r - l])
            {
                r++;
            }
            result[k] = r - l;
            r--;
        }
        else
        {
            int k1 = k - l;
            if (combined_string[k1] + k - 1 < r)
            {
                result[k] = result[k1];
            }
            else
            {
                l = k;
                while (r < n && combined_string[r] == combined_string[r - l])
                {
                    r++;
                }
                result[k] = r - l;
                r--;
            }
        }
    }

    return result;
}

vector<int> zfunction2(string input) {
    int n = input.size();
    vector<int> result(n, 0);
    int l = 0, r= 0;
    for (int k = 1; k < n; k++) {
        if (k > r) {
            l = r = k;
            while (r < n && input[r] == input[r-l]) r++;
            result[k] = r - l;
            r--;
        }
        else {
            int k1 = k - l;
            if (result[k1] + k - 1 < r) result[k] =result[k1];
            else {
                while (r < n && input[r] == input[r-l]) r++;
                result[k] = r- l;
                r--;
            }
        }
    }
    return result;
}

void search(string s, string subStr)
{
    int n = s.size();
    int m = subStr.size();

    string newStr = subStr + "$" + s;
    vector<int> zarray = zfunction(newStr);

    int count = 0;

    for (int i = 0; i <= zarray.size(); ++i)
    {
        if (zarray[i] == m)
        {
            cout << "\nXau con p xuat hien tai vi tri thu " << i - m << endl;
            count++;
        }
    }

    if (count == 0)
    {
        cout << "\nXau con p khong xuat hien trong chuoi s";
    }
}

int main()
{
    string s = "mot hai 3 bon mot 5 6 bay 8 mot",
           p = "mot";

    cout << "Xau s\t\t:" << s << endl;
    cout << "Xau con p\t:" << p << endl;
    search(s, p);

    return 0;
}