//
//  Produit.hpp
//  TP-NOEL
//
//  Created by Victor on 13/12/2021.
//

#ifndef Produit_hpp
#define Produit_hpp

#include <string>
#include <iostream>

class Produit
{
private:
    std::string Variete;
    std::string Type;
    int Calibre;
    
public:
    Produit();
    ~Produit();
    Produit(std::string variete, std::string type, int calibre);
    Produit(const Produit &p);
    int getCalibre();
    std::string getType();
    std::string getVariete();
    void setVariete(std::string variete);
    void setTypes(std::string type);
    void setCalibre(int calibre);
    Produit operator = (const Produit &p);
    bool operator <(const Produit  &p) const;
    bool operator == (const Produit &p);
    friend std::ostream& operator <<(std::ostream& os, const Produit& p);
};

void menu(int *input);
bool compart(Produit First, Produit Second);
std::string StringGenerator();
int intGenerator();
#endif /* Produit_hpp */
