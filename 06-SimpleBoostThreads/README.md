Build command:

*Mac OS X:*

    g++ -I/opt/local/include -L/opt/local/lib -lboost_thread-mt -lboost_system-mt -o simple simple.cpp

*Linux:*

    g++ -o simple simple.cpp -lboost_thread -l boost_system