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
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int index = 0;
    int w = 0;
    for (int i = len - 1; i > 0; i--) {
        if (arr[i] < value) {
            index = i;
            break;
        } else {
            continue;
        }
    }
    for (int i = 0; i <= index; i++) {
        w += 1;
        for (int j = w; j <= index; j++) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    if (count != 0) {
        return count;
    } else {
        return 0;
    }
}
int countPairs3(int *arr, int len, int value) {
    int l = 0;
    int r = len - 1;
    int mid = 0;
    int count = 0;
    bool f = true;
    for (int i = 0; i < len; i++) {
        if (arr[i] <= 50) {
            while ((l <= r) && (f)) {
                mid = (l + r) / 2;
                if (arr[mid] + arr[i] == value) {
                    f = false;
                if (value - arr[i] < mid) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (!f) {
                count += 1;
            }
        }
    }
    if (count != 0) {
        return count;
    } else {
        return 0;
    }
}
