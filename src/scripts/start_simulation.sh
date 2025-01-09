PLATFORM=A100
BENCHMARK1="vit_inference"
cd ..

TRACE_FILE="/workspace/results/traces/${BENCHMARK1}/kernelslist.g"
GPGPUSIM_CONFIG_FILE="./accel-sim-dev/gpu-simulator/gpgpu-sim/configs/tested-cfgs/${PLATFORM}/gpgpusim.config"
TRACE_CONFIG_FILE="./accel-sim-dev/gpu-simulator/configs/tested-cfgs/${PLATFORM}/trace.config"
RESULT_DIR="/workspace/results/simulation_results/${PLATFORM}/vit_inference_power"

mkdir -p $RESULT_DIR

source ./accel-sim-dev/gpu-simulator/setup_environment.sh
./accel-sim-dev/gpu-simulator/bin/release/accel-sim.out \
    -trace $TRACE_FILE \
    -config $GPGPUSIM_CONFIG_FILE \
    -config $TRACE_CONFIG_FILE > "${RESULT_DIR}/vit_inference_power.txt"

# PLATFORM=A100
# BENCHMARK1="tensor_lat_half_3_case4"
# cd ..

# TRACE_FILE="/workspace/results/traces/${BENCHMARK1}/kernelslist.g"
# GPGPUSIM_CONFIG_FILE="./accel-sim-dev/gpu-simulator/gpgpu-sim/configs/tested-cfgs/${PLATFORM}/Case1/gpgpusim.config"
# TRACE_CONFIG_FILE="./accel-sim-dev/gpu-simulator/configs/tested-cfgs/${PLATFORM}/Case1/trace.config"
# RESULT_DIR="/workspace/results/simulation_results/${PLATFORM}/Case4_power"

# mkdir -p $RESULT_DIR

# source ./accel-sim-dev/gpu-simulator/setup_environment.sh
# ./accel-sim-dev/gpu-simulator/bin/release/accel-sim.out \
#     -trace $TRACE_FILE \
#     -config $GPGPUSIM_CONFIG_FILE \
#     -config $TRACE_CONFIG_FILE > "${RESULT_DIR}/Case4.txt"
