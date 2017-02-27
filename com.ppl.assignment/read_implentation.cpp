#include "read.h"
void Read::readBoys(Boy** boys, int* n_b)
        {
           FILE* f = freopen("boys.txt","r",stdin);
           cin >> *n_b;
           for(int i = 0; i < *n_b; i++)
            {
                char n[100];
                int a,b,in,m,t,ind;
                cin >> n;
                cin >> a;
                cin >> b;
                cin >> in;
                cin >> m;
                cin >> t;
                cin >> ind;
                boys[i] = new Boy(n,a,b,in,m,t,ind);
            }

           fclose(f);
        }
void Read::readGirls(Girl** girls, int* n_g)
        {       char n[100];
                int a,m,in,p,t,ind;
            FILE* f = freopen("girls.txt","r",stdin);
            cin >> *n_g;
            for(int i = 0; i < *n_g; i++)
            {

                cin >> n;
                cin >> a;
                cin >> m;
                cin >> in;
                cin >> p;
                cin >> t;
                cin >> ind;

                girls[i] = new Girl(n,a,m,in,p,t,ind);
            }
            fclose(f);
        }
void Read::readData(Boy** boys, int* n_b, int* n_g, Girl** girls, GiftBasket** gifts, int* k)
		{
		    readBoys(boys, n_b);
            readGirls(girls, n_g);
            FILE* f = freopen("k.txt","r",stdin);
            cin >> *k ;
            fclose(f) ;

		}

