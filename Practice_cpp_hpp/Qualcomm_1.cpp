/**
 * @file Qualcomm_1.cpp
 * @date 2021-04-02
 * 1. Implement on CPP file
 * 2. pragma once
 * 3. Name of the Member Variables
 * 4. Use std::
 * 5. Use const
 * 6. Use virtual destructor
 */
// PointCloudCapturer.h
#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
struct Point{
  float x, y, z;
};

class PointCloudCapturer : public Capturer
{
  public:
    PointCloudCapturer();
    virtual ~PointCloudCapturer();
    Point get (int id) const;
    float getDistance (const Point a, const Point b) const;
    void sortDistance (const Point input);

  private:
    std::vector<Point> m_Points;
};



// PointCloudCapturer.cpp
#include <iostream>
#include "PointCloudCapturer.h"
// Constructor
PointCloudCapturer::PointCloudCapturer() {}

// Destructor
virtual PointCloudCapturer::~PointCloudCapturer() {}

// Copy Constructor
PointCloudCapturer::PointCloudCapturer(const PointCloudCapturer& other) {
    *this = other;
}

Point PointCloudCapturer::get (int id) const {
    assert(!Points.empty());
    assert(id < Points.size() - 1);
    return Points[id];
}
float PointCloudCapturer::getDistance(const Point a, const Point b) const {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));
}
void PointCloudCapturer::sortDistance(const Point input) {
    std::sort(Points.begin(), Points.end(), 
            [input] (auto& Point a, auto& Point b) {return distance(a, input) < distance(b,input)} );
}
