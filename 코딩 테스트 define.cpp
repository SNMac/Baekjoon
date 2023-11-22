#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define TIME_START chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
#define TIME_END chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
#define TIME_PRINT cout << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << "ms\n";
// #define DEBUG

#ifdef DEBUG
#include <chrono>
#include <random>
#endif

#ifdef DEBUG
    random_device rd;
    default_random_engine dre(rd());
    uniform_int_distribution dis(-1000, 1000);  // need to edit numbers
#endif

#ifdef DEBUG
    dis(dre);  // generate random number
#endif

#ifdef DEBUG  // clock start
    TIME_START
#endif

#ifdef DEBUG  // clock end
    TIME_END
    TIME_PRINT
#endif