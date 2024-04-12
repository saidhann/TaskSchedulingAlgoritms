#ifndef ZADANIA_H
#define ZADANIA_H
#include <istream>

class Zadania {
private:
    int r;
    int p;
    int q;
    int nu;
  
public:
  Zadania(int _r, int _p, int _q, int _nu);
  Zadania();

    int getR() const { return r; }
    int getP() const { return p; }
    int getQ() const { return q; }
    int getNu() const { return nu; }
    void setR(int tmp) { r = tmp; }
    void setP(int tmp) { p = tmp; }
    void setQ(int tmp) { q = tmp; }
    void setNu(int tmp) { nu = tmp; }
    bool operator<(const Zadania& other) const {
        return this->nu < other.nu;
    }

};
#endif

