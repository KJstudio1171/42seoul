import turtle as t
import random
t.bgcolor("lavender")
t.title("가위바위보 게임")
t.ht()
t.up()
li = ["arrow","circle","square"]

def com_choice():
    rand_choice = random.randint(0,2)
    com_shape(li[rand_choice])

def com_shape(n):
    com.shape(n)

def rock():
    user.shape("arrow")

def scissors():
    user.shape("circle")

def paper():
    user.shape("square")

user = t.Turtle()
user.up()
user.speed(0)
user.goto(-200,200)
user.shape("turtle")
user.write("나의 선택", False, "center", ("", 30))
user.goto(-200,-100)

com = t.Turtle()
com.up()
com.speed(0)
com.goto(200,200)
com.shape("turtle")
com.write("컴퓨터 선택", False, "center", ("", 30))
com.goto(200,-100)

t.listen()
t.onkey(rock,"1")
t.onkey(scissors,"2")
t.onkey(paper,"3")

t.mainloop()