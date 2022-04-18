# Excertos de código com formatação bonita

```c++
if (desvioAbsMaxPeso >= desvioAbsMaxVolume) {
    this->trucks.sort(byMaxVolumeDesc);
    this->packages.sort(byVolumeAsc);
} else {
    this->trucks.sort(byMaxWeightDesc);
    this->packages.sort(byWeightAsc);
}

list<Package> notDelivered = {};
list<Truck>::iterator j = trucks.begin();
for (list<Package>::iterator i = packages.begin(); i != packages.end(); i++)
{   
    if ((*j).addPackage(*i)) continue;
    else if (j == trucks.end()) {
        (*i).addPriority();
        notDelivered.push_back(*i);
    } else {
        j++;
        i--;
    }
}
```