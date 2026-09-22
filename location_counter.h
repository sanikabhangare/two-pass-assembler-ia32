#ifndef LOCATION_COUNTER_H
#define LOCATION_COUNTER_H

class LocationCounter
{
private:
    int address;

public:
    LocationCounter()
    {
        address = 0;
    }

    int getAddress()
    {
        return address;
    }

    void update(int size)
    {
        address = address + size;
    }
};

#endif
