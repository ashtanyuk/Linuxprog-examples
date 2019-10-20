/*
  Simple Thread Function

  * Part of "Threading with Boost - Part I: Creating Threads", published at:

      http://antonym.org/boost

  Copyright (c) 2009 Gavin Baker <gavinb@antonym.org>
  Published under the MIT license, see LICENSE for details
 */

#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
using namespace std;

void workerFunc()
{
    boost::posix_time::seconds workTime(3);
    cout << "Worker: running" << endl;

    // Pretend to do something useful...
    boost::this_thread::sleep(workTime);
    cout << "Worker: finished" << endl;
}

int main(int argc, char* argv[])
{
    cout << "main: startup" << endl;
    boost::thread workerThread(workerFunc);
    cout << "main: waiting for thread" << endl;
    workerThread.join();
    cout << "main: done" << endl;
    return 0;
}
