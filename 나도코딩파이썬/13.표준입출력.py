# import sys
# print("Python","Java",file = sys.stdout)
# print("Python","Java",file = sys.stderr)

# scores = {"수학":0,"영어" : 50,"코딩": 100}
# for subject,score in scores.items():
#     print(subject.ljust(8),str(score).rjust(4),sep = ":") # ljust : 왼쪽 정렬

# for num in range(1,21):
#     print("대기번호 : "+str(num).zfill(3).rjust(4))

# answer = input("아무 값이나 입력 : ")
# print("입력하신 값은 {} 입니다.".format(answer))



#빈 자리는 빈고가느로 두고, 오른쪽 정려를 하되, 총 10자리 공간을 확보
print("{0:>10}".format(500))

#양수일 땐 + 로, 음수일땐 -
print("{0:>+10}".format(500))
print("{0:>+10}".format(-500))

#왼쪽 정렬하고, 빈칸으로 _로 채움
print("{0:_<+10}".format(500))

# 3자리 마다 콤마를 찍어주기
print("{0:,}".format(1000000000000))

# 3자리 마다 콤마를 찍어주기 + - 
print("{0:+,}".format(1000000000000))

# 3자리 마다 콤마를 찍고, 부호도 붙이고, 자릿수 확보
print("{0:^<+30,}".format(1000000000000000))

# 소수점 출력
print("{0:f}".format(5/3))

# 소수점을 특정 자리까지만
print("{0:.2f}".format(5/3))