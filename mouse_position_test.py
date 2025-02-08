import pyautogui
import time
import threading
from pynput import keyboard

# global variable
running = True

def on_press(key):
    global running
    print("stop loop")
    running = False
    
# start keyboard listener
listener = keyboard.Listener( on_press = on_press)
listener.start()

# main loop
while running:
    x ,y = pyautogui.position()
    print("(" , x , "," , y, ")")
    time.sleep(1)
    
# stop keyboard listener
listener.stop()
