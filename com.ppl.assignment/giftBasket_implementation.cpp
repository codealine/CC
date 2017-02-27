#include <algorithm>
#include "giftBasket.h"
#include <fstream>
#include <ctime>
#include <string>
#include <iostream>
void GiftBasket::printAll(string g, string b)
    {
        ofstream file;
        file.open("LOG.txt",ios::app);
        time_t now;
        char *dt = (char*)malloc(sizeof(char)*100);
        now = time(0);
        dt = ctime(&now);
        file << dt ;
        file << " GIFT : " << b << " to " << g <<endl<<endl;
        cout << "Essential: " << endl;
        file << " Essential: " << endl;
        for(int i = 0; i < i_e; i++)
        {
          cout << "Cost: " << e_gifts[i]->getPrice()<< ", Value: " << e_gifts[i]->getValue()<< endl;
          file << " Cost: " << e_gifts[i]->getPrice()<< ", Value: " << e_gifts[i]->getValue()<< endl;
        }

        cout << "Utility: " << endl;
        file << " Utility: " << endl;
        for(int i = 0; i < i_u; i++)
        {
          cout << "Cost: " << u_gifts[i]->getPrice() << ", Value: " << u_gifts[i]->getValue()<< ", Utility Class: " << u_gifts[i]->getUtilityClass() << ", Utility Value: " << u_gifts[i]->getUtilityVale() << endl;
          file << " Cost: " << u_gifts[i]->getPrice() << ", Value: " << u_gifts[i]->getValue()<< ", Utility Class: " << u_gifts[i]->getUtilityClass() << ", Utility Value: " << u_gifts[i]->getUtilityVale() << endl;

        }

        cout << "Luxury: " << endl;
        file << " Luxury: " << endl;
        for(int i = 0; i < i_l; i++)
        {
          cout << "Cost: " << l_gifts[i]->getPrice() << ", Value: " << l_gifts[i]->getValue() << ", Difficulty: " << l_gifts[i]->getDiff() << ", Luxury Rating: " << l_gifts[i]->getRating() << endl;
          file << " Cost: " << l_gifts[i]->getPrice() << ", Value: " << l_gifts[i]->getValue() << ", Difficulty: " << l_gifts[i]->getDiff() << ", Luxury Rating: " << l_gifts[i]->getRating() << endl;

        }
        file << endl << endl;
        file.close();
        cout << endl;
    }


