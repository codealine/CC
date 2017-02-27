/*! \class Read
    \brief reads data of girls and boys in appropriate data structures
*/
#include "giftBasket.h"
#include "boy.h"
#include "girl.h"
#include <fstream>
#include <sstream>
class Read
{
    public:
    /** Reads the data for boys which is given as an ordered set of data members:
            <Name, Attractiveness, Budget, Intelligence, Minimum attractiveness, Type, Index of girlfriend (-1 initially) >
            and calls the parameterized constructor to create objects */
        void readBoys(Boy** boys, int* n_b);


        /** Reads the data for girls which is given as an ordered set of data members:
            <Name, Attractiveness, Maintenance Budget, Intelligence, Preference, Type, Index of boyfriend (-1 initially) >
            and calls the parameterized constructor to create objects */
         void readGirls(Girl** girls, int* n_g);


        /** Caller function to invoke readBoys, readGirls as well as read the value of K */
	void readData(Boy** boys, int* n_b, int* n_g, Girl** girls, GiftBasket** gifts, int* k);
};
