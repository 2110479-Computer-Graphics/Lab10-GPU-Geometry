#pragma once
#include "gpu.h"
#include <iostream>
#include <set>
inline std::set<std::string> unfinished;
inline std::mutex task_mutex;
HD inline void task_not_done(const char* id) {
#ifndef __CUDA_ARCH__
    std::lock_guard<std::mutex> lock(task_mutex); unfinished.insert(id);
#endif
}
inline void print_tasks() { for (auto& id:unfinished) std::cout<<"TASK "<<id<<" not done\n"; }
