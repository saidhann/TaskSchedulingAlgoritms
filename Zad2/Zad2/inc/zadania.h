#ifndef ZADANIA_H
#define ZADANIA_H

class Zadania {
private:
    int p;
    int nu;
  
public:
  Zadania(int _p, int _nu); 

    int getP() const { return p; }
    int getNu() const { return nu; }
    bool operator<(const Zadania& other) const {
        return this->nu < other.nu;
    }

};

#endif

