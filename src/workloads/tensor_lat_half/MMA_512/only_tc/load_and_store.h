#ifndef LOAD_AND_STORE_H
#define LOAD_AND_STORE_H

#include <cuda_runtime.h>
#include <iostream>

#define NUM_ELEMENTS 512
#define NUM_TO_STORE1  400
#define NUM_TO_STORE2  320
#define NUM_TO_STORE3  256
#define NUM_TO_STORE4  160

__global__ void load_and_store(int *inputData, int *outputData, int numElements, int numToStore) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    // 동적 공유 메모리 선언
    extern __shared__ int sharedData[];

    // 주어진 numElements만큼 데이터를 불러옵니다.
    if (idx < numElements) {
        sharedData[idx] = inputData[idx];
    }

    __syncthreads(); // 모든 데이터 로드 완료를 대기

    // 지정된 개수만큼 데이터를 다시 저장
    if (idx < numToStore) {
        outputData[idx] = sharedData[idx];
    }
}

void executeLoadAndStore1() {
    int *deviceInput, *deviceOutput;

    // 호스트 데이터 초기화 (NUM_ELEMENTS 크기로 생성)
    int hostInput[NUM_ELEMENTS];
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        hostInput[i] = i;  // 단순히 인덱스 값 할당
    }

    // GPU 메모리 할당
    cudaMalloc((void **)&deviceInput, NUM_ELEMENTS * sizeof(int));
    cudaMalloc((void **)&deviceOutput, NUM_TO_STORE1 * sizeof(int));

    // 호스트 데이터를 장치 메모리로 복사
    cudaMemcpy(deviceInput, hostInput, NUM_ELEMENTS * sizeof(int), cudaMemcpyHostToDevice);

    // 커널 구성
    int blockSize = 256;  // 블록당 스레드 수
    int gridSize = (NUM_ELEMENTS + blockSize - 1) / blockSize;  // 필요한 그리드 크기 계산
    size_t sharedMemSize = NUM_ELEMENTS * sizeof(int);  // 동적 공유 메모리 크기 설정

    // 커널 실행
    load_and_store<<<gridSize, blockSize, sharedMemSize>>>(deviceInput, deviceOutput, NUM_ELEMENTS, NUM_TO_STORE1);
    cudaDeviceSynchronize();

    // GPU 메모리 해제
    cudaFree(deviceInput);
    cudaFree(deviceOutput);
}

void executeLoadAndStore2() {
    int *deviceInput, *deviceOutput;

    // 호스트 데이터 초기화 (NUM_ELEMENTS 크기로 생성)
    int hostInput[NUM_ELEMENTS];
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        hostInput[i] = i;  // 단순히 인덱스 값 할당
    }

    // GPU 메모리 할당
    cudaMalloc((void **)&deviceInput, NUM_ELEMENTS * sizeof(int));
    cudaMalloc((void **)&deviceOutput, NUM_TO_STORE2 * sizeof(int));

    // 호스트 데이터를 장치 메모리로 복사
    cudaMemcpy(deviceInput, hostInput, NUM_ELEMENTS * sizeof(int), cudaMemcpyHostToDevice);

    // 커널 구성
    int blockSize = 256;  // 블록당 스레드 수
    int gridSize = (NUM_ELEMENTS + blockSize - 1) / blockSize;  // 필요한 그리드 크기 계산
    size_t sharedMemSize = NUM_ELEMENTS * sizeof(int);  // 동적 공유 메모리 크기 설정

    // 커널 실행
    load_and_store<<<gridSize, blockSize, sharedMemSize>>>(deviceInput, deviceOutput, NUM_ELEMENTS, NUM_TO_STORE2);
    cudaDeviceSynchronize();

    // GPU 메모리 해제
    cudaFree(deviceInput);
    cudaFree(deviceOutput);
}


void executeLoadAndStore3() {
    int *deviceInput, *deviceOutput;

    // 호스트 데이터 초기화 (NUM_ELEMENTS 크기로 생성)
    int hostInput[NUM_ELEMENTS];
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        hostInput[i] = i;  // 단순히 인덱스 값 할당
    }

    // GPU 메모리 할당
    cudaMalloc((void **)&deviceInput, NUM_ELEMENTS * sizeof(int));
    cudaMalloc((void **)&deviceOutput, NUM_TO_STORE3 * sizeof(int));

    // 호스트 데이터를 장치 메모리로 복사
    cudaMemcpy(deviceInput, hostInput, NUM_ELEMENTS * sizeof(int), cudaMemcpyHostToDevice);

    // 커널 구성
    int blockSize = 256;  // 블록당 스레드 수
    int gridSize = (NUM_ELEMENTS + blockSize - 1) / blockSize;  // 필요한 그리드 크기 계산
    size_t sharedMemSize = NUM_ELEMENTS * sizeof(int);  // 동적 공유 메모리 크기 설정

    // 커널 실행
    load_and_store<<<gridSize, blockSize, sharedMemSize>>>(deviceInput, deviceOutput, NUM_ELEMENTS, NUM_TO_STORE3);
    cudaDeviceSynchronize();

    // GPU 메모리 해제
    cudaFree(deviceInput);
    cudaFree(deviceOutput);
}


void executeLoadAndStore4() {
    int *deviceInput, *deviceOutput;

    // 호스트 데이터 초기화 (NUM_ELEMENTS 크기로 생성)
    int hostInput[NUM_ELEMENTS];
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        hostInput[i] = i;  // 단순히 인덱스 값 할당
    }

    // GPU 메모리 할당
    cudaMalloc((void **)&deviceInput, NUM_ELEMENTS * sizeof(int));
    cudaMalloc((void **)&deviceOutput, NUM_TO_STORE4 * sizeof(int));

    // 호스트 데이터를 장치 메모리로 복사
    cudaMemcpy(deviceInput, hostInput, NUM_ELEMENTS * sizeof(int), cudaMemcpyHostToDevice);

    // 커널 구성
    int blockSize = 256;  // 블록당 스레드 수
    int gridSize = (NUM_ELEMENTS + blockSize - 1) / blockSize;  // 필요한 그리드 크기 계산
    size_t sharedMemSize = NUM_ELEMENTS * sizeof(int);  // 동적 공유 메모리 크기 설정

    // 커널 실행
    load_and_store<<<gridSize, blockSize, sharedMemSize>>>(deviceInput, deviceOutput, NUM_ELEMENTS, NUM_TO_STORE4);
    cudaDeviceSynchronize();

    // GPU 메모리 해제
    cudaFree(deviceInput);
    cudaFree(deviceOutput);
}


#endif