#11664
import sys

Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz = map(int, sys.stdin.readline().split())

def cal_triangle(x, y, z):
    a = (x - Cx) ** 2 + (y - Cy) ** 2 + (z - Cz) ** 2
    b = (x - Ax) ** 2 + (y - Ay) ** 2 + (z - Az) ** 2
    c = (Cx - Ax) ** 2 + (Cy - Ay) ** 2 + (Cz - Az) ** 2
    if (a + b > c):
        return -1
    elif (a + b == c):
        return 0
    else:
        return 1

left_x = Ax
left_y = Ay
left_z = Az

right_x = Bx
right_y = By
right_z = Bz

while (True):
    mid_x = (left_x + right_x) / 2
    mid_y = (left_y + right_y) / 2
    mid_z = (left_z + right_z) / 2
    if (abs(left_x - right_x) < 0.00000000001 and abs(left_y - right_y) < 0.00000000001 and abs(left_z - right_z) < 0.00000000001):
        break
    val = cal_triangle(mid_x, mid_y, mid_z)
    if (val == 0):
        right_x = mid_x
        right_y = mid_y
        right_z = mid_z
        break
    if (val > 0): #둔각
        left_x = mid_x
        left_y = mid_y
        left_z = mid_z
    else:
        right_x = mid_x
        right_y = mid_y
        right_z = mid_z
print('%0.10f'%((Cx - right_x) ** 2 + (Cy - right_y) ** 2 + (Cz - right_z) ** 2)**(0.5))

