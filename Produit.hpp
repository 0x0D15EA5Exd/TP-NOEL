//
//  Produit.hpp
//  TP-NOEL
//
//  Created by Victor on 13/12/2021.
//

#ifndef Produit_hpp
#define Produit_hpp

#include <string>

class Produit
{
private:
    std::string variete;
    std::string type;
    int calbire;
    
public:
    Produit();
    Produit(std::string variete, std::string type, int calibre);
    Produit(Produit &p);
    int getCalibre();
    std::string getType();
    void setVariete(std::string variete);
    void setTypes(std::string type);
    void setCalibre(int calibre);
    
};




#endif /* Produit_hpp */
