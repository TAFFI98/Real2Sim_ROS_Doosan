import pickle
import numpy as np
import matplotlib.pyplot as plt
from ProMP import ProMP,ProMPTuner


# ----------- Import position and orientation trajectories -----#
with open('/root/catkin_ws/MP/MP.txt', 'rb') as handle_1:
    data = handle_1.read()

data = pickle.loads(data,encoding='latin1')
position = np.array(data['pos'])
orientation = np.array(data['ori'])


nt = position.shape[0]
X_coord = position[:,0]
Y_coord = position[:,1]
angle = orientation[:,0]


# ----------- Plot original trajectories --------- #

# fig, axarr = plt.subplots(1, 3, figsize=(8, 3))
# axarr[0].tick_params(axis='both', labelsize=5)
# axarr[1].tick_params(axis='both', labelsize=5)
# axarr[2].tick_params(axis='both', labelsize=5)
# fig.suptitle('X,Y,angle before MP ', fontweight="bold")
# plt.sca(axarr[0])
# plt.plot(X_coord, 'c', label='X', linewidth=1.5)
# plt.legend(loc=1, fontsize='x-small')
# plt.grid()
# plt.sca(axarr[1])
# plt.plot(Y_coord, 'c', label='Y', linewidth=1.5)
# plt.legend(loc=1, fontsize='x-small')
# plt.grid()
# plt.sca(axarr[2])
# plt.plot(angle, 'c', label='angle', linewidth=1.5)
# plt.legend(loc=1, fontsize='x-small')
# plt.grid()
#plt.show()




# ----------- MP TUNER --------- #

N_T = nt
N_DOF = 1
N_BASIS = 10
promp = ProMP(N_BASIS, N_DOF, N_T)

print(' Tuner X coordinate')
promp_tuner = ProMPTuner(np.expand_dims(np.expand_dims(X_coord, axis = 0).T, axis=0), promp)
promp_tuner.tune_n_basis(min=2, max=20, step=1)
N_BASIS_X = 9 

print(' Tuner Y coordinate')
promp_tuner = ProMPTuner(np.expand_dims(np.expand_dims(Y_coord, axis = 0).T, axis=0), promp)
promp_tuner.tune_n_basis(min=2, max=20, step=1)
N_BASIS_Y = 10

print(' Tuner angle coordinate')
promp_tuner = ProMPTuner(np.expand_dims(np.expand_dims(angle, axis = 0).T, axis=0), promp)
promp_tuner.tune_n_basis(min=2, max=20, step=1)
N_BASIS_angle = 17

# ----------- MP fit  --------- #

# Compute ProMP weights and reconstruct the trajectory : X
promp_X = ProMP(N_BASIS_X, N_DOF, N_T)
weights_X = promp_X.weights_from_trajectory(np.expand_dims(X_coord, axis = 0).T)
X_coord_MP = promp_X.trajectory_from_weights(weights_X)

# Compute ProMP weights and reconstruct the trajectory : Y
promp_Y = ProMP(N_BASIS_Y, N_DOF, N_T)
weights_Y = promp_Y.weights_from_trajectory(np.expand_dims(Y_coord, axis = 0).T)
Y_coord_MP = promp_Y.trajectory_from_weights(weights_Y)

# Compute ProMP weights and reconstruct the trajectory : angle
promp_angle = ProMP(N_BASIS_angle, N_DOF, N_T)
weights_angle = promp_angle.weights_from_trajectory(np.expand_dims(angle, axis = 0).T)
angle_MP = promp_angle.trajectory_from_weights(weights_angle)

# ----------- MP original and reconstructed Plot  --------- #

fig, axarr = plt.subplots(1, 3, figsize=(8, 3))
axarr[0].tick_params(axis='both', labelsize=5)
axarr[1].tick_params(axis='both', labelsize=5)
axarr[2].tick_params(axis='both', labelsize=5)
fig.suptitle('X,Y,angle after MP ', fontweight="bold")

t = np.linspace(0, 200, 200)

plt.sca(axarr[0])
plt.plot(t, X_coord_MP, 'r', label='X MP', linewidth=1.5)
plt.plot(t, X_coord, 'c', label='X', linewidth=1.5)
plt.legend(loc=1, fontsize='x-small')
plt.grid()

plt.sca(axarr[1])
plt.plot(t, Y_coord_MP, 'r', label='Y MP', linewidth=1.5)
plt.plot(t, Y_coord, 'c', label='Y', linewidth=1.5)
plt.legend(loc=1, fontsize='x-small')
plt.grid()

plt.sca(axarr[2])
plt.plot(t, angle_MP, 'r', label='angle MP', linewidth=1.5)
plt.plot(t, angle, 'c', label='angle', linewidth=1.5)
plt.legend(loc=1, fontsize='x-small')
plt.grid()
plt.show()

# ----------- Weights and basis fuctions Plot  --------- #

fig, axarr = plt.subplots(2, 3, figsize=(20, 10))

plt.sca(axarr[0,0])
all_phi_X = promp_X.all_phi()
for i in range(N_BASIS_X):
    plt.plot(t, all_phi_X[:, i])
plt.grid()

plt.sca(axarr[0,1])
all_phi_Y = promp_Y.all_phi()
for i in range(N_BASIS_Y):
     plt.plot(t, all_phi_Y[:, i])
plt.grid()

plt.sca(axarr[0,2])
all_phi_angle = promp_angle.all_phi()
for i in range(N_BASIS_angle):
    plt.plot(t, all_phi_angle[:, i])
plt.grid()

plt.sca(axarr[1,0])
x = np.linspace(1, N_T, num=N_BASIS_X)
plt.bar(x, weights_X, align='center', alpha=0.8, ecolor='red', color=(1, 0, 0, .4), capsize=5)
plt.grid()

plt.sca(axarr[1,1])
x = np.linspace(1, N_T, num=N_BASIS_Y)
plt.bar(x, weights_Y, align='center', alpha=0.8, ecolor='red', color=(1, 0, 0, .4), capsize=5)
plt.grid()


plt.sca(axarr[1,2])
x = np.linspace(1, N_T, num=N_BASIS_angle)
plt.bar(x, weights_angle, align='center', alpha=0.8, ecolor='red', color=(1, 0, 0, .4), capsize=5)
plt.grid()

plt.show()
