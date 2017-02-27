/*! \class Utils
    \brief Class containing the utility functions

    This is the essence of the software as it performs most
    of the work required.

    1) Allocates couples
    2) Performs gifting (reads gifts)
    3) Generates K happiest and most compatible couples
    */

#include "read.h"
#include <string>

#define E 1
#define U 2
#define L 3



class Utils
{		public:


        /** Key caller function. Upon execution, calls the proper functions to build the necessary data structures,
           load the data for boys and girls, allocate boyfriends, perform gifting, set happiness and compatibility,
           print the K happiest and most compatible couples, and prints all the couples. */
        void run();




         /**Function to allocate boyfriends by Intelligence.
            Function performs primary check for maintenance budget being less than budget
            of the boy and also whether the boy is single or not.
            Upon these criterion being met, the check for attractiveness of the girl being not-less-than
            the criteria for minimum attractiveness of the boy is performed.
            From all the boys meeting the above conditions, the one with the highest attractiveness is chosen. */
		void allocateByAttractiveness(Boy** boys, int n,Girl* g);
		
         /**Function to allocate boyfriends by Intelligence.
            Function performs primary check for maintenance budget being less than budget
            of the boy and also whether the boy is single or not.
            Upon these criterion being met, the check for attractiveness of the girl being not-less-than
            the criteria for minimum attractiveness of the boy is performed.
            From all the boys meeting the above conditions, the one with the highest budget is chosen. */
		void allocateByBudget(Boy** boys, int n,Girl* g);
		


        /**Function to allocate boyfriends by Intelligence.
            Function performs primary check for maintenance budget being less than budget
            of the boy and also whether the boy is single or not.
            Upon these criterion being met, the check for attractiveness of the girl being not-less-than
            the criteria for minimum attractiveness of the boy is performed.
            From all the boys meeting the above conditions, the one with the highest intelligence is chosen. */
		void allocateByIntelligence(Boy** boys, int n,	Girl* g);

		/**Function to check the preference type of the girls one-by-one and call the necessary function to
            allocate boyfriends based on preference */
		void allocateBoyfriends(Boy** boys, int n, Girl* g);


		/**Method to set the happiness of the girls and boys.
            Invokes the setGHappiness() method to set the happiness of girls and sets
            happiness of boys based on criteria based on their type.

            Logic for calculation of happiness can be found in further documentation of the software.
            */
		void setHappiness(Girl** girls, Boy** boys, int n_g, GiftBasket** gifts);

		/**Sets happiness of CHOOSY girls*/
		void choosyUtil(GiftBasket* gift, Girl* g);

		/**Sets happiness of NORMAL girls*/
		void normalUtil(GiftBasket* gift, Girl* g);

		/**Sets happiness of DESPERATE girls*/
		void desperateUtil(GiftBasket* gift, Girl* g);

        /**Sets happiness of girls based on their type by calling the required function. */
	void setGHappiness(GiftBasket* gift, Girl* g);

        /**Method to print the K happiest couples in the list.
            K is a randomly generated argument present int a text file "k.txt"

            Method uses a flag array to check the couples already printed.
            A check for the highest value of happiness amongst the unmarked couples in the array
            is performed and the highest value is printed, followed by marking of the index of this value
            to avoid duplicated entries in the output table. */

        void printKHappiest(Boy** boys, Girl** girls, int k, int n_g);


        /** Reads values of gifts out of file "list.txt" which contains an exhaustive list of all the items available for
            purchase at an online store. Stocks of each gift are deemed unlimited compared to the scale of the problem.
            Makes a gift basket of gifts, starting from the cheapest, just over and above the maintenance budget of the
            girlfriend and updates parameters of statistics about the total price and value of the gifts in the basket */
        void miserGifts(int limit, GiftBasket* gift);

        /** Reads values of gifts out of file "list.txt" which contains an exhaustive list of all the items available for
            purchase at an online store. Stocks of each gift are deemed unlimited compared to the scale of the problem.
            Makes a gift basket of gifts, starting from the cheapest, just under the budget of the
            girlfriend and updates parameters of statistics about the total price and value of the gifts in the basket */
        void generousGifts(int limit, GiftBasket* gift);

        /** Reads values of gifts out of file "list.txt" which contains an exhaustive list of all the items available for
            purchase at an online store. Stocks of each gift are deemed unlimited compared to the scale of the problem.
            Makes a gift basket of gifts, starting from the cheapest, just over and above the maintenance budget of the
            girlfriend, including one luxury gift, and updates parameters of statistics about the total price and value of the gifts in the basket */
        void geekGifts(int limit, GiftBasket* gift);


        /** Traverses list of all couples and called the necessary gifting logic function based on the type of the boyfriend */
        void makeGiftBasket(Boy** boys, int n_g, GiftBasket** gifts, Girl** girls);

        /**Sets compatibility of each couple which is stored as a data member in the Girl object.
            Logic for compatibility can be found in further documentation, */
        void setCompatibility(Girl** girls, Boy** boys, int n_g);

        /**Method to print the K most compatible couples in the list.
            K is a randomly generated argument present int a text file "k.txt"

            Method uses a flag array to check the couples already printed.
            A check for the highest value of compatibility amongst the unmarked couples in the array
            is performed and the highest value is printed, followed by marking of the index of this value
            to avoid duplicated entries in the output table. */
            void printKMostCompatible(Boy** boys, Girl** girls, int k, int n_g);
};

