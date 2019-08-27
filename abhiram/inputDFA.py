from pyautogui import press,typewrite
import time
time.sleep(5)
f=open("dfa","r");
data=f.read().split("\n")
for i in data:
    pyautogui.typewrite(i)
    pyautogui.press("enter")