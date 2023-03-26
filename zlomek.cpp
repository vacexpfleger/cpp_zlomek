//
// Created by pfleg on 25.03.2023.
//

#include "zlomek.h"

Zlomek::Zlomek() {
    this->citatel = 1;
    this->jmenovatel = 1;
}

Zlomek::Zlomek(int citatel, int jmenovatel) {
    if(kontrolaVstup(jmenovatel)){
        this->citatel = citatel;
        this->jmenovatel = jmenovatel;
    }
}

bool Zlomek::kontrolaVstup(int jmenovatel) {
    if(jmenovatel < 1){
        return false;
    }

    return true;
}

int Zlomek::getCitatel() const {
    return this->citatel;
}

int Zlomek::getJmenovatel() const {
    return this->jmenovatel;
}

float Zlomek::vydelZlomek() {
    return (float)this->citatel / (float)this->jmenovatel;
}

void Zlomek::prevratZlomek() {
    int cit = this->citatel;
    int jme = this->jmenovatel;
    if(kontrolaVstup(cit)){
        this->citatel = jme;
        this->jmenovatel = cit;
    }
}

int Zlomek::nejvetsiSpolecnyDelitel(int cit, int jme) {
    int gcd, i;

    for(i=1; i <= cit && i <= jme; ++i)
    {
        if(cit%i==0 && jme%i==0)
            gcd = i;
    }

    return gcd;
}

void Zlomek::vykratZlomek() {
    int cit = this->citatel;
    int jme = this->jmenovatel;
    int gcd = nejvetsiSpolecnyDelitel(cit, jme);

    this->citatel = cit/gcd;
    this->jmenovatel = jme/gcd;
}

Zlomek Zlomek::operator+(const Zlomek & z) {
    Zlomek zlomek;
    int spolecnyJmenovatel = (this->jmenovatel * z.jmenovatel) / nejvetsiSpolecnyDelitel(this->jmenovatel, z.jmenovatel);
    zlomek.citatel = (this->citatel * (spolecnyJmenovatel/this->jmenovatel)) + (z.citatel * (spolecnyJmenovatel/z.jmenovatel));
    zlomek.jmenovatel = spolecnyJmenovatel;
    return zlomek;
}

void Zlomek::operator=(const Zlomek & z) {
    this->citatel = z.citatel;
    this->jmenovatel = z.jmenovatel;
}

void Zlomek::zmenaZlomku(int cit, int jme) {
    if(kontrolaVstup(jme)){
        this->citatel=cit;
        this->jmenovatel=jme;
    }
}

std::ostream& operator << (std::ostream & os, const Zlomek & z) {
    os << z.getCitatel() << "/" << z.getJmenovatel();
    return os;
}