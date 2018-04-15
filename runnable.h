#ifndef _RUNNABLE_H_INCLUDED_
#define _RUNNABLE_H_INCLUDED_

#include <thread>
#include <atomic>
#include <memory>

using namespace std;

class runnable
{
public:
    virtual void run() = 0;
    void stop()
    {
        stopflag = true;
        _thread->join();
    }
    void start()
    {
        stopflag = false;
        _thread.reset(
            new std::thread(
            [this](){thread_proc();}));
    }
    bool running() const
    {
        return is_running;
    }
private:
    void thread_proc()
    {
        is_running = true;
        while(!stopflag)
        {
            run();
        }
        is_running = false;
    }
private:
    unique_ptr<std::thread> _thread{nullptr};
    atomic<bool> stopflag{false};
    atomic<bool> is_running{false};
};

#endif // _RUNNABLE_H_INCLUDED_