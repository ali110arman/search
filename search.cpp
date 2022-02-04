#include <iostream>
using namespace std;
class sort {
public:
	sort();
	int n;
	int arr[20];
	int max();
	void bubbleSort();
	void insertionSort();
	void quickSort(int low, int high);
	void selectionSort();
	void mergeSort(int l, int r);
	void heapSort();
	void printArray();
private:
	int partition(int low, int high);
	void merge(int l, int m, int r);
	void heapify(int arr[], int n, int i);
	void swap(int* xp, int* yp);
};
sort::sort() {
	cout << "inter count: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int sort::max() {
	return n;
}

void sort::swap(int* xp, int* yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void sort::bubbleSort(){
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void sort::insertionSort(){
	int i, key, j;
	for (i = 1; i < n; i++){
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int sort::partition( int low, int high){
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++){
		if (arr[j] < pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void sort::quickSort( int low, int high){
	if (low < high){
		int pi = partition(low, high);
		quickSort( low, pi - 1);
		quickSort(pi + 1, high);
	}
}

void sort::selectionSort(){
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++){ 
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		swap(&arr[min_idx], &arr[i]);
	}
}
 
void sort::merge( int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L, * R;
	L = new int[n1];
	R = new int[n2];
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	int i = 0;
	int j = 0;
	int k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void sort::mergeSort( int l, int r) {
	if (l >= r)
		return;
	int m = (l + r - 1) / 2;
	mergeSort(l, m);
	mergeSort(m + 1, r);
	merge(l, m, r);
}

void sort::heapify(int arr[], int n, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void sort::heapSort(){
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void sort::printArray() {
	cout << "Sorted array: "<<endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void main(){
	sort s;
	//s.bubbleSort();
	//s.insertionSort();
	//s.selectionSort();
	//s.quickSort(0, s.max() - 1);
	//s.mergeSort(0, s.max() - 1);
	s.heapSort();
	s.printArray();
}
