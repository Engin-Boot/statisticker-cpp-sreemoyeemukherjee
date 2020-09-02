#include "stats.h"
#include <iostream>
#include <algorithm>
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
    s.min = *min_element(vect.begin(),vect.end());
    s.max = *max_element(vect.begin(), vect.end());
    for (int i = 0; i < vect.size(); i++)
    {
        sum = sum + vect[i];
    }
    s.average = sum/vect.size();
    return s;
}
