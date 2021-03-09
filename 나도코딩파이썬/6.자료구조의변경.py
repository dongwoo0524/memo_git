# menu = {"커피","우유","주스"} #집합
# print(menu,type(menu))

# menu = list(menu) #리스트
# print(menu,type(menu))


from random import*
lst = range(1,21)
lst = list(lst)

shuffle(lst)
# print(lst)
# print(sample(lst,1))

sel = list(sample(lst,4))
print(sel)

print('''---당첨자 발표---
치킨 당첨자 : {}
커피 당첨자 : {}
---축하합니다---'''.format(sel[0],sel[1:]))