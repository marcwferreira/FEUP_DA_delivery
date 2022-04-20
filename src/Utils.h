/**
 * @file Utils
 * @brief This contains the implementation of some comparison functions to auxiliate MailSystem
 *
 * @author Fábio Araújo de Sá, Francisco João Gonçalves Calado Araújo, Marcos William Ferreira Pinto
 *
 * @date 04/02/2022
 */

#ifndef UTILS_H
#define UTILS_H

#include "Package.h"
#include "Truck.h"

/**
 * @brief Boolean function thar compares to packages based on their volume(asc)
 * 
 * @param p1 First package to be compared
 * @param t2 Second package to be compared
 * @return true if volume of p1 is lower than cost of p2
 * @return false if volume of p2 is lower than cost of p1
 */
bool byVolumeAsc(const Package &p1, const Package &p2);

/**
 * @brief Boolean function thar compares to packages based on their volume (desc)
 * 
 * @param p1 First package to be compared
 * @param t2 Second package to be compared
 * @return true if volume of p1 is higher than cost of p2
 * @return false if volume of p2 is higher than cost of p1
 */
bool byVolumeDesc(const Package &p1, const Package &p2);

/**
 * @brief Boolean function thar compares to packages based on their priority (asc)
 * 
 * @param p1 First package to be compared
 * @param t2 Second package to be compared
 * @return true if priority of p1 is lower than cost of p2
 * @return false if priority of p2 is lower than cost of p1
 */
bool byPriorityAsc(const Package &p1, const Package &p2);

/**
 * @brief Boolean function thar compares to packages based on their priority (desc)
 * 
 * @param p1 First package to be compared
 * @param t2 Second package to be compared
 * @return true if priority of p1 is higher than cost of p2
 * @return false if priority of p2 is higher than cost of p1
 */
bool byPriorityDesc(const Package &p1, const Package &p2);

/**
 * @brief Boolean function thar compares to packages based on their weight (asc)
 * 
 * @param p1 First package to be compared
 * @param t2 Second package to be compared
 * @return true if weight of p1 is lower than cost of p2
 * @return false if weight of p2 is lower than cost of p1
 */
bool byWeightAsc(const Package &p1, const Package &p2);

/**
 * @brief Boolean function thar compares to packages based on their weight (desc)
 * 
 * @param p1 First package to be compared
 * @param t2 Second package to be compared
 * @return true if weight of p1 is higher than cost of p2
 * @return false if weight of p2 is higher than cost of p1
 */
bool byWeightDesc(const Package &p1, const Package &p2);

/**
 * @brief Boolean function thar compares to packages based on their profit (asc)
 * 
 * @param p1 First package to be compared
 * @param t2 Second package to be compared
 * @return true if profit of p1 is lower than cost of p2
 * @return false if profit of p2 is lower than cost of p1
 */
bool byRewardAsc(const Package &p1, const Package &p2);

/**
 * @brief Boolean function thar compares to packages based on their profit (desc)
 * 
 * @param p1 First package to be compared
 * @param t2 Second package to be compared
 * @return true if profit of p1 is higher than cost of p2
 * @return false if profit of p2 is higher than cost of p1
 */
bool byRewardDesc(const Package &p1, const Package &p2);

/**
 * @brief Boolean function thar compares to packages based on their time to be delivered (asc)
 * 
 * @param p1 First package to be compared
 * @param t2 Second package to be compared
 * @return true if time to deliver of p1 is lower than cost of p2
 * @return false if time to deliver of p2 is lower than cost of p1
 */
bool byDurationAsc(const Package &p1, const Package &p2);

/**
 * @brief Boolean function thar compares to packages based on their time to be delivered (desc)
 * 
 * @param p1 First package to be compared
 * @param t2 Second package to be compared
 * @return true if time to deliver of p1 is higher than cost of p2
 * @return false if time to deliver of p2 is higher than cost of p1
 */
bool byDurationDesc(const Package &p1, const Package &p2);

/**
 * @brief Boolean function thar compares to Trucks based on their volume (asc)
 * 
 * @param t1 First truck to be compared
 * @param t2 Second truck to be compared
 * @return true if volume of t1 is lower than cost of t2
 * @return false if volume of t2 is lower than cost of t1
 */
bool byMaxVolumeAsc(const Truck &t1, const Truck &t2);

/**
 * @brief Boolean function thar compares to Trucks based on their volume (desc)
 * 
 * @param t1 First truck to be compared
 * @param t2 Second truck to be compared
 * @return true if volume of t1 is larger than cost of t2
 * @return false if volume of t2 is larger than cost of t1
 */
bool byMaxVolumeDesc(const Truck &t1, const Truck &t2);

/**
 * @brief Boolean function thar compares to Trucks based on their weight (asc)
 * 
 * @param t1 First truck to be compared
 * @param t2 Second truck to be compared
 * @return true if weight of t1 is lower than cost of t2
 * @return false if weight of t2 is lower than cost of t1
 */
bool byMaxWeightAsc(const Truck &t1, const Truck &t2);

/**
 * @brief Boolean function thar compares to Trucks based on their weight (desc)
 * 
 * @param t1 First truck to be compared
 * @param t2 Second truck to be compared
 * @return true if weight of t1 is larger than cost of t2
 * @return false if weight of t2 is larger than cost of t1
 */
bool byMaxWeightDesc(const Truck &t1, const Truck &t2);

/**
 * @brief Boolean function thar compares to Trucks based on their cost (asc)
 * 
 * @param t1 First truck to be compared
 * @param t2 Second truck to be compared
 * @return true if cost of t1 is lower than cost of t2
 * @return false if cost of t2 is lower than cost of t1
 */
bool byCostAsc(const Truck &t1, const Truck &t2);

/**
 * @brief Boolean function thar compares to Trucks based on their cost (desc)
 * 
 * @param t1 First truck to be compared
 * @param t2 Second truck to be compared
 * @return true if cost of t1 is larger than cost of t2
 * @return false if cost of t2 is larger than cost of t1
 */
bool byCostDesc(const Truck &t1, const Truck &t2);

#endif /* UTILS_H */