// #include "tensor_lat_half.h"

// int main() {

//   intilizeDeviceProp(0);

//   if (deviceProp.major < 6) // tensor core는 Volta 아키텍처 이상에서만 지원됨
//     return 1;

//   // std::cout << "FP16 operand, FP32 accumulate (kernel1):\n";
//   // tensor_lat_kernel1<half, float>();  // 첫 번째 커널 호출 (tensor_latency_kernel1)

//   std::cout << "\nFP16 operand, FP16 accumulate (kernel2):\n";
//   tensor_lat_kernel2<half, half>();  // 두 번째 커널 호출 (tensor_latency_kernel2)

//   return 0;
// }


#include "tensor_lat_half.h"
#include "load_and_store.h"

int main() {

  intilizeDeviceProp(0);

  if (deviceProp.major < 6) // tesnore unit was added since Volta
    return 1;

  // std::cout << "FP16 operand, FP32 accumalte:\n";
  // tensor_lat<half, float>();

  // executeLoadAndStore();

  std::cout << "\nFP16 operand, FP16 accumalte:\n";

  // // Baseline
  // tensor_lat<half, half>(2048);
  // tensor_lat<half, half>(4096);
  // tensor_lat<half, half>(16384);

  // // Case 1
  // tensor_lat<half, half>(1664);
  // tensor_lat<half, half>(3328);
  // tensor_lat<half, half>(13312);

  // // Case 2
  // tensor_lat<half, half>(1280);
  // tensor_lat<half, half>(2560);
  // tensor_lat<half, half>(10240);
  // tensor_lat<half, half>(1024);
  
  // // Case 3
  // tensor_lat<half, half>(1024);
  // tensor_lat<half, half>(2048);
  // tensor_lat<half, half>(8192);
  
  // Case 4
  tensor_lat<half, half>(640);
  tensor_lat<half, half>(1280);
  tensor_lat<half, half>(5120);

  // tensor_lat<char,int>();

  return 1;
}
