#include "Utils.h"

bool byVolume(const Package &p1, const Package &p2) {
    return p1.getVolume() < p2.getVolume();
}

bool byWeight(const Package &p1, const Package &p2) {
    return p1.getWeight() < p2.getWeight();
}

bool byReward(const Package &p1, const Package &p2) {
    return p1.getReward() < p2.getReward();
}

bool byDuration(const Package &p1, const Package &p2) {
    return p1.getDuration() < p2.getDuration();
}

bool byMaxVolume(const Truck &t1, const Truck &t2) {
    return t1.getMaxVolume() < t2.getMaxVolume();
}

bool byMaxWeight(const Truck &t1, const Truck &t2) {
    return t1.getMaxWeight() < t2.getMaxWeight();
}

bool byCost(const Truck &t1, const Truck &t2) {
    return t1.getCost() < t2.getCost();
}