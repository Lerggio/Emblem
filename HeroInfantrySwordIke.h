#ifndef HEROINFANTRYSWORDIKE_H
#define HEROINFANTRYSWORDIKE_H

#include "Cell.h"
#include "Emptycell.h"
#include "CalvaryImpass.h"
#include "FlyerPass.h"


class HeroInfantrySwordIke : public Cell
{
    public:
        HeroInfantrySwordIke(int i, int j, int k) : Cell(i, j, k)
        {
            x = i;
            y = j;
            z = k;

            counter = 0;
            myColor = wxT("RED");
            healthPoints = 4;
            type = "Infantry";

            filename = wxT("Ike.png");

        }

    ~HeroInfantrySwordIke()
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
                healthPoints = healthPoints - 2;
            }
            if(color == "STEEL BLUE")
            {
                healthPoints = healthPoints - 3;
            }
            if(color == "DARK GREEN")
            {
                healthPoints = healthPoints - 1;
            }
        }
        if(type == "Flier")
        {
            if(color == "INDIAN RED")
            {
                healthPoints = healthPoints - 2;
            }
            if(color == "STEEL BLUE")
            {
                healthPoints = healthPoints - 3;
            }
            if(color == "DARK GREEN")
            {
                healthPoints = healthPoints - 1;
            }
        }
        if(type == "Armor")
        {
            if(color == "INDIAN RED")
            {
                healthPoints = healthPoints - 3;
            }
            if(color == "STEEL BLUE")
            {
                healthPoints = healthPoints - 4;
            }
            if(color == "DARK GREEN")
            {
                healthPoints = healthPoints;
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
                healthPoints = healthPoints - 3;
            }
            if(color == "DARK GREEN")
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
        //extern Cell **** myArray;
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
                    if(previous[0]->getColor() == "WHITE") myArray[z][x][y] = new Empty(x, y, z);
                    if(previous[0]->getColor() == "SEA GREEN") myArray[z][x][y] = new CalvaryImpass(x, y, z);

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

            if(counter == 0) previous[0] = surroundings[rng];

            if(zdim == z &&
               (surroundings[rng]->getColor() == wxT("WHITE")||
                surroundings[rng]->getColor() == wxT("SEA GREEN")))
            {
                if(previous[0]->getColor() == wxT("WHITE"))
                {
                    previous[0] = surroundings[rng];
                    myArray[zdim][xdim][ydim] = myArray[z][x][y];
                    myArray[z][x][y] = new Empty(x, y, z);
                    z = zdim;
                    x = xdim;
                    y = ydim;
                    counter++;
                    return;
                }
                if(previous[0]->getColor() == wxT("SEA GREEN"))
                {
                    previous[0] = surroundings[rng];
                    myArray[zdim][xdim][ydim] = myArray[z][x][y];
                    myArray[z][x][y] = new CalvaryImpass(x, y, z);
                    z = zdim;
                    x = xdim;
                    y = ydim;
                    counter++;
                    return;
                }
                else
                {
                    previous[0] = surroundings[rng];
                    myArray[zdim][xdim][ydim] = myArray[z][x][y];
                    myArray[z][x][y] = new Empty(x, y, z);
                    z = zdim;
                    x = xdim;
                    y = ydim;
                    counter++;
                    return;
                }
            }
        }
    }
    protected:
    private:
        Cell ** previous = new Cell * [0];
        int healthPoints;
        int counter;
        wxString type;
        wxString filename;
};

#endif // HEROINFANTRYSWORDIKE_H
