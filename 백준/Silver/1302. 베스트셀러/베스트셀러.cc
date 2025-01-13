#include <iostream>
#include <map>
#include <string>

int main(){
    int max = 0;
    std::string bestseller;
    // 입력받기
    int N;
    std::cin >> N;

    // N의 길이만큼 map 생성
    std::map<std::string, int> today_books;
    for(int i = 0; i < N; i++){
        std::string book_name;
        std::cin >> book_name;

        if(today_books.find(book_name) != today_books.end()){
            today_books[book_name] += 1;
        } // map에 동일한 book_name을 가진 key값이 있다면 count
        else{
            // map에 book_name을 가진 key 생성
            today_books[book_name] = 1;
        }
        // 이전의 값과 비교했을때, 값이 크다면 max, 작다면 min
        if(i==0){
            bestseller = book_name;
        }

        // 판매량이 다를 경우 가장 높은 판매량이 베스트셀러
        if(today_books[book_name] > max){
            max = today_books[book_name];
            bestseller = book_name;
        }
        // 판매량이 같을 경우 알파벳이 빠른 순이 베스트셀러
        else if(today_books[book_name] == max){
            if(book_name < bestseller){
                bestseller = book_name;
            }
        }
    }
    std::cout << bestseller << std::endl;
}