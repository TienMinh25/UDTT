#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 6;

class Quat
{
public:
    string tenHSX;
    string color;
    int price;

    Quat()
    {
    }
    Quat(string tenHSX, string color, int price)
    {
        this->tenHSX = tenHSX;
        this->color = color;
        this->price = price;
    }
    void hienThi()
    {
        printf("%-40s%-20s%-30d", this->tenHSX.c_str(), this->color.c_str(), this->price);
        cout << endl;
    }
};
void khoiTao(vector<Quat> &quat)
{
    quat.push_back(Quat("Samsung", "Red", 100000));
    quat.push_back(Quat("Honda", "Red", 170000));
    quat.push_back(Quat("Hong Hai", "Yellow", 150000));
    quat.push_back(Quat("Hong Hai", "Green", 200000));
    quat.push_back(Quat("Thong Nhat", "Blue", 300000));
    quat.push_back(Quat("Toyota", "Red", 50000));
}

void hienThiTieuDe()
{
    printf("%-40s%-20s%-30s", "Ten hang san xuat", "Mau", "Gia tien");
    cout << endl;
}
bool cmp(Quat a, Quat b)
{
    return a.price < b.price;
}
vector<Quat> greedy(vector<Quat> quat, int p)
{
    sort(quat.begin(), quat.end(), cmp);
    int i = 0;
    vector<Quat> result;
    while (p >= 0 && i < n)
    {
        if (p - quat[i].price > 0)
        {
            result.push_back(quat[i]);
            p = p - quat[i].price;
        }
        else
            break;
        i++;
    }
    return result;
}

int main()
{
    int p; // so tien p
    vector<Quat> quat;
    khoiTao(quat);
    hienThiTieuDe();
    for (int i = 0; i < n; i++)
    {
        quat[i].hienThi();
    }
    cout << "Moi nhap so tien p: " << endl;
    cin >> p;
    vector<Quat> result = greedy(quat, p);
    if (result.size() == 0)
        cout << "Khong du tien mua quat nao.";
    else
    {
        cout << "Tong so quat nhieu nhat co the mua duoc la: " << result.size() << endl;
        cout << "Cac quat mua duoc bao gom: " << endl;
        hienThiTieuDe();
        for (int i = 0; i < result.size(); i++)
        {
            result[i].hienThi();
        }
    }

    return 0;
}