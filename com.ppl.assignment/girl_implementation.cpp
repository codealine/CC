#include "girl.h"
#include <string>
		
		string Girl::getName()
		{

			return this->name;

		}


		int Girl::getAttr()
		{
			return this->attractiveness;
		}

   
		int Girl::getMB()
		{
			return this->maintenance_budget;
		}

		
		int Girl::getIntelligence()
		{
			return this->intelligence;
		}

		
		int Girl::getPreference()
		{
			return this->preference;
		}

		
		int Girl::getType()
		{
			return this->type;
		}

		
		void Girl::setName(string n)
		{
			this->name = n;
		}

        
		void Girl::setAttr(int a)
		{
			this->attractiveness = a;
		}

		void Girl::setMB(int b)
		{
			this->maintenance_budget = b;
		}

      
		void Girl::setIntelligence(int i)
		{
			this->intelligence = i;
		}

      
		void Girl::setPreference(int a)
		{
			this->preference = a;
		}

        
		void Girl::setType(int t)
		{
			this->type = t;
		}


		void Girl::getCommitted(int i)
        {
                        this->isCommitted = 1;
                        this->index = i;
        }

       
        void Girl::breakUp()
        {
                        this->isCommitted = 0;
                        this->index = -1;
        }

      
		void Girl::setHappiness(int h)
		{
			this->happiness = h;

		}

        
		int Girl::getHappiness()
		{
			return this->happiness;
		}

     
		int Girl::getIndex()
		{
		    return this->index;
		}

		int Girl::getCompatibility()
		{
			return this->compatibility;
		}
		
		void Girl::setCompatibility( int c)
		{
			this->compatibility = c;
		}

