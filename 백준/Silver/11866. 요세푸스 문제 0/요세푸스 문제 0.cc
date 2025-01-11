#include <iostream>
#include <deque>

int main() {
    // 결과값 deque
    std::deque<int> result;
    // input 받기
    int N, K;
    std::cin >> N >> K;

    // 원형으로 앉은 사람들 생성
    std::deque<int> people;
    for(int i = 1; i <= N; i++){
        people.push_back(i);
    }

    // std::cout << people.front() << std::endl;

    while(!people.empty()){
        for(int i = 1; i < K; i++){
            // 앞의 원소를 뒤로 보낸 후 삭제
            people.push_back(people.front());
            people.pop_front();
        } //K-1번 반복 후
        // K번째 데이터 결과값 deque에 담은 후 삭제
        result.push_back(people.front());
        people.pop_front();
    }// 사람들이 모두 제거될 때까지 반복

    std::cout << "<";
    for(auto value : result){
        if (value == result.back()){
            std::cout << value;
        } else {
            std::cout << value << ", ";
        }
    }
    std::cout << ">" << std::endl;
}