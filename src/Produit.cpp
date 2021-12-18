//
//  Produit.cpp
//  TP-NOEL
//
//  Created by Victor on 13/12/2021.
//

#include "Produit.hpp"
#include <string.h>
#include <random>
#include <string>

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

std::ostream& operator <<(std::ostream& os, const Produit& p)
{
    std::cout << "\nCalibre :  " << p.Calibre << "\nType : " << p.Type << "\nVariete : " << p.Variete << std::endl;
    return os;
}



void menu(int * input)
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n----------TP DE NOEL ---------";
    std::cout << std::endl << "Option Ajouter un produit, taper 1 " <<  std::endl;
    std::cout << "Option retirer un produit (le dernier), taper 2" << std::endl;
    std::cout << "Option Afficher le contenu, taper 3 " << std::endl;
    std::cout << "Option pour trier la list, taper 4" << std::endl;
    std::cout << "Pour quitter, taper 5" << std::endl;
    
    std::cout << "Choix : ";
    std::cin >> *input;
    return ;
}

bool compart(Produit First, Produit Second)
{
    return First < Second ? true : false;
}


std::string StringGenerator()
{
    std::string tmpStr("0123456789ABCDEFGHIJKLMNOPQRTUVWXYZabcdefghijklmnopqrtuvwxyz") ;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(tmpStr.begin(), tmpStr.end(), generator);
    return tmpStr.substr(0,32);
}

int intGenerator()
{
    int tmpInt;
    
    static std::default_random_engine rd;
    static std::mt19937 generatorXint(rd());
    std::uniform_int_distribution<int>dist(1,100);
    tmpInt = dist(rd);
    return tmpInt;
}
