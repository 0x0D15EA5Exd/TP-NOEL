//
//  main.cpp
//  TP-NOEL
//
//  Created by Victor on 13/12/2021.
//

#include <iostream>
#include <thread>
#include "Produit.hpp"
#include <vector>
#include <list>
#include <map>

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
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
    
    
    std::vector<Produit> vectorOfProduit; //Vector de Produit
    std::list<Produit> listOfProducts; //List de produit
    
    
    std::vector<Produit>::iterator itVector; //itérateur pour le vector
    std::list<Produit>::iterator itList; //itérateur pour la list
    
    std::map<Produit, int> mapOfProducts; //Tableau associatif de produit
    std::map<Produit, int>::iterator itMap; //Itérateur pour le Tableau associatif
    
    //mapOfProducts.insert(std::pair<Produit, int> (Produit("test,","test",3),1)); Exemple d'insertion 
    
    
    int *input = new int(0); // Variable permettat de naviguer dans les options
    
    do {
        itVector = vectorOfProduit.begin();
        itList = listOfProducts.begin();
        itMap = mapOfProducts.begin();

        menu(input); // Fonction qui affiche le menu, prend un pointeur en paramètre.
        
        if (*input == 1) // Option 1 : créer un objet Produit.
        {
            
            //Version automatique
            //String et entier généré automatiquement.
            std::string tmp1 = StringGenerator(), tmp2 = StringGenerator();
            int* tmp3 = new int(intGenerator());
            int* altTmp3 = new int(1);
            int* quantity = new int(0);

            std::string altTmp1 = "Test ", altTmp2 = "Test ";
            

            //Version avec des valeurs de l utilisateur.
            /*int tmp3 = intGenerator();
            /
            std::cout << "\nValeur Variete : ";
            std::cin >> tmp1;
            std::cout << "\nValeur Type : ";
            std::cin >> tmp2;
            std::cout << "\nValeur Calibre : ";
            std::cin >> *tmp3;
            */

            vectorOfProduit.push_back(Produit(tmp1, tmp2, *tmp3)); //Rajoute un vector après le dernier instancié.
            listOfProducts.push_back(Produit(tmp1, tmp2, *tmp3)); //Rajoute un membre a la fin de la liste chainé.
            
            std::cout << " Quantite de Produit a stocker : ";
            std::cin >> *quantity;
            mapOfProducts.insert(std::pair<Produit, int> (Produit(tmp1, tmp2, *tmp3),*quantity)); // Permet de tester les cas : présence d'un produit déjà existant dans le dico associatif

            itMap = mapOfProducts.find(Produit(altTmp1, altTmp2, *altTmp3)); // Recherche dans le conteneur un élément dont la clé est équivalente à k et renvoie un itérateur vers cet élément s'il est trouvé, sinon il renvoie un itérateur vers map::end.


            if (itMap != mapOfProducts.end()) // Si itérateur n'est pas égal à la valeur de fin alors :
            {
                *quantity += itMap->second;
                mapOfProducts.erase(itMap);

                mapOfProducts.insert(std::pair<Produit, int>(Produit(altTmp1, altTmp2, *altTmp3), *quantity));

                std::cout << "Il y a " << *quantity << " Produits du type " << altTmp2 << std::endl;
               
            }
            else
            {
                mapOfProducts.insert(std::pair<Produit, int>(Produit(altTmp1, altTmp1, *altTmp3), 1));
            }
           
            delete tmp3, altTmp3;

        }
        if (*input == 2 ) // Supprime un produit.
        {

            vectorOfProduit.erase(vectorOfProduit.end()-1); //Supprime le dernier vector.
            vectorOfProduit.shrink_to_fit();

            int * tmp = new int;

            std::cout << "Supprimer un produit : ";
            std::cin >> *tmp;

            std::advance(itList, *tmp-1); //Déplace l'itérateur sur l'objet de la liste chainé que l'on veut supprimer.
            listOfProducts.erase(itList);

        }
        if (*input == 3 ) // Affiche le contenu du vector et de la liste chainé
        {
            std::cout << "--------------Vector------------" << std::endl;
            for (itVector = vectorOfProduit.begin(); itVector != vectorOfProduit.end(); itVector++)
            {
                std::cout << ' ' << *itVector; // Affichage des produit contenu dans le vector
            }

            std::cout << "--------------List------------ " << std::endl;
            for (auto const &i: listOfProducts) {
                std::cout << ' ' << i; // Affichage des produits contenu dans la liste chainé
            }

            std::cout << "--------------Map------------" << std::endl;
            for (auto it = mapOfProducts.cbegin(); it != mapOfProducts.end(); ++it)
            {
                std::cout << it->first << std::endl << "Quantité de produit =" << it->second << std::endl;
            }
        }
        if (*input == 4) // Option 4 : trie les objets de la liste chainé
        {
            listOfProducts.sort(); // Tri de manière coirssante les produits dans la liste en fonction de Calibre.
            std::cout << "List is now sorted ! \n\n\n\n\n" << std::endl;
        }
    } while (*input != 5 ); // Option 5 : sortie du programme.
    delete input;
    
    
    return 0;
}



    
