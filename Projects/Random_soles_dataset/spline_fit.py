# Import packages
import numpy as np
import nurbspy as nrb
import matplotlib.pyplot as plt
import os
import pickle
from pyquaternion import Quaternion

def get_immediate_filesNames(a_dir, extension:bool=1):
    if extension == 0:
        return [name.split('.')[0] for name in os.listdir(a_dir)
            if os.path.isfile(os.path.join(a_dir, name))]
    else:
        return [name for name in os.listdir(a_dir)
            if os.path.isfile(os.path.join(a_dir, name))]




if __name__ == '__main__':

    path = '/home/taffi/Desktop/Random_soles_dataset/coordinate_bave/'
    files = get_immediate_filesNames(path)
    for file in files:
        with open(path + file) as f:
            list_rows = f.readlines()
            n_points = np. shape(list_rows)[0] 
            # Define the array of control points
            P = np.zeros((2,n_points))
            # Maximum index of the control points (counting from zero)
            n = np.shape(P)[1] - 1
            # Define the array of control point weights
            W = np.zeros((n_points))



            for i in range(n_points):
                X = np.single(list_rows[i].split('\t')[0])
                Y = np.single(list_rows[i].split('\t')[1])
                P[:, i] = [X,Y]
                W [i] = 1

            # Define the order of the basis polynomials
            # Linear (p = 1), Quadratic (p = 2), Cubic (p = 3), etc.
            # Set p = n (number of control points minus one) to obtain a Bezier
            p = 2

            # Define the knot vector (clamped spline)
            # p+1 zeros, n-p equispaced points between 0 and 1, and p+1 ones. In total r+1 points where r=n+p+1
            U = np.concatenate((np.zeros(p), np.linspace(0, 1, n - p + 2), np.ones(p)))

            # Create and plot the NURBS curve
            fig = plt.figure(figsize=(6, 5))
            ax = fig.add_subplot(111)
            ax.set_title(file.strip('.txt'))
            ax.set_xlabel('X')
            ax.set_ylabel('Y')

            # Define a u-parametrization suitable for finite differences
            h = 1e-4
            hh = 2*(h + h**2)
            Nu = 200
            u = np.linspace(0.00+hh, 1.00-hh, Nu)
            nurbs2D = nrb.NurbsCurve(control_points=P, weights=W, degree=p, knots=U)

            # Compute the NURBS derivatives analytically
            position = np.single(nurbs2D.get_value(u))
            tangent = np.single(nurbs2D.get_tangent(u))
            normal = np.single(nurbs2D.get_normal(u))

            nurbs2D.plot(fig=fig, ax=ax,curve=True, control_points=True, frenet_serret=False, axis_off=False, ticks_off=False)
            # Plot the tangent vector ---- X, Y define the arrow locations, U, V define the arrow directions
            x, y = position
            tx, ty = tangent
            # Plot the normal vector ---- X, Y define the arrow locations, U, V define the arrow directions
            nx, ny = normal
            
            
            tx_final, ty_final, nx_final, ny_final  = np.empty_like(tx), np.empty_like(ty), np.empty_like(nx), np.empty_like(ny)

            for i in range(tx.shape[0]):
                t = np.array([tx[i] , ty[i] , 0])
                n = np.array([nx[i] , ny[i] , 0])
                z = np.cross(t,n)
                if z[-1] > 0:
                    ax.quiver(x[i], y[i], tx[i], ty[i], color='red', scale=4)
                    ax.quiver(x[i], y[i], nx[i], ny[i], color='blue', scale=4)
                    # R = np.column_stack((t, n, z))
                    # q8d = Quaternion(matrix=R)
                    # print(q8d.rotation_matrix)
                    tx_final[i] = tx[i]
                    ty_final[i] = ty[i]
                    nx_final[i] = nx[i]
                    ny_final[i] = ny[i]


                if z[-1] < 0:  
                    ax.quiver(x[i], y[i], tx[i], ty[i], color='red', scale=5)
                    ax.quiver(x[i], y[i], -nx[i], -ny[i], color='blue', scale=5)                 
                    # R = np.column_stack((t, -n, -z))
                    # q8d = Quaternion(matrix=R)
                    # print(q8d.rotation_matrix)
                    tx_final[i] = tx[i]
                    ty_final[i] = ty[i]
                    nx_final[i] = -nx[i]
                    ny_final[i] = -ny[i]




            # Plot the origin of the vectors
            x, y = position
            points, = ax.plot(x, y)
            points.set_linestyle(' ')
            points.set_marker('.')
            points.set_markersize(5)
            points.set_markeredgewidth(0.25)
            points.set_markeredgecolor('k')
            points.set_markerfacecolor('w')
            points.set_zorder(4)


            # Save figures of burrs
            #plt.show()
            plt.savefig(path+'img/'+file.strip('.IGS.txt')+'.png')

            # Save annotations of ox, oy, tx, ty, nx, ny

            deltax = np.single(x[1:] - x[0]* np.ones((np.shape(x[1:]))))
            deltay = np.single(y[1:] - y[0]* np.ones((np.shape(x[1:]))))

            dictionary = {
            "OX":  x[0],
            "OY":  y[0],
            "deltaX":  deltax,
            "deltaY":  deltay,
            "tx":  np.single(tx_final),
            "ty":  np.single(ty_final),
            "nx":  np.single(nx_final),
            "ny":  np.single(ny_final)
            }
            file_PY3 = open(path+'annotations_PY3/'+file, "wb") 
            file_PY2 = open(path+'annotations_PY2/'+file, "wb") 

            pickle.dump(dictionary, file_PY3)               # Dump python3 
            pickle.dump(dictionary, file_PY2, protocol=2)   # Dump python2
            file_PY3.close()
            file_PY2.close()

