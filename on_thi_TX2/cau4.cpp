#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int n = 6;
class DT
{
public:
    string nhanHieu;
    int kichThuoc;
    int price;
    DT() {}
    DT(string nhanHieu, int kichThuoc, int price)
    {
        this->nhanHieu = nhanHieu;
        this->kichThuoc = kichThuoc;
        this->price = price;
    }
    void hienThi()
    {
        printf("%-33s%-33d%-33d", this->nhanHieu.c_str(), this->kichThuoc, this->price);
        cout << endl;
    }
};

void khoiTaoDS(vector<DT> &listDT)
{
    listDT.push_back(DT("Samsung", 10, 9));
    listDT.push_back(DT("Vivo", 4, 30));
    listDT.push_back(DT("Huawei", 5, 20));
    listDT.push_back(DT("Oppo", 1, 7));
    listDT.push_back(DT("Iphone XS max", 20, 50));
    listDT.push_back(DT("Iphone 6 plus", 4, 8));
}
void hienThiTieuDe()
{
    printf("%-33s%-33s%-33s", "Hang dien thoai", "Kich thuoc", "Gia tien");
    cout << endl;
}

vector<vector<int>> dynamic(vector<DT> listDT, int S)
{
    // dp[i][j] la khi xet den do vat thu i, co tong kich thuoc la j
    // hien thi cho gia tri cua do vat da lay
    vector<vector<int>> dp(n + 1, vector<int>(S + 1));
    for (int i = 0; i < S; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= S; j++)
        {
            // gia su truong hop khong lay
            dp[i][j] = dp[i - 1][j];
            // truong hop co the lay
            if (j >= listDT[i].kichThuoc)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - listDT[i].kichThuoc] + listDT[i].price);
            }
        }
    }
    return dp;
}
vector<DT> truyVetKetQua(vector<vector<int>> dp, vector<DT> listDT, int s)
{
    vector<DT> result;
    int i = n, j = s;
    while (i != 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            result.push_back(listDT[i]);
            j = j - listDT[i].kichThuoc;
        }
        i--;
    }
    return result;
}
int main()
{
    vector<DT> listDT;
    khoiTaoDS(listDT);
    // y 1
    hienThiTieuDe();
    for (int i = 0; i < n; i++)
    {
        listDT[i].hienThi();
    }

    // y 2
    int s;
    cout << "Nhap vao kich thuoc cai tui: " << endl;
    cin >> s;

    vector<vector<int>> dp(n + 1, vector<int>(s + 1));
    dp = dynamic(listDT, s);
    vector<DT> result = truyVetKetQua(dp, listDT, s);
    cout << "So dien thoai co the lay duoc la: " << result.size() << endl;
    cout << "Danh sach cac dien thoai da lay la: " << endl;
    hienThiTieuDe();
    for (int i = 0; i < result.size(); i++)
    {
        result[i].hienThi();
    }

    return 0;
}