//
//  main.cpp
//  TP-NOEL
//
//  Created by Victor on 13/12/2021.
//

#include <iostream>
#include "Produit.hpp"
#include <vector>


int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    /// Implémentation de la classe produit
    ///
    ///
    ///
    
    Produit P1("Test", "test 2", 3);
    Produit P2 = P1;
    Produit P3 = P2;
    Produit arrayProduit[10];
    
    
    P2.setTypes("Lego");
    P2.setVariete("Variete");
    P2.setCalibre(1000000);
    
    for (int i = 0; i < 10; i++) {
        arrayProduit[i] = P2;
    }
    
    
    
    for (int i = 0; i< 10; i++) {
        std::cout << "Valeur dans arrayProduit[" << i << "]" << "=" << arrayProduit[i].getType() << " " << arrayProduit[i].getCalibre() << " " <<  arrayProduit[i].getVariete() << std::endl;
    }
    
    std::vector<Produit> V;
    
    for (auto i = V.begin(); i != V.end(); ++i) {
        
    }
    
    return 0;
}
