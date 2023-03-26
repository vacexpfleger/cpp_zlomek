//
// Created by pfleg on 25.03.2023.
//

#ifndef UNTITLED_ZLOMEK_H
#define UNTITLED_ZLOMEK_H
#include <iostream>

class Zlomek {
public:
    Zlomek();
    Zlomek(int, int);
    Zlomek(Zlomek &);
    // virtual ~Zlomek();
    bool kontrolaVstup(int);
    int getCitatel() const;
    int getJmenovatel() const;
    float vydelZlomek();
    void prevratZlomek();
    int nejvetsiSpolecnyDelitel(int, int);
    void vykratZlomek();
    void zmenaZlomku(int, int);
    Zlomek operator+ (const Zlomek&);
    void operator= (const Zlomek&);
private:
    int citatel;
    int jmenovatel;
};

std::ostream& operator << (std::ostream &, const Zlomek &);

#endif //UNTITLED_ZLOMEK_H
