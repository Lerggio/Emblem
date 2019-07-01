#ifndef ENEMYCALVARYSWORD_H
#define ENEMYCALVARYSWORD_H

#include "Cell.h"
#include "Emptycell.h"
#include "CalvaryImpass.h"
#include "FlyerPass.h"


class EnemyCalvarySword : public Cell
{
public:
    EnemyCalvarySword(int i, int j, int k) : Cell(i, j, k)
    {
        x = i;
        y = j;
        z = k;

        myColor = wxT("INDIAN RED");
        healthPoints = 3;
        type = "Calvary";

        filename = wxT("genericcalvarysword.png");

    }

    ~EnemyCalvarySword()
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
            if(color == "RED")
            {
                healthPoints = healthPoints - 2;
            }
            if(color == "BLUE")
            {
                healthPoints = healthPoints - 3;
            }
            if(color == "GREEN")
            {
                healthPoints = healthPoints - 1;
            }
        }
        if(type == "Flier")
        {
            if(color == "RED")
            {
                healthPoints = healthPoints - 2;
            }
            if(color == "BLUE")
            {
                healthPoints = healthPoints - 3;
            }
            if(color == "GREEN")
            {
                healthPoints = healthPoints - 1;
            }
        }
        if(type == "Armor")
        {
            if(color == "RED")
            {
                healthPoints = healthPoints - 3;
            }
            if(color == "BLUE")
            {
                healthPoints = healthPoints - 4;
            }
            if(color == "GREEN")
            {
                healthPoints = healthPoints;
            }
        }
        if(type == "Calvary")
        {
            if(color == "RED")
            {
                healthPoints = healthPoints - 3;
            }
            if(color == "BLUE")
            {
                healthPoints = healthPoints - 3;
            }
            if(color == "GREEN")
            {
                healthPoints = healthPoints - 1;
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
               (surroundings[ind]->getColor() == wxT("BLUE")||
               surroundings[ind]->getColor() == wxT("RED")||
               surroundings[ind]->getColor() == wxT("GREEN")||
                surroundings[ind]->getColor() == wxT("GREY")))
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

#endif // ENEMYCALVARYSWORD_H
