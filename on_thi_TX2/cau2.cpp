#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n = 6;
class Quat
{
public:
    string tenHSX;
    string color;
    int price;
    Quat() {}
    Quat(string tenHSX, string color, int price)
    {
        this->tenHSX = tenHSX;
        this->color = color;
        this->price = price;
    }
    void hienThi()
    {
        printf("%-40s%-20s%-40d", this->tenHSX.c_str(), this->color.c_str(), this->price);
        cout << endl;
    }
};

void hienThiTieuDe()
{
    printf("%-40s%-20s%-40s", "Ten hang san xuat", "Mau sac", "Gia tien");
    cout << endl;
}
void khoiTaoDS(vector<Quat> &quat)
{
    quat.push_back(Quat("Samsung", "Red", 100000));
    quat.push_back(Quat("Honda", "Red", 170000));
    quat.push_back(Quat("Hong Hai", "Yellow", 150000));
    quat.push_back(Quat("Hong Hai", "Green", 200000));
    quat.push_back(Quat("Thong Nhat", "Blue", 300000));
    quat.push_back(Quat("Toyota", "Red", 50000));
}
bool cmp(Quat a, Quat b)
{
    return a.price > b.price;
}
vector<Quat> greedy(vector<Quat> quat, int p)
{
    vector<Quat> result;
    sort(quat.begin(), quat.end(), cmp);
    int i = 0;
    while (p >= 0 && i < n)
    {
        if (p - quat[i].price > 0)
        {
            result.push_back(quat[i]);
            p -= quat[i].price;
        }
        else
            break;
    }
    return result;
}

int main()
{
    int p;
    vector<Quat> quat;
    khoiTaoDS(quat);

    hienThiTieuDe();
    for (int i = 0; i < n; i++)
    {
        quat[i].hienThi();
    }

    cout << "Moi nhap so tien p: " << endl;
    cin >> p;
    vector<Quat> result = greedy(quat, p);
    if (!result.size())
        cout << "So tien khong du de mua bat ki cai quat nao.";
    else
    {
        cout << "Tong so quat co the mua: " << result.size() << endl;
        cout << "Danh sach quat duoc mua bao gom: " << endl;
        hienThiTieuDe();
        for (int i = 0; i < result.size(); i++)
        {
            result[i].hienThi();
        }
    }

    return 0;
}