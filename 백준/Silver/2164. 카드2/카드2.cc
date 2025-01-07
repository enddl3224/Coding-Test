#include <iostream>
#include <queue>

int main() {
    int N;
    std::cin >> N;

    std::queue<int> cards;
    for (int i = 1; i <= N; i++) {
        cards.push(i);
    }

    while (cards.size() > 1) {
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }
    std::cout << cards.front() << std::endl;
    return 0;
}