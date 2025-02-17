#ifndef TRUCK_PARAM_H
#define TRUCK_PARAM_H

#include "string"
#include "vector"

struct TruckParam
{
  std::string name;
  std::vector<int> ip;
  std::vector<double> lf, lb;
};

#endif // TRUCK_PARAM_H
