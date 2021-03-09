# for waiting in range(0,5): 
#     print("대기번호 : {}".format(waiting))

# star = ["A","B","C"]
# for customer in star:
#     print("{},커피가 준비되었습니다.".format(customer))

# #while
# customer = "A"
# index = 5
# while index >=1:
#     print("{}, 커피가 준비되었습니다.{} 번 남았어요.".format(customer,index))
#     index -=1
#     if index==0:
#         print("커피는 폐기되었습니다.")

# customer = "Q"
# index = 0
# while True:
#     print("{}, 커피가 준비되었습니다.{} 번 남았어요.".format(customer,index))
#     index +=1

# customer = "Q"
# person = "Unknown"

# while person != customer:
#     print("{}, 커피가 준비되었습니다.".format(customer))
#     person = input("이름이?")

absent = [2,5]
nobook = [7]
for student in range(1,11):
    if student in absent:
        continue
    elif student in nobook:
        print("오늘수업 여기까지, {} 따라ㅏ와".format(student))
        break
    print("{}, 일어나".format(student))