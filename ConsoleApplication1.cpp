#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Raspis
{
private:
    int den;
    double vrema;
    string name_uc_d;
    int auditoria;
public:
    Raspis(int d, double v, string n, int au) :den(d), vrema(v), name_uc_d(n), auditoria(au) {}

    void file()
    {
        ofstream files("a.txt");
        if (!files.is_open())
            cout << "Нет файла";
        files << den << endl;
        files << vrema << endl;
        files << name_uc_d << endl;
        files << auditoria << endl;
        files.close();
    }
    friend ostream& operator<<(ostream& so, Raspis& r) {
        so << r.den << r.vrema << r.name_uc_d << r.auditoria;
        return so;
    }

    friend istream& operator>>(istream& so, Raspis& r) {
        so >> r.den >> r.vrema >> r.name_uc_d >> r.auditoria;
        return so;
    }

};


int main()
{
    Raspis pa(12, 12.450, "Bym", 1);
    cout << pa;
    cin >> pa;

    return 0;
}
