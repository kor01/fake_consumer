#! /bin/bash

TF_LFLAGS=( $(python -c 'import tensorflow as tf; print(" ".join(tf.sysconfig.get_link_flags()))') )
TF_CFLAGS=( $(python -c 'import tensorflow as tf; print(" ".join(tf.sysconfig.get_compile_flags()))') )

g++-4.8 -std=c++11 -Ofast -shared -DGOOGLE_CUDA -o _fake_consumer_ops.so \
    fake_consumer/ops/fake_consumer_ops.cc \
     ${TF_CFLAGS[@]} -I./ \
    -fPIC -L/usr/local/cuda/lib64/ ${TF_LFLAGS[@]}

mv _fake_consumer_ops.so fake_consumer/python/
