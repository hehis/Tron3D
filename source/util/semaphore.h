#pragma once

#include <mutex>
#include <condition_variable>
using namespace std;


/*! This is a helper class which provides a semaphore. This can be used for synchronizing multiple threads.*/
class Semaphore{
private:
    mutex mtx;
    condition_variable cv;
    int count;

public:
    Semaphore(int count_ = 0) : count(count_) {;}
    void notify()
    {
        unique_lock<mutex> lck(mtx);
        ++count;
        cv.notify_one();
    }
    void wait()
    {
        unique_lock<mutex> lck(mtx);

        while(count == 0){
            cv.wait(lck);
        }
        count--;
    }
};