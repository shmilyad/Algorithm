
<!-- TOC -->

- [排序算法总结](#排序算法总结)
    - [内排序](#内排序)
        - [选择法](#选择法)
            - [选择排序](#选择排序)
            - [堆排序](#堆排序)
        - [比较法](#比较法)
            - [冒泡排序](#冒泡排序)
            - [快速排序](#快速排序)
        - [插入法](#插入法)
            - [插入排序](#插入排序)
            - [希尔排序](#希尔排序)
        - [归并排序](#归并排序)
        - [计数排序](#计数排序)
        - [基数排序](#基数排序)
        - [桶排序](#桶排序)
    - [外排序](#外排序)

<!-- /TOC -->
# 排序算法总结
排序默认做升序
## 内排序
### 选择法
#### 选择排序
**算法思路:**
在待排序数组中，选择最大(最小)放在最前(最后)位置
```cpp
void SelectSort(int arr[], int n) {
	if (n <= 1) return;

	// 每次选取最大数和最小数的下标
	int left = 0;
	int right = n - 1;

	while (left < right) {
		for (int i = left; i <= right; i++) {
			int minindex = left;
			int maxindex = right;
			if (arr[i] < arr[minindex]) minindex = i;
			if (arr[i] > arr[maxindex]) maxindex = i;
			swap(arr[left], arr[minindex]);
			if (maxindex == left)   maxindex = minindex;
			swap(arr[right], arr[maxindex]);
		}
		left++;
		right--;
	}

	return;
}
```
#### 堆排序
**算法思路**
显然选择排序的思路每次遍历一遍数组，然后选取最大和最小的数(其实每次选一个也是可以的)，这样选择的代价是O(n),堆排序优化这个选择的过程
``` cpp
// 升序做大堆 反之相同
void AdjustDown(int arr[], int size, int parent) {
	int child = parent * 2 + 1;
	while (child < size) { // 存在孩子
		// 右孩子存在 并且右孩子值大于左孩子 则选区较大的右孩子
		if (child + 1 < size && arr[child + 1] > arr[child])
			++child;
		// 孩子值大于父亲的值 需要交换 然后进行下次迭代
		if (arr[child] > arr[parent]) {
			swap(arr[child], arr[parent]); // 这次交换可以优化 但这块关注算法逻辑
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
	return;
}

void HeapSort(int arr[], int n) {
	if (n <= 1)  return;
	for (int root = (n - 2) / 2; root >= 0; root--) {
		AdjustDown(arr, n, root);
	}
	for (int i = n - 1; i>0; i--) {
		swap(arr[0], arr[i]); // 将堆顶元素放在最后位置
		AdjustDown(arr, i, 0); // 调整堆，堆元素个数为 i
	}
}
```
**小结**
| 名称 | 时间复杂度 | 空间复杂度 | 稳定性 |
|:---|:---|:---|:----|
| 选择排序 | O(n^2) | O(1) | 不稳定 |
| 堆排序 | O(n*logn) | O(1) | 不稳定 |
### 比较法
#### 冒泡排序
**算法思路:**
从一端开始，逐次比较相临元素，发现倒序则交换
```cpp
void BubbleSort(int arr[],int n) {
    for (int i=0; i<n-1; i++) {// 需要比较的趟数
        bool flag = false; // 发生交换改为true 
        for (int j=0; j<n-i-1; j++)  {// 比较的数据
            if (arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if (!bool) // 这一趟没有发生交换,显然是有序的
            break;
    }
}
```
#### 快速排序
**算法思路**
同样是利用比较的思路，快排是在整体上算法优化，划分成两部分，比冒泡局限于相邻显然性能会好很多
快排算法的优劣性取决于每次选区的key值是否居中，在极端情况下退化成n^2的算法
```cpp
int Partion(int arr,int left,int right) {
    int key = arr[left]; // 选取最左边的值作为key 但是为了保证划分的优良性 可以选择三数取中进行优化
    int i = left-1; // [0,i]区间的数整体小于等于key
    int cur = left; // 当前位置
    while (cur <= right) {
        if (arr[cur] <= key) {
            ++i;
            if (i != cur) {
                swap(arr[i],arr[cur]);
            }
        }
        ++cur;
    }
    //[left,i] 的数小于key 将key放到i位置 显然 [left,i-1] 都比key小 右边都比key大
    swap(arr[left],arr[i]);
    return i;
}
void _QuickSort(int arr[],int left,int right) {
    if (left < right) {
        int index = Partion(arr,left,right);
        _QuickSort(arr,left,index-1);
        _QuickSort(arr,index+1,right);
    }
}
void QuickSort(int arr[],int n) {
    if (n <= 1) return arr;
    _QuickSort(arr,0,n-1);
}
``` 
| 名称 | 时间复杂度 | 空间复杂度 | 稳定性 |
| :--- | :--- | :--- | :--- |
| 冒泡排序 | O(n^2) | O(1) | 稳定的 |
| 快排 | O(n*logn) | O(1) | 不稳定 |

### 插入法
#### 插入排序
**算法思路**
将待排序表看作左右两部分，其中左边为有序区，右边为无序区,整个排序过程就是将右边无序区中的元素逐个插入到左边的有序区中，以构成新的有序区。
```cpp
void InsertSort(int arr[],int n) {
   for (int i=1; i<n; i++) { 
       int tmp = arr[i];
       int j = i-1; // [0,j] 有序数组
       while (j >= 0 && arr[j] > tmp ) {
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = tmp;
   }
}
```
#### 希尔排序
**算法思路**
将待排序列划分为若干组，在每组内进行直接插入排序，以使整个序列基本有序，然后再对整个序列进行直接插入排序
```cpp
void ShellSort(int arr[],int n) {
    int d = n/2; // 初始化步长
    while (d > 0) {
        for (int i=d; i<n; i++) {
            int tmp = arr[i];
            int j = i-d;
            while (j >= 0 && arr[j] > tmp) {
                arr[j+d] = arr[j];
                j -= d;
            }
            arr[j+d] = tmp;
        }
        d /= 2; // 步长变为原来的一半
    }
}
```
| 名称 | 时间复杂度 | 空间复杂度 | 稳定性 | 
| :---- | :---- | :---- | :---- |
| 插入排序 | O(n^2) | O(1) | 稳定的 |
| 希尔排序 | O(nlog(2n)) | O(1) | 不稳定的 |
备注：
希尔排序是对插入排序的优化，思想是处理小数组加速，然后合并，但其却破坏了插入排序处理大量有序数组的良好性，所以不算一个很成功的优化。  
### 归并排序
**算法思路**
是指将两个或两个以上的有序表合并成一个新的有序表。
```cpp
void Merge(int arr,int left,int mid,int right) {
    int i = left;
    int j = mid+1;
    vector<int> tmp[right-left+1];
    int index = 0;
    while (i<=mid && j<=right) {
        if (arr[i] < arr[j])    tmp[index++] = arr[i++];
        else    tmp[index++] = arr[j++];
    }
    while (i <= mid)    tmp[index++] = arr[i++];
    while (j <= right)  tmp[index++] = arr[j++];
    for (int i=left; i<=right; i++)
        arr[i] = tmp[i-left];
}
void _MergeSort(int arr[],int left,int right) {
    if (left < right) {
        int mid = left + (right-left)/2;
        _MergeSort(arr,left,mid);
        _MergeSort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}
void MergeSort(int arr[],int n) {
    _MergeSort(arr,0,n-1);
}
```
| 名称 | 时间复杂度 | 空间复杂度 | 稳定性 |
| :--- | :--- | :--- | :--- | 
| 归并排序 | O(nlogn) | O(n) | 稳定的 |
### 计数排序
**算法思路**
计数排序使用一个额外的数组C，其中第i个元素是待排序数组A中值等于i的元素的个数。
计数排序的核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。
* 平均时间复杂度：O(n + k) // k是数据范围
* 最佳时间复杂度：O(n + k)
* 最差时间复杂度：O(n + k)
* 空间复杂度：O(n + k)
### 基数排序
原理是将整数按位数切割成不同的数字，然后按每个位数分别比较。从高位或者低位开始比较。当时不是说了高位的思路
就是相当于按照位去分治。
* 时间复杂度：O(k*N) // k是最高位的个数
* 空间复杂度：O(k + N)
* 稳定性：稳定

### 桶排序
**算法思想**
就是先分块，假设数据集合是[1,100]，分成k个桶(分成几个都可以)，然后将数据入桶，每个同有序，则整体有序,显然这个算法的效果取决于桶分的优劣例如如果100个数据里绝大多数数据存在在区间[0,10]那样这个桶会堆积太多的数据，导致性能下降。每个桶的排序一般选择快排
* 平均时间复杂度：O(n + k)
* 最佳时间复杂度：O(n + k)
* 最差时间复杂度：O(n ^ 2)
* 空间复杂度：O(n * k)
* 稳定性：取决于每个桶内部的排序算法是否稳定
## 外排序
当数据存储在外存时，内存无法全部加载完全，需要对外存的块进行划分，然后加载到内存去排序，显然这时你可以保证每个块是有序的，但是你如何取保证这些块的整体有序性。
举例
将文件需要分成k块读入，需要从小到大进行排序。
1. 依次读入每个文件块，在内存中对当前文件块进行排序（应用恰当的内排序算法）。此时，每块文件相当于一个由小到大排列的有序队列。
2. 内存中建立一个最小值堆，读入每块文件的队列头。
3. 弹出堆顶元素，如果元素来自第i块，则从第i块文件中补充一个元素到最小值堆。弹出的元素暂存至临时数组。
4. 当临时数组存满时，将数组写至磁盘，并清空数组内容。
5. 重复过程（3）、（4），直至所有文件块读取完毕。

