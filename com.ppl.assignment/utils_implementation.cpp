
#include "utils.h"
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <ctime>
#include <string>
 void Utils::run()
        {
            int n_g,n_b,k;
            Boy* boys[10000];
            Girl* girls[10000];
            Read* read = new Read();
            GiftBasket* gifts[10000];
            read->readData(boys, &n_b, &n_g, girls, gifts, &k);
            ofstream file;
            file.open("LOG.txt");
            time_t now;
            char *dt = (char*)malloc(sizeof(char)*100);
            for( int i = 0; i < n_g; i++)
            {
                this->allocateBoyfriends(boys,n_b,girls[i]);
                boys[girls[i]->getIndex()]->getCommitted(i);
                now = time(0);
                dt = ctime(&now);

                file << dt << " COMMITMENT " << " Girl: " << girls[i]->getName() << ", Boy: " << boys[girls[i]->getIndex()]->getName() <<endl <<endl;

            }
            file.close();
            cout << "Couples formed: " << endl << endl;



            this->makeGiftBasket(boys,n_g,gifts,girls);
            for(int i = 0; i < n_g; i++)
            {
               cout << "Girl: " << girls[i]->getName() << ", Boy: " << boys[girls[i]->getIndex()]->getName() <<endl;
               gifts[i]->printAll(girls[i]->getName(),boys[girls[i]->getIndex()]->getName());
               cout << endl;
            }
            this->setHappiness(girls, boys, n_g, gifts);
            this->setCompatibility(girls,boys,n_g);

            for(int i = 0; i < 50; i++)
                cout << "--";
            cout << endl << endl;

            cout << k << " happiest couples: " << endl << endl;
            this->printKHappiest(boys, girls, k, n_g);

            for(int i = 0; i < 50; i++)
                cout << "--";
            cout << endl << endl;

            cout << k << " most compatible couples: " << endl << endl;

            this->printKMostCompatible(boys,girls,k,n_g);

        }




         
		void Utils::allocateByAttractiveness(Boy** boys, int n,Girl* g)
		{
			int dude  = 0;

			for(int i = 0; i < n; i++)
			{
				if(g -> getMB() <= boys[i]-> getB()  && boys[i]->isCommitted == 0)
				{
					if( g->getAttr() >= boys[i]-> getMin())
					{
						if( boys[i]->getAttr() > boys[dude]->getAttr() )
							dude = i;
					}
				}
		}

		g->getCommitted(dude);
		boys[dude]->isCommitted = 1;
		}

         
		void Utils::allocateByBudget(Boy** boys, int n,Girl* g)
		{
			int dude  = 0;
				for(int i = 0; i < n; i++)
				{
					if(g -> getMB() <= boys[i]-> getB()  && boys[i]->isCommitted == 0)
					{
						if( g->getAttr() >= boys[i]-> getMin())
						{
							if( boys[i]->getB() > boys[dude]->getB() )
								dude = i;
						}
					}
				}

			g->getCommitted(dude);
			boys[dude]->isCommitted = 1;
		}


       
		void Utils::allocateByIntelligence(Boy** boys, int n,	Girl* g)
		{
			int dude  = 0;
			for(int i = 0; i < n; i++)
			{
				if(g -> getMB() <= boys[i]-> getB()  && boys[i]->isCommitted == 0)
				{
					if( g->getAttr() >= boys[i]-> getMin())
					{
						if( boys[i]->getIntelligence() > boys[dude]->getIntelligence() )
							dude = i;
					}
				}
			}

			g->getCommitted(dude);
			boys[dude]->isCommitted = 1;
		}

		
		void Utils::allocateBoyfriends(Boy** boys, int n, Girl* g)
		{

			if(g->getPreference() == ATTRACTIVE)
			{
				this->allocateByAttractiveness(boys,n,g);
			}
			else
			if(g->getPreference() == RICH)
			{
				this->allocateByBudget(boys, n, g);
			}
			else
				this->allocateByIntelligence(boys, n, g);


		}






		void Utils::setHappiness(Girl** girls, Boy** boys, int n_g, GiftBasket** gifts)
		{
		    for( int i = 0; i < n_g; i++)
            {
                this->setGHappiness(gifts[i],girls[i]);
                if(boys[girls[i]->getIndex()]->getType() == MISER)
                    boys[i]->setHappiness(gifts[i]->totalCost - boys[i]->getB());
                else
                 if(boys[girls[i]->getIndex()]->getType() == GENEROUS)
                    boys[i]->setHappiness(girls[i]->getHappiness());
                else
                 if(boys[girls[i]->getIndex()]->getType() == GEEK)
                    boys[i]->setHappiness(girls[i]->getIntelligence());
            }

		}



        void Utils::choosyUtil(GiftBasket* gift, Girl* g)
		{
		    g->setHappiness((int)(log10(gift->totalCost - g->getMB())/1));
		}


		void Utils::normalUtil(GiftBasket* gift, Girl* g)
		{
		    g->setHappiness((gift->totalCost - g->getMB() ) + gift->totalValue);
		}


		void Utils::desperateUtil(GiftBasket* gift, Girl* g)
		{
		    g->setHappiness((int)(exp(gift->totalCost - g->getMB())/1));
		}

        
		void Utils::setGHappiness(GiftBasket* gift, Girl* g)
		{
			if(g->getType() == DESPERATE)
                desperateUtil(gift, g);
			else
			if(g->getType() == NORMAL)
				normalUtil(gift, g);
			else
				choosyUtil(gift, g);
		}


        
        void Utils::printKHappiest(Boy** boys, Girl** girls, int k, int n_g)
		{
			ofstream file;
			file.open("LOG.txt",ios::app);
			file << k << " happiest couples: " << endl << endl;
		    int mark[100];
		    for( int i = 0; i < 100; i++)
                mark[i] = 0;
            int index, happiness;
            int Max;
            for( int i = 0; i < k; i++)
            {   Max = 0;
                index = -1;
                for( int j = 0; j < n_g; j++)
                {
                    if(mark[j] == 1)
                        continue;
                    happiness = girls[j]->getHappiness() + boys[girls[j]->getIndex()]->getHappiness();

                    if( happiness >=  Max )
                    {
                        Max = happiness;
                        index = j;
                    }

                }
            if(index == -1)
                continue;
            mark[index] = 1;
            cout << "Girl: " << girls[index]->getName() << ", Boy: " << boys[girls[index]->getIndex()]->getName() << "      Happiness: " << Max <<endl;
	    file << "Girl: " << girls[index]->getName() << ", Boy: " << boys[girls[index]->getIndex()]->getName() << "      Happiness: " << Max <<endl;
            }
		file << endl;
		file.close();
		}

        
        void Utils::miserGifts(int limit, GiftBasket* gift)
        {
            int tot = 0;
            int t,a,b,c,d;
            int i_e = 0;
            int i_u = 0;
            int i_l = 0;
            int tot_l = 0;
            ifstream infile("list.txt");

               string line;
                while (std::getline(infile, line) && tot < limit)
                {
                        istringstream iss(line);
                        int a, b;
                        if (!(iss >> t >> a >> b >> c >> d)) { break; } // error

                        /*cout << t << endl;
                        cout << a << endl;
                        cout << b << endl;
                        cout << c << endl;
                        cout << d << endl;*/



                if( t == E){
                    gift->e_gifts[i_e] =  new Essential(a,b);
                    i_e++;

                }
                else
                 if( t == U ){
                    gift->u_gifts[i_u] = new Utility(a,b,c,d);
                    i_u++;
                 }
                 else
                 {
                     gift->l_gifts[i_l] = new Luxury(a,b,c,d);
                     i_l++;
                     gift->luxuryValue += b;
                 }
                 gift->totalCost += a;
                 gift->totalValue += b;
                tot += a;

            }
        gift->i_e = i_e;
        gift->i_u = i_u;
        gift->i_l = i_l;
        infile.close();

        }

     
        void Utils::generousGifts(int limit, GiftBasket* gift)
        {
            int tot = 0;
            int t,a,b,c,d;
            int i_e = 0;
            int i_u = 0;
            int i_l = 0;
            int tot_l = 0;
           ifstream infile("list.txt");

               string line;
                while (std::getline(infile, line) && tot < limit)
                {
                        istringstream iss(line);
                        int a, b;
                        if (!(iss >> t >> a >> b >> c >> d)) { break; } // error

                        /*cout << t << endl;
                        cout << a << endl;
                        cout << b << endl;
                        cout << c << endl;
                        cout << d << endl;*/
                    if( tot + a > limit)
                    break;


                if( t == E){
                    (gift->e_gifts)[i_e] =  new Essential(a,b);
                    i_e++;
                }
                else
                 if( t == U ){
                    gift->u_gifts[i_u] = new Utility(a,b,c,d);
                    i_u++;
                 }
                 else
                 {
                     gift->l_gifts[i_l] = new Luxury(a,b,c,d);
                     i_l++;
                     gift->luxuryValue += b;
                 }
                 gift->totalCost += a;
                 gift->totalValue += b;
                    tot+=a;
            }
             gift->i_e = i_e;
            gift->i_u = i_u;
            gift->i_l = i_l;
            infile.close();

        }

        
        void Utils::geekGifts(int limit, GiftBasket* gift)
        {
            int tot = 0;
            int t,a,b,c,d;
            int i_e = 0;
            int i_u = 0;
            int i_l = 0;
            int tot_l = 0;
            ifstream infile("list.txt");


                string line;
                while (std::getline(infile, line) && tot < limit)
                {
                        istringstream iss(line);
                        int a, b;
                        if (!(iss >> t >> a >> b >> c >> d)) { break; } // error

                        /*cout << t << endl;
                        cout << a << endl;
                        cout << b << endl;
                        cout << c << endl;
                        cout << d << endl;*/



                if( t == E){

                    (gift->e_gifts)[i_e] =  new Essential(a,b);
                    i_e++;

                }
                else
                 if( t == U ){
                    gift->u_gifts[i_u] = new Utility(a,b,c,d);
                    i_u++;                 }
                 else
                 {
                     gift->l_gifts[i_l] = new Luxury(a,b,c,d);
                     i_l++;
                     gift->luxuryValue += b;
                 }
                 gift->totalCost += a;
                 gift->totalValue += b;
                 tot+=a;

            }
        gift->i_e = i_e;
        gift->i_u = i_u;
        gift->i_l = i_l;
        infile.close();
        }


        
        void Utils::makeGiftBasket(Boy** boys, int n_g, GiftBasket** gifts, Girl** girls)
        {
            for(int i = 0; i < 10000; i++)
            {
                gifts[i] = new GiftBasket();
            }

            for(int i = 0; i < n_g; i++)
            {

                if(boys[girls[i]->getIndex()]->getType() == MISER)
                    this->miserGifts(girls[i]->getMB(),gifts[i]);
                if(boys[girls[i]->getIndex()]->getType() == GENEROUS)
                    this->generousGifts(boys[girls[i]->getIndex()]->getB(),gifts[i]);
                if(boys[girls[i]->getIndex()]->getType() == GEEK )
                    this->geekGifts(girls[i]->getMB(),gifts[i]);
                if(gifts[i]->totalCost > boys[girls[i]->getIndex()]->getB())
                {
                    boys[girls[i]->getIndex()]->setB(gifts[i]->totalCost);
                }
            }

        }

        
        void Utils::setCompatibility(Girl** girls, Boy** boys, int n_g)
        {
            int c;
            for( int i = 0; i < n_g; i++ )
            {
                c = ( boys[girls[i]->getIndex()]->getB() - girls[i]->getMB() ) + abs( boys[girls[i]->getIndex()]->getIntelligence() - girls[i]->getIntelligence() ) + abs( boys[girls[i]->getIndex()]->getAttr() -girls[i]->getAttr() );
                girls[i]->setCompatibility(c);
            }
        }

        
            void Utils::printKMostCompatible(Boy** boys, Girl** girls, int k, int n_g)
            {
			ofstream file;
			file.open("LOG.txt",ios::app);
			file << k << " most compatible couples: " << endl << endl;
		    int mark[100];
		    for( int i = 0; i < 100; i++)
                mark[i] = 0;
            int index, compat;
            int Max;
            for( int i = 0; i < k; i++)
            {   Max = 0;
                index = -1;
                for( int j = 0; j < n_g; j++)
                {
                    if(mark[j] == 1)
                        continue;
                    compat = girls[j]->getCompatibility();
                    if( compat >=  Max )
                    {
                        Max = compat;
                        index = j;
                    }

                }
            if(index == -1)
                continue;
            mark[index] = 1;
            cout << "Girl: " << girls[index]->getName() << ", Boy: " << boys[girls[index]->getIndex()]->getName() << "      Compatibility: " << Max <<endl;
		file << "Girl: " << girls[index]->getName() << ", Boy: " << boys[girls[index]->getIndex()]->getName() << "      Compatibility: " << Max <<endl;
            }
		file << endl;
		file.close();
		}


