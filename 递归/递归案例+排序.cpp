#include <stdio.h>

// 合并两个已排序的子数组
void merge(int arr[], int left[], int left_length, int right[], int right_length) {
    int i = 0, j = 0, k = 0;
    //arr为总数组 left 和 right 为合并数组
    while (i < left_length && j < right_length) {
        //确保只在左右子数组的有效索引范围内进行比较和合并操作，以避免访问越界错误。
        if (left[i] < right[j]) {
            //判断插入位置
            arr[k] = left[i];
            i++;//left的下标
        } else {
            arr[k] = right[j];
            j++;//right的下标
        }
        k++;//主数组的下标
    }

    //为什么还需将剩余的数据再次放入？
    //因为当 while 循环结束时，可能会存在一方的子数组仍然有剩余的元素未被合并。

    /*
    考虑以下情况：左子数组为 [1, 3, 5]，右子数组为 [2, 4, 6]。
    在进行比较和合并操作时，当比较到左子数组的最后一个元素 5 和右子数组的第一个元素 2 时，
    由于 2 < 5，我们会将 2 放入合并后的数组。然后，由于左子数组已经没有元素可以进行比较，
    但右子数组仍然有元素 4 和 6，这些元素应该被加入合并后的数组中。
    */
    
    //将剩余的元素加入合并后的数组
    while (i < left_length) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_length) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// 递归排序
void merge_sort(int arr[], int length) {
    if (length <= 1) { //数组分到为1个
        return;//结束
    }

    int mid = length / 2;//计算中心值，便于分数据
    int left[mid];//左侧从0到mid
    int right[length - mid];//右侧从mid到长度-mid

    // 将原数组分成两个子数组
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < length; i++) {
        right[i - mid] = arr[i];
    }

    // 递归排序左右子数组
    merge_sort(left, mid);
    merge_sort(right, length - mid);

    // 合并两个已排序的子数组
    merge(arr, left, mid, right, length - mid);
}

int main() {
    int arr[] = {5, 2, 9, 1, 3};//排序的数据
    int length = sizeof(arr) / sizeof(arr[0]);

    // 调用归并排序函数
    merge_sort(arr, length);

    printf("Sorted array: ");//输出
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
