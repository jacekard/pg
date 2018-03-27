#include <iostream>
#define arr_size 5
#define out_size 3

void init(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
}

void print(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
}

void permutation(int* arr, int size, int* out, int outSize, int index, bool repeats) {
	if (index == outSize) {
		print(out, outSize);
		return;
	}
	bool isUsed = false;
	for (int i = 0; i < size; i++) {
		if (!repeats) {
			for (int j = 0; j < index; j++) {
				if (arr[i] == out[j]) {
					isUsed = true;
					break;
				}
			}
			if (isUsed) {
				isUsed = false;
				continue;
			}
		}
		out[index] = arr[i];
		permutation(arr, size, out, outSize, index + 1, repeats);
	}
}

void combination(int* arr, int size, int* out, int outSize, int index, int smallest) {
	if (index == outSize) {
		print(out, outSize);
		return;
	}
	int largest = size - outSize + index;
	for (int i = smallest; i <= largest; i++) {
		out[index] = arr[i];
		combination(arr, size, out, outSize, index + 1, i + 1);
	}
}

void printPermutations(int* arr, int size, int outSize, bool repeats) {
	int* out = new int[outSize];
	permutation(arr, size, out, outSize, 0, repeats);
	delete out;
	std::cout << "----------------" << std::endl;
}

void permutacje(int* arr, int size) {
	printPermutations(arr, size, size, false);
}

void wariacjeBezPowtorzen(int* arr, int size, int outSize) {
	printPermutations(arr, size, outSize, false);
}

void wariacjeZPowtorzeniami(int* arr, int size, int outSize) {
	printPermutations(arr, size, outSize, true);
}

void kombinacje(int* arr, int size, int outSize) {
	int* out = new int[outSize];
	combination(arr, size, out, outSize, 0, 0);
	delete out;
	std::cout << "----------------" << std::endl;
}

int main() {
	int arr[arr_size];
	init(arr, arr_size);
	permutacje(arr, arr_size);
	wariacjeBezPowtorzen(arr, arr_size, out_size);
	wariacjeZPowtorzeniami(arr, arr_size, out_size);
	kombinacje(arr, arr_size, out_size);
	return 0;
}
