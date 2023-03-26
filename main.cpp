#include <iostream>
#include "zlomek.h"

int main() {
    Zlomek z1;
    Zlomek z2(3, 2);
    Zlomek z3(2, 6);
    Zlomek z4(0, 2);
    std::cout << "Objekt z1 vytvoreny konstruktorem bez parametru: " << z1 << ", " << z1.vydelZlomek() << std::endl;
    std::cout << "Objekt z2 vytvoreny konstruktorem s parametry: " << z2 << ", " << z2.vydelZlomek() << std::endl;
    std::cout << "Objekt z3 vytvoreny konstruktorem s parametry: " << z3 << ", " << z3.vydelZlomek() << std::endl;
    std::cout << "Objekt z4 vytvoreny konstruktorem s parametry: " << z4 << ", " << z4.vydelZlomek() << std::endl;

    z2.prevratZlomek();
    z4.prevratZlomek();
    std::cout << "\nObjekt z2 po prevraceni: " << z2 << std::endl;
    std::cout << "Objekt z4 po prevraceni: " << z4 << std::endl;

    int cit, jme;
    std::cout << "\nZmena zlomku z1" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "Zadej citatele: ";
    std::cin >> cit;
    std::cout << "Zadej jmenovatele: ";
    std::cin >> jme;
    z1.zmenaZlomku(cit, jme);
    std::cout << "Objekt z1 po zmene: " << z1 << std::endl;

    std::cout << "\nScitani a prirazovani zlomku" << std::endl;
    std::cout << "----------------------------" << std::endl;
    z3 = z1 + z2;
    std::cout << "z3 = z1 + z2 = " << z1 << " + " << z2 << " = " << z3 << std::endl;
}
