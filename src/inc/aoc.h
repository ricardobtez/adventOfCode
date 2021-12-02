//
// Created by ricardo.benitez.cruz on 2-12-2021.
//

#ifndef DAYONE_H
#define DAYONE_H

#include <string>

/// \brief
/// Calculates the Number of times an increment happens in the submarine
/// sonar sweep
int getNumberOfIncrementsStatic(const std::string& filename);

/// \brief
/// Get the number of increments happens in the sliding window of the
/// submarine sonar sweep
int getNumberOfIncrementsSliding(const std::string& filename, int windowSize = 3);

#endif //DAYONE_H
