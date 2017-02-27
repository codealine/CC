/*! \class Utility
    \brief Blueprint for objects of type Utility Gift
*/

class Utility
{
    private:
        int utilityValue;
        int utilityClass;
        int value;
        int price;
    public:
        Utility(int p, int v,int u,int c)
        {
            utilityValue = u;
            utilityClass = c;
            price = p;
            value = v;
        }
	//*Returns price of the gift*/
        int getPrice();
	//*Returns value of the gift*/
        int getValue();
	//*Returns Utility Value of the gift*/
        int getUtilityVale();
	//*Returns Utility class of the gift*/
        int getUtilityClass();
};
