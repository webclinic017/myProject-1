import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf
from sklearn.datasets import load_iris

x_data = load_iris().data
y_data = load_iris().target

np.random.seed(116)
np.random.shuffle(x_data)
np.random.seed(116)
np.random.shuffle(y_data)
# tf.random.set_seed(116)

x_train = x_data[:-30]
y_train = y_data[:-30]
x_test  = x_data[-30:]
y_test  = y_data[-30:]

x_train = tf.cast(x_train, tf.float32)
x_test  = tf.cast(x_test, tf.float32)

train_db = tf.data.Dataset.from_tensor_slices((x_train, y_train)).batch(32)
test_db = tf.data.Dataset.from_tensor_slices((x_test, y_test)).batch(32)

r = 0.1
loss4 = 0
epochs = 500
loss_list = []
acc_list = []

w = tf.Variable(tf.random.truncated_normal([4, 3], stddev=0.1))
b = tf.Variable(tf.random.truncated_normal([3], stddev=0.1))

for epoch in range(epochs):
    for step, (x_train, y_train) in enumerate(train_db):
        with tf.GradientTape() as tape:
            y1 = tf.matmul(x_train, w) + b
            y1 = tf.nn.softmax(y1)
            y2 = tf.one_hot(y_train, depth=3)
            loss = tf.reduce_mean(tf.square(y1 - y2))
            loss4 = loss4 + loss.numpy()
        dloss_dw, dloss_db = tape.gradient(loss, [w, b])
        w.assign_sub(r * dloss_dw)
        b.assign_sub(r * dloss_db)

    print('目前步数：第{}大步。\n本步的均方误差：{}'.format(epoch, loss4/4))
    loss_list.append(loss4/4)
    loss4 = 0

    total_right = 0
    total_number = 0
    for x_test, y_test in test_db:
        y1 = tf.matmul(x_test, w) + b
        y1 = tf.nn.softmax(y1)
        y1_max = tf.argmax(y1, axis=1)
        y2 = y_test
        y1 = tf.cast(y1_max, dtype=y2.dtype)

        compare_TF = tf.equal(y1, y2)
        compare_int = tf.cast(compare_TF, dtype=tf.int32)
        right_count = int(tf.reduce_sum(compare_int))
        total_right = total_right + right_count
        total_number = total_number + y_test.shape[0]
    acc = total_right / total_number
    print('本大步预测正确率为：{}\n======================='.format(acc))
    acc_list.append(acc)

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
fig = plt.figure('误差&准确率变化曲线')
ax1 = fig.add_axes([0.1, 0.1, 0.8, 0.8])
ax2 = ax1.twinx()

x = np.arange(1, epochs+1)
y1 = loss_list
y2 = acc_list

l1, = ax1.plot(x, y1, 'r', label='loss')
l2, = ax2.plot(x, y2, 'b', label='acc')
ax1.set_xlabel('步数')
ax1.set_ylabel('误差', color='r')
ax2.set_ylabel('准确率', color='b')
plt.legend(handles=[l1, l2, ], labels=['误差', '正确率'], loc='best')
plt.title('误差&准确率变化,修正率:{}'.format(r))
plt.show()

print(w)
print('--------------------------------')
print(b)