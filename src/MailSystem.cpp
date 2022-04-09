#include "MailSystem.h"

MailSystem::MailSystem()
{
    this->trucks = FileReader::getTrucks(TRUCKS_FILE);
    this->packages = FileReader::getPackages(PACKAGES_FILE);
}

void MailSystem::case1()
{
    if (statistics())
    {
        this->trucks.sort(byMaxVolumeDesc); // descending
        this->packages.sort(byVolumeAsc);   // ascending -> na carrinha maior cabem mais packages menores
    }
    else
    {
        this->trucks.sort(byMaxWeightDesc); // descending
        this->packages.sort(byWeightAsc);   // ascending -> na carrinha que pode levar mais peso cabem mais packages menos pesados
    }

    for (list<Package>::iterator i = packages.begin(); i != packages.end(); i++)
    {
        if (!(*i).isExpress())
        {
            for (list<Truck>::iterator j = trucks.begin(); j != trucks.end(); j++)
            {
                if ((*j).addPackage(*i))
                    break;
            }
        }
    }

    // results
    // cout << "\nBy Weight!" << endl;
    // int howManyTrucks = 0, howManyPackages = 0, totalPackages = 0;
    // for (list<Truck>::iterator j = trucks.begin(); j != trucks.end(); j++)
    // {
    //     list<Package> p = (*j).getPackages();
    //     if (!p.empty())
    //     {
    //         // cout << "Truck: " << *j;
    //         ;
    //         for (auto i = p.begin(); i != p.end(); i++)
    //         {
    //             cout << (*i);
    //             howManyPackages++;
    //             totalPackages++;
    //         }
    //         // cout << "Number of Packages: " << howManyPackages << endl
    //         //      << endl;
    //         howManyTrucks++;
    //         howManyPackages = 0;
    //     }
    // }
    // cout << howManyTrucks << ",";
    // cout << "Number of trucks: " << howManyTrucks << endl;
    // cout << "Number of packages (total, !express): " << totalPackages << endl;
    // reset();
    cout << endl;
}

bool MailSystem::statistics()
{
    /* Sorting both the trucks and the packages */
    reset();

    /* Trucks -> média de peso máximo, média de volume máximo, média de custo */
    /* Trucks -> desvio padrão máximo de peso máximo, desvio padrão máximo de volume máximo, desvio padrão máximo de custo */

    // cout << "\nTrucks:" << endl;

    long long int pesoTotal = 0, volumeTotal = 0, custoTotal = 0;
    double numberTrucks = trucks.size();
    for (const Truck &t : trucks)
    {
        pesoTotal += t.getMaxWeight();
        volumeTotal += t.getMaxVolume();
        custoTotal += t.getCost();
    }

    double mediaDensidade = pesoTotal / (double)volumeTotal;
    double mediaPeso = pesoTotal / numberTrucks, mediaVolume = volumeTotal / numberTrucks, mediaCusto = custoTotal / numberTrucks;

    // cout << "Média do peso: " << mediaPeso << "\nMédia do volume: " << mediaVolume << "\nMédia da densidade: " << mediaDensidade << "\nMédia do custo: " << mediaCusto << endl;

    double desvioPeso = 0, desvioVolume = 0, desvioCusto = 0, desvioDensidade = 0;

    for (const Truck &t : trucks)
    {
        desvioPeso = abs(mediaPeso - t.getMaxWeight()) > desvioPeso ? abs(mediaPeso - t.getMaxWeight()) : desvioPeso;
        desvioVolume = abs(mediaVolume - t.getMaxVolume()) > desvioVolume ? abs(mediaVolume - t.getMaxVolume()) : desvioVolume;
        desvioCusto = abs(mediaCusto - t.getCost()) > desvioCusto ? abs(mediaCusto - t.getCost()) : desvioCusto;
        desvioDensidade = abs(mediaDensidade - t.getMaxWeight() / (double)t.getMaxVolume()) > desvioDensidade ? abs(mediaDensidade - t.getMaxWeight() / (double)t.getMaxVolume()) : desvioDensidade;
    }

    // cout << "Desvio máximo do peso: " << desvioPeso << "\nDesvio máximo do volume: " << desvioVolume << "\nDesvio máximo da densidade: " << desvioDensidade << "\nDesvio máximo do custo: " << desvioCusto << endl;

    /* Packages -> média de peso, média de volume, média de recompensa, média de duração */
    /* Packages -> desvio padrão máximo de peso, desvio padrão máximo de volume, desvio padrão máximo de recompensa, desvio padrão máximo de duração */

    // cout << "\nPackages:" << endl;

    pesoTotal = 0, volumeTotal = 0;
    double duracaoTotal = 0, recompensaTotal = 0;
    double numberPackages = packages.size();
    for (const Package &p : packages)
    {
        pesoTotal += p.getWeight();
        volumeTotal += p.getVolume();
        recompensaTotal += p.getReward();
        duracaoTotal += p.getDuration();
    }

    mediaDensidade = pesoTotal / (double)volumeTotal;
    mediaPeso = pesoTotal / numberPackages, mediaVolume = volumeTotal / numberPackages;
    double mediaRecompensa = recompensaTotal / numberPackages, mediaDuracao = duracaoTotal / numberPackages;

    // cout << mediaPeso << "," << mediaVolume << ",";
    // cout << "Média do peso: " << mediaPeso << "\nMédia do volume: " << mediaVolume << "\nMédia da densidade: " << mediaDensidade << "\nMédia da recompensa: " << mediaRecompensa << "\nMédia da duração: " << mediaDuracao << endl;

    desvioPeso = 0, desvioVolume = 0, desvioDensidade = 0;
    double desvioRecompensa = 0, desvioDuracao = 0;

    for (const Package &p : packages)
    {
        desvioPeso = abs(mediaPeso - p.getWeight()) > desvioPeso ? abs(mediaPeso - p.getWeight()) : desvioPeso;
        desvioVolume = abs(mediaVolume - p.getVolume()) > desvioVolume ? abs(mediaVolume - p.getVolume()) : desvioVolume;
        desvioRecompensa = abs(mediaRecompensa - p.getReward()) > desvioRecompensa ? abs(mediaRecompensa - p.getReward()) : desvioRecompensa;
        desvioDuracao = abs(mediaDuracao - p.getDuration()) > desvioDuracao ? abs(mediaDuracao - p.getDuration()) : desvioDuracao;
        desvioDensidade = abs(mediaDensidade - p.getWeight() / (double)p.getVolume()) > desvioDensidade ? abs(mediaDensidade - p.getWeight() / (double)p.getVolume()) : desvioDensidade;
    }
    // cout << desvioPeso << "," << desvioVolume << ",";
    // cout << "Desvio máximo do peso: " << desvioPeso << "\nDesvio máximo do volume: " << desvioVolume << "\nDesvio máximo da densidade: " << desvioDensidade << "\nDesvio máximo da recompensa: " << desvioRecompensa << "\nDesvio máximo da duração: " << desvioDuracao << endl;

    if (desvioPeso > desvioVolume)
    {
        return true;
    }

    return false;
}

void MailSystem::reset()
{

    for (list<Truck>::iterator it = trucks.begin(); it != trucks.end(); it++)
    {
        (*it).clearPackages();
    }
    this->trucks.sort();
    this->packages.sort();
}