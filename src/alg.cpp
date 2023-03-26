// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; i++) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    if (count != 0) {
        return count / 2;
    } else {
        return 0;
    }
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j > 0; j--) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    if (count != 0) {
        return count;
    }
    else {
        return 0;
    }
}
    int binsearch(int* arr, int l, int r, int value) {
    int mid = 0;
    int k = 0;
    bool f = true;
    while ((l <= r) && (f)) {
        mid = (l + r) / 2;
        if (arr[mid] == value) {
            f = false;
            k = arr[mid];
        }
        if (arr[mid] > value) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    if (f) {
        return k;
    }
    else {
        return 0;
    }
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] + binsearch(arr, i, len, value - arr[i]) == value) {
            count += 1;
        }
    }
    if (count != 0) {
        return count;
    }
    else {
        return 0;
    }
}
