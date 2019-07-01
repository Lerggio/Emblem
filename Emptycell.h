#ifndef EMPTY_H
#define EMPTY_H

#include "Cell.h"

class Empty : public Cell
{
    public:
        Empty(int i, int j, int k) : Cell(i, j, k)
        {
            x = i;
            y = j;
            z = k;
            myColor = wxT("WHITE");
            filename = wxT("nothing.png");
        }

    ~Empty()
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
};

#endif // EMPTY_H
