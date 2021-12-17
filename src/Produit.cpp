//
//  Produit.cpp
//  TP-NOEL
//
//  Created by Victor on 13/12/2021.
//

#include "Produit.hpp"

Produit::Produit()
{
    this->Variete = "Not_Initialized";
    this->Type = "Not_Initialized";
    this->Calibre = 2;
    std::cout << "Ctor Produit called" << std::endl;
}

std::string Produit::getType()
{
    return this->Type;
    
}

std::string Produit::getVariete()
{
    return this->Variete;
}

int Produit::getCalibre()
{
    return this->Calibre;
}

Produit::Produit(std::string variete, std::string type, int calibre) {
    this->Variete = variete ;
    this->Type = type ;
    this->Calibre = calibre ;
    std::cout << "Ctor Produit Called" << std::endl ;
}

Produit::Produit(const Produit &p) { 
    this->Type = p.Type ;
    this->Variete = p.Variete ;
    this->Calibre = p.Calibre;
    std::cout << "Copy Ctor Produit Called" << std::endl;
}

void Produit::setVariete(std::string variete) { 
    this->Variete = variete;
}

void Produit::setTypes(std::string type) { 
    this->Type = type ;
}

void Produit::setCalibre(int calibre) { 
    this->Calibre = calibre ;
}

Produit::~Produit() {
    std::cout << "Dtor Produit Called" << std::endl;
}

Produit Produit::operator=(const Produit &p) {
    this->Calibre = p.Calibre;  
    this->Type = p.Type;
    this->Variete = p.Variete;
    return *this;
}

bool Produit::operator<(const Produit &p) const { 
    return (p.Calibre < this->Calibre);
}

bool Produit::operator==(const Produit &p) { 
    return (p.Calibre == this->Calibre);
}








