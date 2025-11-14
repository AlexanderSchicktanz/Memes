import os
import sys

import cv2
import numpy as np

try:
    img_file = sys.argv[1]
except:
    print("Error: No image file provided")
    exit()

input = cv2.imread(img_file)  # Reads in BGR format
img = np.asarray(input)


filename = img_file.split(".")[0]
output_full = filename + ".ppm"

if os.path.isfile(output_full):
    os.remove(output_full)

try:
    from tqdm import trange
except:
    trange = lambda *args, leave=None, desc=None: range(*args)

with open(output_full, "w") as matrix:
    matrix.write("P3\n")
    matrix.write(str(len(img[0])))
    matrix.write(" ")
    matrix.write(str(len(img)))
    matrix.write("\n")
    matrix.write("255\n")
    for row in trange(len(img)):
        for pixel in trange(len(img[row]), leave=False, desc="Row " + str(row)):
            # opencv reads in BGR format
            R = img[row][pixel][2]
            G = img[row][pixel][1]
            B = img[row][pixel][0]

            matrix.write(str(R))
            matrix.write(" ")
            matrix.write(str(G))
            matrix.write(" ")
            matrix.write(str(B))
            matrix.write(" ")

        matrix.write("\n")
