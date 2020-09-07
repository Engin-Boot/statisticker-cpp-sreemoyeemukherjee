#include "stats.h"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

vector<float> RemoveNAN(vector<float> vect)
{
   vect.erase(remove_if(vect.begin(),vect.end(),[](const auto& value) { return std::isnan(value); }),vect.end());
    return vect;
}
Stats Statistics::ComputeStatistics(const std::vector<float>& vect) {
    //Implement statistics here
    Stats s;
    s.average = NAN;
    s.min = NAN;
    s.max = NAN;
    vector<float> newvect = RemoveNAN(vect);
    if (newvect.empty())  // Error condition
    {
        return s;
    }
    float sum=0;
    s.min = *min_element(newvect.begin(),newvect.end());
    s.max = *max_element(newvect.begin(), newvect.end());
    for (int i = 0; (unsigned) i < newvect.size(); i++)
    {
            sum = sum + newvect[i];
    }
    s.average = sum/newvect.size();
    return s;
}