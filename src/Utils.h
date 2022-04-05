#ifndef UTILS_H
#define UTILS_H

#include "Package.h"
#include "Truck.h"

bool byVolume(const Package &p1, const Package &p2);

bool byWeight(const Package &p1, const Package &p2);

bool byReward(const Package &p1, const Package &p2);

bool byDuration(const Package &p1, const Package &p2);

bool byMaxVolume(const Truck &t1, const Truck &t2);

bool byMaxWeight(const Truck &t1, const Truck &t2);

bool byCost(const Truck &t1, const Truck &t2);

#endif /* UTILS_H */