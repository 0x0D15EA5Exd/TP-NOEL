//
//  main.cpp
//  TP-NOEL
//
//  Created by Victor on 13/12/2021.
//

#include <iostream>
#include "Produit.hpp"
#include <vector>
#include <list>

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    /// Implémentation de la classe produit
    ///
    ///
    ///
    /*
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
    
    for (int i = 0; i < 5 ; ++i) {
        int CalibreC;
        std::string str1;
        std::string str2;
        
        std::cout << "\nValeur Variete : ";
        std::cin >> str1;
        std::cout << "\nValeur Type : ";
        std::cin >> str2;
        std::cout << "\nValeur Calibre : ";
        std::cin >>  CalibreC;
        V.push_back(Produit(str1, str2, CalibreC)) ;
    }
    for(int i = 0; i < V.size() ; i++)
    {
        std::cout << V[i];
    }
    */
    
    
    
    std::vector<Produit> vectorOfProduit;
    std::list<Produit> listOfProducts;
    std::vector<Produit>::iterator it;
    std::list<Produit>::iterator itList;
    /* VECTOR */
    int input(0);
    do {
        it = vectorOfProduit.begin();
        itList = listOfProducts.begin();
        menu(&input);
        
        if (input == 1)
        {
            std::string tmp1, tmp2;
            int tmp3;
            std::cout << "\nValeur Variete : ";
            std::cin >> tmp1;
            std::cout << "\nValeur Type : ";
            std::cin >> tmp2;
            std::cout << "\nValeur Calibre : ";
            std::cin >>  tmp3;
            
            vectorOfProduit.push_back(Produit(tmp1, tmp2, tmp3));
            listOfProducts.push_back(Produit(tmp1, tmp2, tmp3));
        }
        if (input == 2 )
        {
            vectorOfProduit.erase(vectorOfProduit.end());
            vectorOfProduit.shrink_to_fit();
            
            std::cout << " Supprimer un produit : ";
            int tmp;
            std::cin >> tmp;
            std::advance(itList, tmp);
            listOfProducts.erase(itList);
        }
        if (input == 3 )
        {
            for (it = vectorOfProduit.begin(); it != vectorOfProduit.end(); it++)
            {
                std::cout << ' ' << *it;
            }
            for (auto const &i: listOfProducts) {
                std::cout << ' ' << i;
            }
        }
        if (input == 4) {
            listOfProducts.sort();
        }
        if (input ==5) {
            break;
        }
    } while (input != 5 );
    
    
    
    
    
    
    
    
    
    
    


    return 1;
}
