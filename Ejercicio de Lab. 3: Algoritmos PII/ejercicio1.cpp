#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

double calcularMediana(const vector<int>& nums) {
    int size = nums.size();
    if (size % 2 == 0) {
        return (nums[size / 2 - 1] + nums[size / 2]) / 2.0;
    } else {
        return nums[size / 2];
    }
}

int main() {
    cout << "Ejercicio 1" << endl;

    vector<int> nums1 = {1, 2, 3, 3};
    vector<int> nums2 = {2, 3, 4};

    int count = nums1.size() + nums2.size();
    vector<int> nums_merge(count);

    cout << "Arreglo Nums1: "; 
    for (int i = 0; i < nums1.size(); i++) {
        cout << "[" << nums1[i] << "] ";
    }

    cout << "\nArreglo Nums2: ";
    for (int i = 0; i < nums2.size(); i++) {
        cout << "[" << nums2[i] << "] ";
    }

    auto start = chrono::high_resolution_clock::now();

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums_merge.begin());

    auto end = chrono::high_resolution_clock::now();

    cout << "\nArreglo Nums_Merge: ";
    for (int i = 0; i < count; i++) {
        cout << "[" << nums_merge[i] << "] ";
    }
    cout << endl;

    double mediana = calcularMediana(nums_merge);
    cout << "La mediana es: " << mediana << endl;

    chrono::duration<double, std::milli> duration = end - start; 
    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;

    return 0;
}
