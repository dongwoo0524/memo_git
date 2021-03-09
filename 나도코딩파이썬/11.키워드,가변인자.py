# def profile(name,age,lang):
#     print(name,age,lang)

# profile(name = "유재석",lang = "파이썬",age = 20)

# def profile(name,age,lang1,lang2,lang3,lang4,lang5):
#     print("이름 : {} 나이 : {} ".format(name,age),end = " ")
#     print(lang1,lang2,lang3,lang4,lang5)

def profile(name,age,*lang):
    print("이름 : {} 나이 : {} ".format(name,age),end = " ")
    for langu in lang:
        print(langu,end=" ")
    print()
profile("유재석",20,"P","C","V","T","H")
profile("김태호",25,"K","s")