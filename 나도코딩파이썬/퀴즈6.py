def std_weight(height,gender):
    if gender == "남자":
        weight = height*height*22/10000
        return weight
    else:
        weight = height*height*21/10000
        return weight

height = int(input("키를 입력 : "))
gender = input("성별을 입력 : ")
weight = round(std_weight(height,gender),2) #반올림 함수 round
print("키 {} {}의 표준 체중은 {}kg 입니다.".format(height,gender,weight))
    