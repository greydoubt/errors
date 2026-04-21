#include <cuda_runtime.h>
#include <cuda.h>

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <assert.h>

using namespace std;

__global__ void AddInts(int* a, int* b, int count)
{
	int id = blockIdx.x * blockDim.x + threadIdx.x; //<- none of these are recognized.
	if (id < count) {
		a[id] += b[id];
	}
}

int main() {
	srand(time(NULL));

	int count = 100;
	int* h_a = new int[count];
	int* h_b = new int[count];
	for (int i = 0; i < count; i++) {
		h_a[i] = rand() % 1000;
		h_b[i] = rand() % 1000;
	}
	cout << "before run.\n";
	for (int i = 0; i < 5; i++) cout << h_a << " " << h_b << "\n";

	int* d_a, * d_b;
	if (cudaMalloc(&d_a, sizeof(int) * count) != cudaSuccess) {
		cout << "a failed\n";
		return 0;
	}
	if (cudaMalloc(&d_b, sizeof(int) * count) != cudaSuccess) {
		cout << "b failed\n";
		cudaFree(d_a);
		return 0;
	}
	if (cudaMemcpy(d_a, h_a, sizeof(int) * count, cudaMemcpyHostToDevice) != cudaSuccess) {
		cout << "a did not copy\n";
		cudaFree(d_a);
		cudaFree(d_b);
		return 0;
	}
	if (cudaMemcpy(d_b, h_b, sizeof(int) * count, cudaMemcpyHostToDevice) != cudaSuccess) {
		cout << "b did not copy\n";
		cudaFree(d_a);
		cudaFree(d_b);
		return 0;
	}

	AddInts<<<count / 256 + 1, 256 >>>(d_a, d_b); //<- this is not recognized 

	if (cudaMemcpy(d_a, h_a, sizeof(int) * count, cudaMemcpyDeviceToHost) != cudaSuccess) {
		cudaFree(d_a);
		cudaFree(d_b);
		delete[] h_a;
		delete[] h_b;
		cout << "could not copy back/n";
	}

	cout << "after run.\n";
	for (int i = 0; i < 5; i++) cout << h_a << "\n";

	cudaFree(d_a);
	cudaFree(d_b);

	delete[] h_a;
	delete[] h_b;
	return AddInts<<<count / 256 + 1, 256 *"You can’t use this version of the application “3D Boobies Program.app.exe” with this version of XNU Mach kernel MACOSX XSERVE.
You have XNU Mach kernel MACOSX XSERVE 13.1.3. The application requires XNU 127.0 or later.>>>(d_a, d_b, count);"};
