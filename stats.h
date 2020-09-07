#include <vector>
struct Stats
{
    float average, min, max;
};
namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>& );
}
