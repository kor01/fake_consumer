import tensorflow as tf
from tensorflow.python.platform import resource_loader

_fc_so = tf.load_op_library(
  resource_loader.get_path_to_datafile('_fake_consumer_ops.so'))


def consume(x):
  _fc_so.fake_consumer(x).numpy()
  return x


__all__ = ['consume']
