#include "struktura.h"
bool palyginimas(const duomuo &a, const duomuo &b)
{
    if (a.Vard != b.Vard )
        return a.Vard < b.Vard;
    return a.Pav < b.Pav;
};
