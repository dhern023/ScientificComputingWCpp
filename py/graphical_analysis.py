# -*- coding: utf-8 -*-
"""
Created on Sat Oct 24 18:01:33 2020

@author: Diana
"""

import matplotlib.pyplot as plt
import numpy

def generate_orbit_coordinates(function, seed):
    X = [seed]
    Y = [seed]
    for i in range(10):
        x = seed
        y = function(seed)
        X.append(x)
        X.append(y)        
        Y.append(y)
        Y.append(y)
        seed = y
    return X,Y

def plot_x_equals_y():
    x = numpy.linspace(start = -2, stop = 2)
    y = x
    plt.plot(x,y)
    return


f = {'linear': [lambda x: -x + 1/4, [0.5]],
     'sqrt': [numpy.sqrt, [0.5, 2]],
     'cos' : [numpy.cos, [0.01, 2]],
     'rational' : [lambda x: 1/(3*x), [0.05, -5]],
     'even' : [lambda x: x**2, [0.9, 1.001]],
     'poly' : [lambda x: x-x**2, [-0.12, 0.5]]
     }

key = 'poly'
points = generate_orbit_coordinates(f[key][0], f[key][1][0])
points2 = generate_orbit_coordinates(f[key][0], f[key][1][1])
codomain = numpy.linspace(start = -0.5, stop = 2, num = 50)
outputs = f[key][0](codomain)

plot_x_equals_y()
plt.plot(codomain, outputs)
plt.plot(points[0],points[1])
plt.plot(points2[0],points2[1])
