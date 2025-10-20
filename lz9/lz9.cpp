#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    string pib;
    int groupNumber{};
    int missed{};
};

int main(){ 
    const int N = 10;
    Student a[N];

    cout << "Vvedit dani dlya 10 stydentiv.\n";
    for (int i = 0; i < N; ++i) {
        cout << "\nStudent #" << i + 1 << ":\n";
        cout << "PIB: ";
        getline(cin, a[i].pib);
        cout << "Nomer grypu: ";
        cin >> a[i].groupNumber;
        cout << "Kilkist propyskiv: ";
        cin >> a[i].missed;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    sort(a, a + N, [](const Student& x, const Student& y) {
        return x.groupNumber > y.groupNumber;
        });

    cout << "\nStydentu z kilkistu propyskiv bilshe 20:\n";
    bool any = false;
    for (int i = 0; i < N; ++i) {
        if (a[i].missed > 20) {
            cout << a[i].pib << " — група " << a[i].groupNumber << '\n';
            any = true;
        }
    }
    if (!any) cout << "Nema stydentiv z kilkistu propyskiv bilshe 20.\n";

    return 0;
}