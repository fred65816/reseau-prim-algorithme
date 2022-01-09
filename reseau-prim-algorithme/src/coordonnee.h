#if !defined(_COORDONNEE__H_)
#define _COORDONNEE__H_
#include <iostream>

class Coordonnee {
  public:
    Coordonnee(){}
    Coordonnee(double latitude_, double longitude_);
    Coordonnee(const Coordonnee&);
    double distance(const Coordonnee&) const;
    Coordonnee& operator=(const Coordonnee& s);
  private:
    double latitude;
    double longitude;

  friend std::ostream& operator << (std::ostream&, const Coordonnee&);
  friend std::istream& operator >> (std::istream&, Coordonnee&);
};

#endif
