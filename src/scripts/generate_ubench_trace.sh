BENCHMARK="tensor_lat_half_3_case4"
BIN_FILE="workloads/tensor_lat_half/tensor_lat_half"

#################################

cd ..

TRACE_FILE="/workspace/results/traces/${BENCHMARK}"

export CUDA_VERSION="11.7"
export CUDA_VISIBLE_DEVICES=0

# Generate Trace
LD_PRELOAD=accel-sim-dev/util/tracer_nvbit/tracer_tool/tracer_tool.so $BIN_FILE

# Post Processing
accel-sim-dev/util/tracer_nvbit/tracer_tool/traces-processing/post-traces-processing ./traces/kernelslist

# Copy to tc_gem/traces
mkdir -p $TRACE_FILE
cp traces/* $TRACE_FILE