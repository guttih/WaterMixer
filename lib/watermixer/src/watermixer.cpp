#include "watermixer.h"

WaterMixer::WaterMixer(Valve *hotValve, Valve *coldValve) {
    init(hotValve, coldValve);
}

void WaterMixer::init(Valve *hotValve, Valve *coldValve) {
    _hotValve = hotValve;
    _coldValve = coldValve;
}