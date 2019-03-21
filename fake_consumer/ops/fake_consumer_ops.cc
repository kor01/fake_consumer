#include "tensorflow/core/framework/op.h"
#include "tensorflow/core/framework/shape_inference.h"
#include "tensorflow/core/framework/op_kernel.h"
#include "tensorflow/core/framework/register_types.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"


namespace tensorflow {

using CPUDevice = Eigen::ThreadPoolDevice;
using GPUDevice = Eigen::GpuDevice;

using ::tensorflow::shape_inference::InferenceContext;
using ::tensorflow::shape_inference::ShapeHandle;

REGISTER_OP("FakeConsumer")
    .Input("data: T")
    .Output("output: bool")
    .Attr("T: {int32, half, bfloat16, float, double}")
    .Doc(R"doc(FakeConsumer op.)doc");


class FakeConsumerOp : public ::tensorflow::OpKernel {
 public:
  explicit FakeConsumerOp(::tensorflow::OpKernelConstruction* context)
      : ::tensorflow::OpKernel(context) {}

  void Compute(::tensorflow::OpKernelContext* ctx) override {
    ::tensorflow::TensorShape output_shape = {};
    ::tensorflow::Tensor* output = nullptr;
    OP_REQUIRES_OK(ctx, ctx->allocate_output(0, output_shape, &output));
  }

 private:
  TF_DISALLOW_COPY_AND_ASSIGN(FakeConsumerOp);
};

#define REGISTER(TYPE)                                                     \
  REGISTER_KERNEL_BUILDER(                                                 \
      Name("FakeConsumer").Device(DEVICE_CPU).TypeConstraint<TYPE>("T"),   \
      FakeConsumerOp);                                                     \

TF_CALL_ALL_TYPES(REGISTER);
#undef REGISTER

#if GOOGLE_CUDA
#define REGISTER(TYPE)                                                     \
  REGISTER_KERNEL_BUILDER(                                                 \
      Name("FakeConsumer").Device(DEVICE_GPU).TypeConstraint<TYPE>("T"),   \
      FakeConsumerOp)

TF_CALL_ALL_TYPES(REGISTER);
#undef REGISTER
#endif  // GOOGLE_CUDA

}
