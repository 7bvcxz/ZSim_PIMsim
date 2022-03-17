from __future__ import print_function

import tensorflow as tf

print("0")
matrix1 = tf.constant([[3., 3.]])
print("1")
matrix2 = tf.constant([[2.],[2.]])
print("2")

product = tf.matmul(matrix1, matrix2)
print("3")

with tf.Session() as sess:
    result = sess.run(product)
    print("kkmkkmkkmkkmkkmkkmkkmkkmkkmkkmkkmkkmkkmkkmkkmkkmkkmkkm")
    print(result)
    # ==> [[ 12.]]