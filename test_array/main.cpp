#include <iostream>
#include <random>
#include <unordered_set>
#include <ctime>

//Функция для сортировки массивов
inline void qsort(int *arr, int first, int last, const int &number_array) {
    int left {first}, right {last};
    int mid {arr[(left + right) / 2]}, temporary {};
    //Сортируем нечетные
    if(number_array % 2) {
        do {
            while (arr[left] > mid) ++left;
            while (arr[right] < mid) --right;
            if (left <= right) {
                temporary = arr[left];
                arr[left] = arr[right];
                arr[right] = temporary;
                ++left;
                --right;
            }
        } while (left < right);
        if (first < right)
            qsort(arr, first, right, number_array);
        if (left < last)
            qsort(arr, left, last, number_array);
    }
    //Сортируем четные
    else {
        do {
            while (arr[left] < mid) ++left;
            while (arr[right] > mid) --right;
            if (left <= right) {
                temporary = arr[left];
                arr[left] = arr[right];
                arr[right] = temporary;
                ++left;
                --right;
            }
        } while (left < right);
        if (first < right)
            qsort(arr, first, right, number_array);
        if (left < last)
            qsort(arr, left, last, number_array);
    }
}

int **random_arrays(int n) {
    auto **arr_with_arr = new int* [n];// Создаем динамический массив, который будет хранить созданные массивы
    std::mt19937 random_number(static_cast<unsigned int>(time(nullptr)));//Создаёт случайные числа
    std::unordered_set<int> random_sizes;//Создаем набор,в котором будут хранится размеры будущих массивов
    while(random_sizes.size() != n)
        random_sizes.emplace(random_number() % (n + 50));//Заполняем его уникальными рандомными значениями
    auto iter {random_sizes.begin()};
    //Создаем рандомные массивы
    for(int i = 0; i < n; ++i, ++iter) {
        arr_with_arr[i] = new int [*iter];
    }
    iter = random_sizes.begin();
    //Заполняем массивы случайными числами
    for(int i = 0; i < n; ++i, ++iter) {
        for(int j = 0; j < *iter; ++j)
            arr_with_arr[i][j] = random_number() % (n + 10000);
    }
    iter = random_sizes.begin();
    //Сортируем их
    for(int i = 0; i < n; ++i, ++iter) {
        qsort(arr_with_arr[i], 0, *iter - 1, i);
    }
    return arr_with_arr;
};

int main() {
    
    return 0;
}
