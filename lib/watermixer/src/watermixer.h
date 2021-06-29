#ifndef WATERMIXER_H
#define WATERMIXER_H

#include "valve.h"

class WaterMixer
{
    private:
        Valve *_hotValve = NULL;
        Valve *_coldValve = NULL;
        void init(Valve *hotValve, Valve *coldValve);
    public:
        WaterMixer(Valve *hotValve, Valve *coldValve);
        Valve *getHotValve() {return _hotValve; }
        Valve *getColdValve() {return _coldValve; }

};
#endif