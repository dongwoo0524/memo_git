# 사전{}
cabinet = {3:"유재석",100:"김태호"}
print(cabinet[3])
print(cabinet[100])

print(cabinet.get(3))
print(cabinet.get(5,"사용가능")) #기왕이면 get 함수를 쓰는 것 추천. 프로그램을 이어서 실행 시켜준다.

print(3 in cabinet) #True
print(5 in cabinet) #False

print(cabinet)
cabinet = {"A-3":"유재석","B-100":"김태호"}
cabinet["C-20"] = "조새호"
cabinet["A-3"] = "김종국"
print(cabinet)

# 간 손님
del cabinet["A-3"]
print(cabinet)

#총 사용중인 열쇠들 출력
print(cabinet.keys())

# 값들 만 출력
print(cabinet.values())

#키 와 값 모두 출력
print(cabinet.items())