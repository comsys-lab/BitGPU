#include "tensor_lat_half.h"
#include "load_and_store.h"

int main() {

  intilizeDeviceProp(0);

  if (deviceProp.major < 6) // tesnore unit was added since Volta
    return 1;

  // std::cout << "FP16 operand, FP32 accumalte:\n";
  // tensor_lat<half, float>();

  executeLoadAndStore1();
  executeLoadAndStore2();
  executeLoadAndStore3();
  executeLoadAndStore4();

  std::cout << "\nFP16 operand, FP16 accumalte:\n";
  tensor_lat<half, half>();

  // tensor_lat<char,int>();

  return 1;
}
