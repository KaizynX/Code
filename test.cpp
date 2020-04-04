#include <iostream>
#include <thread>

void f1()
{
    for (int i = 1; i <= 100; ++i) {
        std::cout << 'A';
    }
}

template <int val>
struct Node
{
    ;
};

constexpr int f(int x) { return x; }

signed main()
{
    // std::thread t1 = std::thread(f1);
    // t1.join();
    // std::cout << t1.get_id() << std::endl;
    int n;
    std::cin >> n;
    return 0;
}