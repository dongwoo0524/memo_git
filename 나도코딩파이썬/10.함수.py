# def open_account():
#     print("새로운 계좌가 생성되었습니다.")

# def deposit(balance,money):
#     print("입금이 완료되었습니다. 잔액은 {} 원 입니다.".format(balance+money))
#     return balance+money

# def withdraw(balance,money):
#     if balance< money:
#         print("출금이 불가능 합니다. 잔액은 {} 원 입니다.".format(balance))
#         return balance
#     else:
#         print("출금이 완료되었습니다. 잔액은 {} 원 입니다.".format(balance - money))
#         return balance - money
# def withdraw_night(balance,money):
#     commission = 100
#     return commission,balance - money - commission
# balance = 0
# balance = deposit(balance,1000)
# print(balance)
# balance = withdraw(balance,4000)
# commission,balance = withdraw_night(balance,500)
# print("수수료 {} 원, 잔액은 {} 원 입니다.".format(commission,balance))

# def profile(name,age,lang):
#     print("이름 : {}\t나이 : {}\t주 사용 언어 : {}".\
#         format(name,age,lang))

# profile("유재석",20,"python")

#같은 학교 같은 학년 같은 반 같은 수업

# def profile(name,age=17,lang):
#     print("이름 : {}\t나이 : {}\t주 사용 언어 : {}".\
#         format(name,age,lang))
