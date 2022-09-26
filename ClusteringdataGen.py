import numpy as np
import matplotlib.pyplot as plt

num_points=10
coords_x=np.random.randint(0,50,num_points)
coords_y=np.random.randint(0,50,num_points)

xm=np.average(coords_x)
ym=np.average(coords_y)

#d1=((coords_x-xm)**2+(coords_y-ym)**2)**0.5
print(coords_x)
print(coords_y)


