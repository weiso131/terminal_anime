
import cv2
import os
from pathlib import Path


def turn_img_to_txt(img_path, fx= 0.06, fy = 0.03):
    
    img_txt = ""
    
    img = cv2.imread(img_path)
    img = cv2.resize(img,None,fx = fx,fy = fy,interpolation=cv2.INTER_LINEAR)
    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    
    width = img.shape[0] 
    height = img.shape[1] 
    
    #print(img.shape)
    for i in range(width):
        for j in range(height):
            if (img[i][j] <= 128):
                img_txt += " "
            else:
                img_txt += "#"
        img_txt += "\n"
    
    return img_txt

txt_dir_path = "txt/"
img_dir_path = "img/"
list_dir = os.listdir(img_dir_path)

for path in list_dir:
    img_txt = turn_img_to_txt(img_dir_path + path, fx = 0.25, fy = 0.125)
    
    
    
    txt_path = txt_dir_path + path[:-3] + "txt"
    #print(txt_path)
    
    Path.touch(Path(txt_path), exist_ok = True)
    
    print(img_txt)
    
    file = open(txt_path, "w")
    file.write(img_txt)
    file.close()

    

"""
with open(path, "r") as file:
    text = file.read()
"""


"""
cv2.imshow(img_path, img)
cv2.waitKey(0)
"""








"""
import time
for i in range(100):
    print(i, "\r", end = "");
    time.sleep(1)
"""
