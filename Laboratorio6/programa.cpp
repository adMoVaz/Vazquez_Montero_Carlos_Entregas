#include <iostream>
#include <algorithm>
using namespace std;

int maxArea(int height[], int n) {
    int left = 0;
    int right = n - 1;
    int max_area = 0;

    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        max_area = max(max_area, area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    cout << "Ejercicio Laboratorio ADA" << endl;

    int height[] = {6, 1, 4, 7, 3, 6, 2, 5, 8, 3, 9};
    int size = sizeof(height) / sizeof(height[0]);

    cout << "Values Array: ";
    for (int i = 0; i < size; i++) {
        cout << "[" << height[i] << "] ";
    }
    cout << endl;

    int max_water = maxArea(height, size);
    cout << "La máxima cantidad de agua que se puede contener es: " << max_water << endl;

    return 0;
}
