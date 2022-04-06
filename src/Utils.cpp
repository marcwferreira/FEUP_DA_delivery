#include "Utils.h"

bool byVolumeAsc(const Package &p1, const Package &p2) {
    return p1.getVolume() < p2.getVolume();
}

bool byVolumeDesc(const Package &p1, const Package &p2) {
    return p1.getVolume() > p2.getVolume();
}

bool byWeightAsc(const Package &p1, const Package &p2) {
    return p1.getWeight() < p2.getWeight();
}

bool byWeightDesc(const Package &p1, const Package &p2) {
    return p1.getWeight() > p2.getWeight();
}

bool byRewardAsc(const Package &p1, const Package &p2) {
    return p1.getReward() < p2.getReward();
}

bool byRewardDesc(const Package &p1, const Package &p2) {
    return p1.getReward() > p2.getReward();
}

bool byDurationAsc(const Package &p1, const Package &p2) {
    return p1.getDuration() < p2.getDuration();
}

bool byDurationDesc(const Package &p1, const Package &p2) {
    return p1.getDuration() > p2.getDuration();
}

bool byMaxVolumeAsc(const Truck &t1, const Truck &t2) {
    return t1.getMaxVolume() < t2.getMaxVolume();
}

bool byMaxVolumeDesc(const Truck &t1, const Truck &t2) {
    return t1.getMaxVolume() > t2.getMaxVolume();
}

bool byMaxWeightAsc(const Truck &t1, const Truck &t2) {
    return t1.getMaxWeight() < t2.getMaxWeight();
}

bool byMaxWeightDesc(const Truck &t1, const Truck &t2) {
    return t1.getMaxWeight() > t2.getMaxWeight();
}

bool byCostAsc(const Truck &t1, const Truck &t2) {
    return t1.getCost() < t2.getCost();
}

bool byCostDesc(const Truck &t1, const Truck &t2) {
    return t1.getCost() > t2.getCost();
}