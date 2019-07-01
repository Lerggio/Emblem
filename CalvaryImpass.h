#ifndef CALVARYIMPASS_H
#define CALVARYIMPASS_H

#include "Cell.h"

class CalvaryImpass : public Cell
{
    public:
        CalvaryImpass(int i, int j, int k) : Cell(i, j, k)
        {
            x = i;
            y = j;
            z = k;
            myColor = wxT("SEA GREEN");
            filename = wxT("nothing.png");
        }

    ~CalvaryImpass()
    {
    //dtor
    }

    void tick(Cell **** myArray, int rows, int cols, int lays)
    {

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

#endif // CALVARYIMPASS_H
