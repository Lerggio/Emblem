CPP=g++

CPPFLAGS=-Wall -g `wx-config --cxxflags`

LD=g++

LDFLAGS=-Wall -g `wx-config --libs`

OBJS=FinalProjectMain.o FinalProjectApp.o

PROG=FinalProject

all: $(PROG)

clean:
	$(RM) -f $(PROG) $(OBJS)

$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(PROG)

%.o: %.c
	$(CPP) $(CPPFLAGS) -c $<
