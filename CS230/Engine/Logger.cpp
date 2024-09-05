/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Logger.cpp
Project:    GAM150
Author:     Jonathan Holmes, Junhyeong Kim
Created:    March 8, 2023
Updated:    March 17, 2023
*/

#include <iostream>
#include "Logger.h"

CS230::Logger::Logger(Logger::Severity severity, bool use_console, std::chrono::system_clock::time_point set_time) : min_level(severity), out_stream("Trace.log"), start_time(set_time) {
    if (use_console == true) {
        out_stream.set_rdbuf(std::cout.rdbuf());
    }
}

CS230::Logger::~Logger() {
    out_stream.flush();
    out_stream.close();
}

void CS230::Logger::log(CS230::Logger::Severity severity, std::string message) {
    switch (severity)
    {
    case CS230::Logger::Severity::Verbose:
        if (min_level > severity)
        {
            break;
        }
        out_stream.precision(4);
        out_stream << '[' << std::fixed << seconds_since_start() << "]\t";
        out_stream <<"Verbose"<< "\t" << message << std::endl;
        break;
    case CS230::Logger::Severity::Debug:
        if (min_level > severity)
        {
            break;
        }
        out_stream.precision(4);
        out_stream << '[' << std::fixed << seconds_since_start() << "]\t";
        out_stream << "Debug" << "\t" << message << std::endl;
        break;
    case CS230::Logger::Severity::Event:
        if (min_level > severity)
        {
            break;
        }
        out_stream.precision(4);
        out_stream << '[' << std::fixed << seconds_since_start() << "]\t";
        out_stream << "Event" << "\t" << message << std::endl;
        break;
    case CS230::Logger::Severity::Error:
        if (min_level > severity)
        {
            break;
        }
        out_stream.precision(4);
        out_stream << '[' << std::fixed << seconds_since_start() << "]\t";
        out_stream << "Error" << "\t" << message << std::endl;
        break;
    default:
        break;
    }
    return;
}
