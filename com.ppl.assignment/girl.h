/*! \class Girl
    \brief To create objects of type Girl

    Holds all the attributes of each Girl including name, attractiveness, maintenance budget, intelligence, preference, type, boyfriend, happiness
    and compatibility of couple */
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

#define CHOOSY 0
#define NORMAL 1
#define DESPERATE 2

#define ATTRACTIVE 0
#define RICH 1
#define INTELLIGENT 2

class Girl
{
	private:
		string name;
		int attractiveness;
		int maintenance_budget;
		int intelligence;
		int preference;
		int type;
		int index;
		int happiness;
		int compatibility;

	public:
        /**Parameterized constructor for creating Girl objects*/
		Girl(string n, int a, int m, int i, int p, int t, int ind)
		{
			name = n;
			attractiveness = a;
			maintenance_budget = m;
			intelligence = i;
			preference = p;
			type = t;
			index = ind;
			isCommitted = 0;
		}

		int isCommitted;/*!< Commitment status of the girl. 1 = TRUE, 0 = FALSE*/
		/**Getter function for name of the girl*/
		
		string getName();
        /**Getter function for attractiveness of the girl*/
		int getAttr();

        /**Getter function for maintenance budget of the girl*/
		int getMB();

        /**Getter function for intelligence of the girl*/
		int getIntelligence();

        /**Getter function for preference of the girl*/
		int getPreference();

        /**Getter function for type of the girl*/
		int getType();

        /**Setter function for name of the girl*/
		void setName(string n);

        /**Setter function for attractiveness of the girl*/
		void setAttr(int att);

        /**Setter function for maintenance budget of the girl*/
		void setMB(int mb);

        /**Setter function for intelligence of the girl*/
		void setIntelligence(int i);

        /**Setter function for preference of the girl*/
		void setPreference(int p);

        /**Setter function for type of the girl*/
		void setType(int t);

        /**The girl is committed to the i'th boy*/
		void getCommitted(int i);

        /**The girls breaks up*/
		void breakUp();

        /** Shows index of the boy who is committed to the girl*/
		int getIndex();

        /**Setter function for happiness of the girl*/
		void setHappiness(int h);

        /**Getter function for happiness of the girl*/
		int getHappiness();

        /**Getter function for compatibility of the girl*/
		int getCompatibility();

        /**Setter function for compatibility of the girl*/
		void setCompatibility(int c);

};

