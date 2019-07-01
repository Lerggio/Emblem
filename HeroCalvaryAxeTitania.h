#ifndef HEROCALVARYAXETITANIA_H
#define HEROCALVARYAXETITANIA_H

#include "Cell.h"
#include "Emptycell.h"
#include "CalvaryImpass.h"
#include "FlyerPass.h"


class HeroCalvaryAxeTitania : public Cell
{
public:
    HeroCalvaryAxeTitania(int i, int j, int k) : Cell(i, j, k)
    {
        x = i;
        y = j;
        z = k;

        myColor = wxT("GREEN");
        healthPoints = 3;
        type = "Calvary";

        filename = wxT("Titania.png");

    }

    ~HeroCalvaryAxeTitania()
    {
        //dtor
    }

    wxString getName()
    {
        return filename;
    }

    wxString getType()
    {
        return type;
    }

    int getHP()
    {
        return healthPoints;
    }

    void hit(wxColor color, wxString type)
    {
        if(type == "Infantry")
        {
            if(color == "INDIAN RED")
            {
                healthPoints = healthPoints - 3;
            }
            if(color == "STEEL BLUE")
            {
                healthPoints = healthPoints - 1;
            }
            if(color == "DARK GREEN")
            {
                healthPoints = healthPoints - 2;
            }
        }
        if(type == "Flier")
        {
            if(color == "INDIAN RED")
            {
                healthPoints = healthPoints - 3;
            }
            if(color == "STEEL BLUE")
            {
                healthPoints = healthPoints - 1;
            }
            if(color == "DARK GREEN")
            {
                healthPoints = healthPoints - 2;
            }
        }
        if(type == "Armor")
        {
            if(color == "INDIAN RED")
            {
                healthPoints = healthPoints - 4;
            }
            if(color == "STEEL BLUE")
            {
                healthPoints = healthPoints;
            }
            if(color == "DARK GREEN")
            {
                healthPoints = healthPoints - 3;
            }
        }
        if(type == "Calvary")
        {
            if(color == "INDIAN RED")
            {
                healthPoints = healthPoints - 3;
            }
            if(color == "STEEL BLUE")
            {
                healthPoints = healthPoints - 1;
            }
            if(color == "DARK GREEN")
            {
                healthPoints = healthPoints - 3;
            }
        }
        if(type == "Assassin")
        {
            healthPoints = healthPoints - 4;
        }
    }



    void tick(Cell **** myArray, int rows, int cols, int lays)
    {
        Cell ** surroundings = this->getSuroundings(myArray, rows, cols, lays);
        int scount = this->getScount(myArray, rows, cols, lays);

        for(int ind = 0; ind < scount; ind++)
        {
            int zdim = surroundings[ind]->getZ();

            if(zdim == z &&
               (surroundings[ind]->getColor() == wxT("STEEL BLUE")||
               surroundings[ind]->getColor() == wxT("INDIAN RED")||
               surroundings[ind]->getColor() == wxT("DARK GREEN")||
                surroundings[ind]->getColor() == wxT("DARK GREY")))
            {
                hit(surroundings[ind]->getColor(), surroundings[ind]->getType());
                if(healthPoints <= 0)
                {
                    myArray[z][x][y] = new Empty(x, y, z);

                    return;
                }
            }
        }

        for(int ind = 0; ind < scount; ind++)
        {
            int rng = rand() % scount;

            int xdim = surroundings[rng]->getX();
            int ydim = surroundings[rng]->getY();
            int zdim = surroundings[rng]->getZ();

            if(zdim == z && surroundings[rng]->getColor() == wxT("WHITE"))
            {
                myArray[zdim][xdim][ydim] = myArray[z][x][y];
                myArray[z][x][y] = new Empty(x, y, z);
                z = zdim;
                x = xdim;
                y = ydim;

                return;
            }
        }
    }
protected:
private:
    int healthPoints;
    wxString filename;
    wxString type;
};

#endif // HEROCALVARYAXETITANIA_H
