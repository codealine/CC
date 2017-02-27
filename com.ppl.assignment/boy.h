/*! \class Boy
    \brief To create objects of type Boy

    Holds all the attributes of each Boy including name, attractiveness, budget, intelligence, minimum attractiveness, type, girlfriend,
    and happiness
*/

#include <algorithm>
#include <iostream>

using namespace std;

#define MISER 0
#define GENEROUS 1
#define GEEK 2


class Boy
{
	private:
		string name ;
		int attractiveness;
		int budget;
		int intelligence;
		int minAttr;
		int type;
		int index;
		int happiness;
	public:
	        int isCommitted; /*!<Commitment status*/
		Boy(string n, int a, int b, int i, int m, int t, int ind)
		{
			name = n;
			attractiveness = a;
			budget = b;
			intelligence = i;
			minAttr = m;
			type = t;
			index = ind;
			isCommitted = 0;
		}


        /** Getter for attribute name */
		string getName();

        /** Getter for attribute attractiveness */
		int getAttr();
		

        /** Getter for attribute budget */
		int getB();
		
		/** Getter for attribute intelligence */
		int getIntelligence();
		

		/** Getter for attribute minimum attractiveness */
		int getMin();
		

		/** Getter for attribute type */
		int getType();
		

		/** Setter for attribute name*/
		void setName(string n);
		

        /** Setter for attribute attractiveness*/
		void setAttr(int a);
		

		/** Setter for attribute budget*/
		void setB(int b);
		

        /** Setter for attribute intelligence*/
		void setIntelligence(int i);
		

        /** Setter for attribute minimum attractiveness*/
		void setMinAttr(int a);
		

        /** Setter for attribute type*/
		void setType(int t);
		

        /** Gets the boy committed to girl of index i */
		void getCommitted(int i);
       

        /** Makes the boy single */
        void breakUp();

        /** Sets attribute happiness */
		void setHappiness(int h);
		
        /** Gets attribute happiness */
		int getHappiness();
		

        /** Gets index of girlfriend */
		int getIndex();
		



};

