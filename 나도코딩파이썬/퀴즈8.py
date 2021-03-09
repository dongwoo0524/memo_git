# 출력 예제
# 총 3대의 매물
# 강남 아파트 매매 10억 2010년
# 마포 오피스텔 전세 5억 2007년
# 송파 빌라 월세 500/50 2000년

class House:
    def __init__(self,location,house_type,deal_type,price,year):
        self.location = location
        self.house_type = house_type
        self.deal_type = deal_type
        self.price = price
        self.year = year

    def show(self):
        print("{} {} {} {} {}년 ".format(self.location,\
            self.house_type,self.deal_type,self.price,self.year))

cases = []

case1 = House("강남","아파트","매매","10억","2010")
case2 = House("마포","오피스텔","전세","5억","2007")
cases.append(case1)
cases.append(case2)

for case in cases:
    case.show()

# case1.show()
# case2.show()