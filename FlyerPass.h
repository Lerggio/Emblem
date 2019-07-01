#ifndef FLYERPASS_H
#define FLYERPASS_H

#include "Cell.h"

class FlyerPass : public Cell
{
    public:
        FlyerPass(int i, int j, int k) : Cell(i, j, k)
        {
            x = i;
            y = j;
            z = k;
            myColor = wxT("SKY BLUE");
            filename = wxT("nothing.png");
        }

~FlyerPass()
{
    //dtor
}

void tick(Cell **** myArray, int rows, int cols, int lays)
{
    //extern Cell **** myArray;
    /*Cell ** surroundings;
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

    for(int ind = 0; ind < scount; ind++)
    {

    }*/
}

wxString getName()
    {
        return filename;
    }

    protected:
    private:
        wxString filename;
	//int counter;
};

#endif // FLYERPASS_H
