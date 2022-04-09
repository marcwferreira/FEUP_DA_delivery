#ifndef UTILS_H
#define UTILS_H

#include "Package.h"
#include "Truck.h"

bool byVolumeAsc(const Package &p1, const Package &p2);

bool byVolumeDesc(const Package &p1, const Package &p2);

bool byPriorityAsc(const Package &p1, const Package &p2);

bool byPriorityDesc(const Package &p1, const Package &p2);

bool byWeightAsc(const Package &p1, const Package &p2);

bool byWeightDesc(const Package &p1, const Package &p2);

bool byRewardAsc(const Package &p1, const Package &p2);

bool byRewardDesc(const Package &p1, const Package &p2);

bool byDurationAsc(const Package &p1, const Package &p2);

bool byDurationDesc(const Package &p1, const Package &p2);

bool byMaxVolumeAsc(const Truck &t1, const Truck &t2);

bool byMaxVolumeDesc(const Truck &t1, const Truck &t2);

bool byMaxWeightAsc(const Truck &t1, const Truck &t2);

bool byMaxWeightDesc(const Truck &t1, const Truck &t2);

bool byCostAsc(const Truck &t1, const Truck &t2);

bool byCostDesc(const Truck &t1, const Truck &t2);

#endif /* UTILS_H */