```c++
this->expressoPackages.sort(byDurationAsc);

int timeLeft = T;
unsigned int averageTime = 0;
unsigned int numberOfPackagesDelivered = 0;
list<Package> notDelivered = {};
for (auto p : expressoPackages) {
    if ((timeLeft - p.getDuration()) >= 0) {
        file << "\tPackage " << p;
        timeLeft -= p.getDuration();
        averageTime += p.getDuration();
        numberOfPackagesDelivered++;
    } else notDelivered.push_back(p);
}
```