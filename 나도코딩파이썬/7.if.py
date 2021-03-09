# weather = input("오늘 날씨는 어때요? ")
# if weather=="비" or weather == "눈":
#     print("우산을 챙기세요")
# elif weather == "미세먼지":
#     print("마스크를 챙기세요")
# else:
#     print("준비물이 필요업어요")

temp  = int(input("기온은 어때요 ? "))
if temp >=30:
    print("너무 더워요")
elif temp>=10 and temp <=29:
    print("딱 좋아요")
elif temp >=0 and temp <=9:
    print("조금 쌀쌀")
else :
    print("넘 추움")