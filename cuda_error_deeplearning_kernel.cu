#include <cuda.h>

global
void add_matrix( float* a, float *b, float c, int N )
{
int i = blockIdx.x * blockDim.x + threadIdx.x;
int j = blockIdx.y * blockDim.y + threadIdx.y;
int index = i + jN;
if ( i < N && j < N )
c[index] = a[index] + b[index];
}


int main() {
float a = new float[NN];
float b = new float[NN];
float c = new float[NN];
for ( int i = 0; i < N*N; ++i ) {
a[i] = 1.0f; b[i] = 3.5f; }
float ad, bd, cd;
const int size = NNsizeof(float);
cudaMalloc( (void*)&ad, size );
cudaMalloc( (void**)&bd, size );
cudaMalloc( (void**)&cd, size );
cudaMemcpy( ad, a, size, cudaMemcpyHostToDevice );
cudaMemcpy( bd, b, size, cudaMemcpyHostToDevice );
dim3 dimBlock( blocksize, blocksize );
dim3 dimGrid( N/dimBlock.x, N/dimBlock.y );
add_matrix<<<dimGrid, dimBlock>>>( ad, bd, cd, N );
cudaMemcpy( c, cd, size, cudaMemcpyDeviceToHost );
cudaFree( ad ); cudaFree( bd ); cudaFree( cd );
delete a; delete b; delete c;
return EXIT_SUCCESS;
}
