#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int rndm_pivot(int left, int right) {
    return left + rand() % (right - left + 1);
}

int partition(std::vector<int>& arr, int left, int right) {
    int pivot_index = rndm_pivot(left, right);
    int pivot_value = arr[pivot_index];

    swap(arr[pivot_index], arr[right]);
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot_value) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[right]);
    return i;
}


void quick_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}

void bucketSort(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> buckets(n);

    int min_val = *std::min_element(nums.begin(), nums.end());
    int max_val = *std::max_element(nums.begin(), nums.end());

    double range = (double)(max_val - min_val + 1) / n;

    for (int i = 0; i < n; i++) {
        int bucketIndex = (nums[i] - min_val) / range;
        buckets[bucketIndex].push_back(nums[i]);
    }

    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            nums[index++] = buckets[i][j];
        }
    }
}


void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> Left(n1);
    std::vector<int> Right(n2);

    for (int i = 0; i < n1; i++) {
        Left[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        Right[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 and j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main() {
    setlocale(LC_ALL, "russian");
    srand(time(nullptr));

    const int N = 20;
    int i;
    std::vector<int>count(N);

    for (i = 0; i < N; i++)
    {
        count[i] = rand() / 100;
        std::cout << count[i] << ",";
    }
    std::cout << "\nРезультат выполнения Merge sort : " << std::endl;

    mergeSort(count, 0, count.size() - 1);

    for (int N : count) {
        std::cout << N << " ";
    }


    std::vector<int>count2(N);
    std::cout << "\n" << std::endl;
    for (i = 0; i < N; i++)
    {
        count2[i] = rand() / 100;
        std::cout << count2[i] << ",";
    }

    std::cout << "\nРезультат выполнения Bucket sort : " << std::endl;


    bucketSort(count2);
    for (int N : count2) {
        std::cout << N << " ";
    }

    std::vector<int>count3(N);
    std::cout << "\n" << std::endl;
    for (i = 0; i < N; i++)
    {
        count3[i] = rand() / 100;
        std::cout << count3[i] << ",";
    }

    std::cout << "\nРезультат выполнения quick sort : " << std::endl;


    quick_sort(count3, 0, count3.size() - 1);
    for (int N : count3) {
        std::cout << N << " ";
    }
    std::cout << std::endl;
    return 0;
}
