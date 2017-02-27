/*! \class Luxury
    \brief Blueprint for objects of type Luxury Gift
*/
class Luxury
{
    private:
        int luxuryRating;
        int difficulty;
        int price;
        int value;
    public:
        Luxury(int p, int v, int l, int d)
        {
            luxuryRating = l;
            difficulty = d;
            price = p;
            value = v;
        }
	/**Return price of the gift*/	
        int getPrice();
	/**Return value of the gift*/	
        int getValue();
	/**Return difficulty in getting of the gift*/
        int getDiff();
	/**Return luxury rating of the gift*/
        int getRating();
};
