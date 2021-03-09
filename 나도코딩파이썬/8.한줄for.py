# 출석번호 앞에 100을 붙임
# student = [1,2,3,4,5]
# student = [i+100 for i in student]
# print(student)

# student = ["iron man","thor","i am groot"]
# student = [len(i) for i in student]
# print(student)

# student = ["iron man","thor","i am groot"]
# student = [i.upper() for i in student]
# print(student)

from random import*
cnt = 0
for i in range(1,51):
    t = randrange(1,51)
    if t >=5 and t <=15:
        print("[O] {}번째 손님 (소요시간 : {} 분)".format(i,t))
        cnt+=1
    else:
        print("[ ] {}번째 손님 (소요시간 : {} 분)".format(i,t))

print("총 탑승 승객 : {} 분".format(cnt))
