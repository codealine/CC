/*! \class Essential
    \brief Blueprint for objects of type Essential Gift
*/

class Essential
{
    private:
        int price;
        int value;
    public:
	/**Parameterized constructor. p = price of gift, v = 
	    value of gift*/        
	Essential(int p, int v)
        {
            price = p;
            value = v;
        }
	/**Return price of the gift*/
	int getPrice();
	/**Returns value of the gift*/
        int getValue();
};
