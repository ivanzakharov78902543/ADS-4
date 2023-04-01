// Copyright 2021 NNTU-CS
int binsearch(int* arr, int l, int r, int value) {
    int scum = 0;
    int mid = 0;
    int temp = 0;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (arr[mid] == value) {
            scum = scum + 1;
            temp = mid + 1;
            while (arr[temp] == value && temp < r) {
                scum = scum + 1;
                temp = temp + 1;
            }
            temp = mid - 1;
            while (arr[temp] == value && temp > l) {
                scum = scum + 1;
                temp = temp - 1;
            }
            break;
        }
        if (arr[mid] < value) {
            l = mid;
        }
        if (arr[mid] > value) {
            r = mid;
        }
    }
    return scum;
}
int countPairs1(int* arr, int len, int value) {
    int scum = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                scum = scum + 1;
            }
        }
    }
    return scum;
}
int countPairs2(int *arr, int len, int value) {
    int scum = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len - 1; i < j; --j) {
            if (arr[i] + arr[j] == value) {
                scum = scum + 1;
            }
        }
    }
    return scum;
}
int countPairs3(int *arr, int len, int value) {
    int scum = 0;
    int val = 0;
    for (int i = 0; i < len - 1; ++i) {
        val = value - arr[i];
        scum = scum + binsearch(arr, i, len, val);
    }
    return scum;
}
