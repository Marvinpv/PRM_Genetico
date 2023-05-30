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
    
    #groups[i-4] = map(int,groups[i-4])


im = plt.imread('maps/room1.pgm')
implot = plt.imshow(im)
for i in range(n_groups):
    print('Grupo',i,':',groups[i])
    color = np.random.rand()
    plt.scatter(points_x[groups[i]],points_y[groups[i]],label='Group '+str(i))

plt.legend()
plt.show()