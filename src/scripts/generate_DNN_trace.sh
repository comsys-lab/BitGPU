# # DNN model trace
BENCHMARK="bert_inference"
BIN_FILE="bert_inference.py"

#################################

_BENCHMARK=${1:-${BENCHMARK}}
_BIN_FILE=${2:-${BIN_FILE}}

cd /workspace/accel-sim-dev

TRACE_FILE="/workspace/results/traces/${_BENCHMARK}"

export CUDA_VERSION="11.7"
export CUDA_VISIBLE_DEVICES=0
export TOOL_VERBOSE=1
export DYNAMIC_KERNEL_LIMIT_START=9
export DYNAMIC_KERNEL_LIMIT_END=43
rm -rf ./traces/*

# Generate Trace
if [[ $_BIN_FILE == *.py ]]; then
  PYTHON3="python3"
else
  PYTHON3=""
fi
LD_PRELOAD=util/tracer_nvbit/tracer_tool/tracer_tool.so ${PYTHON3} /workspace/workloads/$_BIN_FILE

# Post Processing
util/tracer_nvbit/tracer_tool/traces-processing/post-traces-processing ./traces/kernelslist

# Copy to tc_gem/traces
mkdir -p $TRACE_FILE
rm -rf ${TRACE_FILE}/*
cp traces/* $TRACE_FILE

rm -rf ./traces/*