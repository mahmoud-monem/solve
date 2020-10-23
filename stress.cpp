#include "bits/stdc++.h"

using namespace std;
#define rep2(i, s, e) for(int i=s;i<=(int)e;++i)
#define rep(i, n) for(int i=0;i<(int)n;++i)

class Random {
public:
    Random() = default;

    Random(std::mt19937::result_type seed) : eng(seed) {}

    int DrawNumber(int min, int max);

private:
    std::mt19937 eng{std::random_device{}()};
};

int Random::DrawNumber(int min, int max) {
    if (max < min)return 0;
    return std::uniform_int_distribution<int>{min, max}(eng);
}

int main() {
    system("g++ -lm -O3 -std=c++17 -pipe -o wa.exe D:\\Programming\\#C++\\ACMLion\\brute.cpp");
    //system("g++ -lm -O3 -std=c++17 -pipe -o ac.exe ./p.cpp");
    int tc = 1;
    Random rnd;

    while (1) {
        cerr << "Case " << tc << endl;
        ofstream cout("test.in");
        int n = rnd.DrawNumber(1, 10), m = rnd.DrawNumber(1, 20);

        cout << n << " " << m << endl;

        rep2(i, 1, m) {
            int x = rnd.DrawNumber(1, n);
            int y = rnd.DrawNumber(1, n);
            cout << x << " " << y << rnd.DrawNumber(0, 1);
            cout << endl;
        }
        cout.close();
        if (system("wa.exe <test.in >wa.txt"))break;
//        system("ac.exe <test.in >ac.txt");

        cerr << tc++ << endl;
  //      ifstream acs("ac.txt");
        ifstream was("wa.txt");

        string ac, wa;
        getline(was, wa, (char) EOF);

    //    getline(acs, ac, (char) EOF);
        was.close();

      //  acs.close();

//		cout << ac << endl;
//		cout << wa << endl;
        //if (ac !="YES\n")
        //if (ac != wa)
          //  break;
    }
}