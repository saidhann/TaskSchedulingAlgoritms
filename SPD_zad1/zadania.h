#ifndef ZADANIA_H
#define ZADANIA_H

class Zadania {
private:
    int r;
    int p;
    int q;
    int nu;
  
public:
  Zadania(int _r, int _p, int _q, int _nu); 

    int getR() const { return r; }
    int getP() const { return p; }
    int getQ() const { return q; }
    int getNu() const { return nu; }
    bool operator<(const Zadania& other) const {
        return this->nu < other.nu;
    }

};

#endif

