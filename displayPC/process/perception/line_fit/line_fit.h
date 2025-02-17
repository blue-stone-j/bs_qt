#ifndef LINEFIT_H
#define LINEFIT_H

#include "../perception_interface.h"

template <class PointT>
class LineFit : public PerceptionInterface<PointT>
{
public:
  LineFit();
  void runPerception(const pcl::PointCloud<PointT> cloudIn) override;
};
template <class PointT>
LineFit<PointT>::LineFit()
{
}

#endif // LINEFIT_H
