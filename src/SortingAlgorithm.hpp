#pragma once

#include <vector>
#include <algorithm>
#include <concepts> // per std::convertible_to

namespace SortLibrary 
{

template<typename T>
concept Sortable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
    const size_t n = v.size();
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                std::swap(v[j], v[j + 1]);
        }
    }
}

template<Sortable T>
void HeapSort(std::vector<T>& v)
{
    // Usa heap massimo di default
    std::make_heap(v.begin(), v.end());
    std::sort_heap(v.begin(), v.end());
}

template<Sortable T>
void HeapSort1(std::vector<T>& v)
{
    // Usa un heap con funzione di confronto esplicita (heap massimo)
    auto compare = [](const T& a, const T& b) { return a < b; }; // max-heap
    std::make_heap(v.begin(), v.end(), compare);
    std::sort_heap(v.begin(), v.end(), compare);
}

}

