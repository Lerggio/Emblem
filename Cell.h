#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


class Cell
{
    public:
        int x, y, z;
        wxColor myColor;
        wxString type;
        int healthPoints = 0;
        Cell(int i, int j, int k)
        {
            x = i;
            y = j;
            z = k;
            myColor = wxT("CYAN");
        }
        virtual ~Cell()
        {
            //dtor
        }

	wxColor virtual getColor()
	{
	    return myColor;
	}

	wxString virtual getType()
	{
        return type;
	}

	int virtual getHP()
	{
	    return healthPoints;
	}

	int virtual getX()
	{
	    return x;
	}

	int virtual getY()
	{
	    return y;
	}

	int virtual getZ()
	{
	    return z;
	}

	void setPosition(int i, int j, int k)
	{
	    x = i;
        y = j;
        z = k;
	}

	void setColor(wxColor color)
	{
	    myColor = color;
	}

	Cell ** getSuroundings(Cell **** myArray, int rows, int cols, int lays)
	{
	    Cell ** surroundings;
        surroundings = new Cell * [26];
        int scount = 0;
        for(int a = z - 1; a <= z + 1; a++)
        {
            for(int b = x - 1; b <= x + 1; b++)
            {
                for(int c = y - 1; c <= y + 1; c++)
                {
                    if(!(a < 0 || b < 0 || c < 0 || a >= lays || b >= rows || c >= cols))
                    {
                        if(!(myArray[a][b][c] == myArray[z][x][y]))
                        {
                            surroundings[scount] = myArray[a][b][c];
                            scount++;
                        }
                    }
                }
            }
        }

        return surroundings;
	}

    int getScount(Cell **** myArray, int rows, int cols, int lays)
    {
        Cell ** surroundings;
        surroundings = new Cell * [26];
        int scount = 0;
        for(int a = z - 1; a <= z + 1; a++)
        {
            for(int b = x - 1; b <= x + 1; b++)
            {
                for(int c = y - 1; c <= y + 1; c++)
                {
                    if(!(a < 0 || b < 0 || c < 0 || a >= lays || b >= rows || c >= cols))
                    {
                        if(!(myArray[a][b][c] == myArray[z][x][y]))
                        {
                            surroundings[scount] = myArray[a][b][c];
                            scount++;
                        }
                    }
                }
            }
        }
        return scount;
    }

	virtual void tick(Cell **** myArray, int rows, int cols, int lays)
	{

	}

	virtual wxString getName()
	{
        return "Cell";
	}
    protected:
    private:
};

#endif // CELL_H
