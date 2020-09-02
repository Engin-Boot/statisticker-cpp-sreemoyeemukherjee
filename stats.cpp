#include "stats.h"
using namespace std;

Stats Statistics::ComputeStatistics(const std::vector<float>& vect) {
    //Implement statistics here
    Stats s;
    if (vect.empty())   // Error condition
    {
        s.average = NAN;
        s.min = NAN;
        s.max = NAN;
        return s;
    }
    float sum=0;
    s.min = vect[0];
    s.max = vect[0];
    for (int i = 0; i < vect.size(); i++)
    {
        sum = sum + vect[i];
        if (vect[i] < s.min)
            s.min = vect[i];
        if (vect[i] > s.max)
            s.max = vect[i];
    }
    s.average = sum/vect.size();
    return s;
}
