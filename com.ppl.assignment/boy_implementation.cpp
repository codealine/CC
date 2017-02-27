#include "boy.h"
#include <string>
		
		string Boy::getName()
		{

			return this->name;

		}


		int Boy::getAttr()
		{
			return this->attractiveness;
		}

   
		int Boy::getB()
		{
			return this->budget;
		}

		
		int Boy::getIntelligence()
		{
			return this->intelligence;
		}

		
		int Boy::getMin()
		{
			return this->minAttr;
		}

		
		int Boy::getType()
		{
			return this->type;
		}

		
		void Boy::setName(string n)
		{
			this->name = n;
		}

        
		void Boy::setAttr(int a)
		{
			this->attractiveness = a;
		}

		void Boy::setB(int b)
		{
			this->budget = b;
		}

      
		void Boy::setIntelligence(int i)
		{
			this->intelligence = i;
		}

      
		void Boy::setMinAttr(int a)
		{
			this->minAttr = a;
		}

        
		void Boy::setType(int t)
		{
			this->type = t;
		}


		void Boy::getCommitted(int i)
        {
                        this->isCommitted = 1;
                        Boy::index = i;
        }

       
        void Boy::breakUp()
        {
                        this->isCommitted = 0;
                        this->index = -1;
        }

      
		void Boy::setHappiness(int h)
		{
			this->happiness = h;

		}

        
		int Boy::getHappiness()
		{
			return this->happiness;
		}

     
		int Boy::getIndex()
		{
		    return this->index;
		}

