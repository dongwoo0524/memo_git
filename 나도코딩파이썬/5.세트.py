# 집합(set)
# 중복안됨, 순서 없음
my_set = {1,2,3,3,3}
print(my_set)

java = {"유재석","김태호","양세형"}
python = set(["유재석","박명수"])

# 교집합 (java 와ㅏ python을 모두 할 수 있는 사람)
print(java & python)
print(java.intersection(python))

#합집합
print(java | python)
print(java.union(python))

#차집합
print(java - python)
print(java.difference(python))

#파이썬을 할중 아는 사람 늘어남
python.add("김태호")
print(python)

#java를 까먹음
print(java)
java.remove("김태호")
print(java)