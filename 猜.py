# -*- coding:utf-8 -*-
import random
#随机生成一个1~10的数字
secret = random.randint(1,10)
print('---------i am yu--------')
temp = input("不防猜一猜我现在心里想的是哪个数字：")
guess = int(temp)
while guess != secret:
    temp = input("哎呀，猜错啦，重新猜吧~~")
    guess = int(temp)
    if guess == secret:
        print("呀，你是我心里的蛔虫吗？！")
        print("哼，猜中了也没有奖励！")

    else:
        if guess > secret:
            print("嘿，数字猜大了！")
        else:
            print("嘿，数字猜小啦！")
print("游戏结束，不玩啦O(∩_∩)O")
