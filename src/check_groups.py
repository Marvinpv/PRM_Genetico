import sys
import math
import matplotlib.pyplot as plt
import numpy as np

points_x = np.array(list(sys.argv[1].split(',')[:-1]),dtype=int)
points_y = np.array(list(sys.argv[2].split(',')[:-1]),dtype=int)

print('Points x:',points_x)
print('Points y:',points_y)
n_groups = int(sys.argv[3])

groups = []
for i in range(4,4+n_groups):

    groups.append(np.array(list(sys.argv[i].split(','))[:-1],dtype=int))

connective = np.array([])
print('Connective:',sys.argv[n_groups + 4])
if sys.argv[n_groups + 4] != "None":
    connective = np.array(list(sys.argv[n_groups + 4].split(',')[:-1]),dtype=int)

connections = np.array([])
if sys.argv[n_groups + 5] != "None":
    connections = np.array(list(sys.argv[n_groups + 5].split(',')[:-1]),dtype=int)
    connections = np.reshape(connections,(connections.size//2,2))

im = plt.imread('../maps/room2_inflated.pgm')
implot = plt.imshow(im)
for i in range(n_groups):
    print('Grupo',i,':',groups[i])
    color = np.random.rand()
    plt.scatter(points_y[groups[i]],points_x[groups[i]],label='Group '+str(i))
    
if connective.size > 0:
    plt.scatter(points_y[connective],points_x[connective],label='Connective')

for i in range(connections.shape[0]):
    y_values = [points_y[connections[i,0]],points_y[connections[i,1]]]
    x_values = [points_x[connections[i,0]],points_x[connections[i,1]]]
    plt.plot(y_values,x_values,linestyle='--')

plt.legend()
plt.show()