// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; i++) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; i < j; j--) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    return count;
}
int binsearch(int* arr, int l, int r, int value) {
    int mid = 0;
    int k = 0;
    int count = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[mid] == value) {
            count += 1;
            k = mid + 1;
            while (arr[k] == value && k < r) {
                count += 1;
                k += 1;
            }
            k = mid - 1;
            while (arr[k] == value && k < r) {
                count += 1;
                k -= 1;
            }
        }
        if (arr[mid] > value) {
            r = mid - 1;
        } else {
             l = mid + 1;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        count += binsearch(arr, i, len, value - arr[i]);
    }
    return count;
}
