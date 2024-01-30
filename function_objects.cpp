#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class IndexPrinter {
public:
    IndexPrinter() : index(0) {}

    void operator()(int number) {
        std::cout << "#" << ++index << ": " << number << std::endl;
    }

private:
    int index;
};

class LottoNumberGenerator {
public:
    LottoNumberGenerator(int min, int max) : min(min), max(max) {}

    int operator()();

private:
    int min;
    int max;
    std::vector<int> numbers;
};
int LottoNumberGenerator::operator()() {
    int number;
    do {
        number = rand() % (max - min + 1) + min;
    } while(find(numbers.begin(), numbers.end(), number) != numbers.end());
    numbers.push_back(number);
    return number;
}

int main() {
    srand(time(NULL));
    std::ostream_iterator<int> out_it(std::cout, " ");

    std::vector<int> Lotto(7);
    std::generate(Lotto.begin(), Lotto.end(), LottoNumberGenerator(1, 40));
    std::cout<< "Lotto: ";
    std::copy(Lotto.begin(), Lotto.end(), out_it);
    std::cout<<std::endl;

    std::vector<int> Lotto2(6);
    std::generate(Lotto2.begin(), Lotto2.end(), LottoNumberGenerator(1, 48));
    std::cout<< "Viking lotto: ";
    std::copy(Lotto2.begin(), Lotto2.end(), out_it);
    std::cout<<std::endl;

    std::vector<int> commonNumber;
    std::set_intersection(Lotto.begin(), Lotto.end(), Lotto2.begin(), Lotto2.end(), std::back_inserter(commonNumber));
    std::cout<< "Matching numbers: " <<std::endl;
    std::for_each(commonNumber.begin(), commonNumber.end(), IndexPrinter());
    
    std::vector<int> Lotto3(5);
    std::generate(Lotto3.begin(), Lotto3.end(), LottoNumberGenerator(1, 50));
    std::cout<< "Eurojackpot: ";
    std::copy(Lotto3.begin(), Lotto3.end(), out_it);
    std::cout<<std::endl;
    /*
    std::set_intersection(Lotto.begin(), Lotto.end(), Lotto3.begin(), Lotto3.end(), std::back_inserter(comonNumber));
    std::cout<< "Matching numbers: " <<std::endl;
    std::for_each(comonNumber.begin(), comonNumber.end(), IndexPrinter());
    */
    return 0;
}
