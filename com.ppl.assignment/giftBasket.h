/*! \class GiftBasket
    \brief Objects for each gift basket exchanged between couples

    Contains information about total cost of gifts, total value of gifts, value of luxury items.
    Contains arrays holding objects of each type of gift present in the gift basket, namely Essential,
    Utility, and Luxury.

    Also contains method to print information of all the gift exchanges and log them to a file */

#include "luxury.h"
#include "utility.h"
#include "essential.h"
#include <fstream>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

class GiftBasket
{
    public:
    Luxury* l_gifts[100]; /*!< Array holding  all objects of gifts of Luxury type, as exchanged between a couple */
    Essential* e_gifts[100]; /*!< Array holding  all objects of gifts of Essential type, as exchanged between a couple */
    Utility* u_gifts[100]; /*!< Array holding  all objects of gifts of Utility type, as exchanged between a couple */

    int totalCost; /*!< Total cost of all the gifts in the basket */
    int totalValue;/*!< Total value of all the gifts in the basket */
    int luxuryValue;/*!< Total value of all the Luxury gifts in the basket */

    int i_u; /*!< Total number of Utility gifts*/
    int i_e; /*!< Total number of Essential gifts*/
    int i_l; /*!< Total number of Luxury gifts*/

    GiftBasket()
    {
        totalCost = 0;
        totalValue = 0;
        luxuryValue = 0;
    }
    
    /**Logs all the gift exchange details of couples and prints them to the terminal as well */
    void printAll(string g, string b);

};
