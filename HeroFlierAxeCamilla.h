#ifndef HEROFLIERAXECAMILLA_H
#define HEROFLIERAXECAMILLA_H

#include "Cell.h"
#include "Emptycell.h"
#include "CalvaryImpass.h"
#include "FlyerPass.h"


class HeroFlierAxeCamilla : public Cell
{
    public:
        HeroFlierAxeCamilla(int i, int j, int k) : Cell(i, j, k)
        {
            x = i;
            y = j;
            z = k;

            counter = 0;
            myColor = wxT("GREEN");
            healthPoints = 4;
            type = wxT("Flier");

            filename = wxT("Camilla.png");

        }

    ~HeroFlierAxeCamilla()
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
        if(type == wxT("Armor"))
        {
            if(color == "INDIAN RED")
            {
                healthPoints = healthPoints - 4;
            }
            if(color == "STEEL BLUE")
            {
                healthPoints = healthPoints;
            }
            if(color == wxT("DARK GREEN"))
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
                    if(previous[0]->getColor() == "SKY BLUE") myArray[z][x][y] = new FlyerPass(x, y, z);


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
                surroundings[rng]->getColor() == wxT("SEA GREEN")||
               surroundings[rng]->getColor() == wxT("SKY BLUE")))
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
                if(previous[0]->getColor() == wxT("SKY BLUE"))
                {
                    previous[0] = surroundings[rng];
                    myArray[zdim][xdim][ydim] = myArray[z][x][y];
                    myArray[z][x][y] = new FlyerPass(x, y, z);
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

#endif // HEROFLIERAXECAMILLA_H
