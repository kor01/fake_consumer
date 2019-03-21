## Fake Consumer

eliminate lazy behavior in tensorflow eager execution

#

### code example:

```python

import time
import tensorflow as tf
from fake_consumer import *

# make sure random test data generated before profiling
image = consume(tf.random.normal((2, 1024, 1024, 64)))
coord = consume(tf.random.uniform((2, 1024, 1024, 2)) * (1024 - 1))

start = time.time()

# make sure all computations in my_complex_function are executed 
_ = consume(my_complex_function(image, coord))

print('time usage: ', time.time() - start)

```

