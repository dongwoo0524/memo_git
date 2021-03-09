# 리스트 []

subway1 = 10
subway2 = 20
subway3 = 30

subway = [10,20,30]
print(subway)

subway = ["유재석","조세호","박명수"]

# 조세호가 몇번쩨 칸에 타고있나.
print(subway.index("조세호"))

#  하하가 다음 정류장에서 탑승
subway.append("하하")
print(subway)

# 정형돈을 유재석 조세호 사이에 탑승
subway.insert(1,"정형돈")
print(subway)

#지하철에 있는 사람을 한 명씩 뒤에서 꺼냄
subway.pop()
print(subway)

# subway.pop()
# print(subway)

# subway.pop()
# print(subway)

#같은 이름의 사람이 몇명 있는지
subway.append("유재석")
print(subway.count("유재석"))

#정렬도 가능
num_list = [5,2,4,3,1]
num_list.sort()
print(num_list)

#뒤집기 가능
num_list.reverse()
print(num_list)

#모두 지우기
# num_list.clear()
print(num_list)

#다양한 자료형과 함께 사용 가능
mix_list = ["조세호",20,True]
print(mix_list)

#리스트 확장
num_list.extend(mix_list)
print(num_list)