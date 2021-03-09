# # 마린 : 공격 유닛, 군인. 총 쏠수 있음

# name = "마린"
# hp = 40
# damage = 5

# print("{} 유닛이 생성되었습니다.".format(name))
# print("체력 {} , 공격력 {} \n".format(hp,damage))

# # 탱크 : 공격 유닛, 탱크. 일반/시즈모드
# tank_name ="탱크"
# tank_hp = 150
# tank_damage = 35

# print("{} 유닛이 생성되었습니다.".format(tank_name))
# print("체력 {} , 공격력 {} \n".format(tank_hp,tank_damage))

# def attack(name,location,damage):
#     print("{} : {} 방향으로 적군을 공격 합니다.[공격력 {}]".format(\
#         name, location,damage))

# attack(name,"1시",damage)
# attack(tank_name,"1시",tank_damage)

# class Unit: 
#     def __init__(self,name,hp,damage):
#         self.name = name
#         self.hp = hp

# marine = Unit("마린",40,5)
# marine2 = Unit("마린",40,5)
# tank = Unit("탱크",150,35)

# 레이스 : 공중유닛, 비행기, 클로킹
# wraith1 = Unit("레이스",80,5)
# print("유닛 이름 : {}, 공격력 : {} ".format(wraith1.name,wraith1.damage))

# #마인드 컨트롤 : 상대방 유닛을 내 것으로
# wraith2 = Unit("빼앗은 레이스",80,5)
# wraith2.clocking = True #파이썬 에서는 클래스 외부에서 변수를 만들어 쓸 수 있다.

# if wraith2.clocking == True:
#     print("{} 는 현재 클로킹 상태입니다.".format(wraith2.name))

# if wraith1.clocking == True: #기존의 개체에는 추가 되지 않는다.
#     print("{} 는 현재 클로킹 상태입니다.".format(wraith2.name))

class Unit: 
    def __init__(self,name,hp):
        self.name = name
        self.hp = hp

class AttackUnit(Unit):
    def __init__(self,name,hp,damage):
        Unit.__init__(self,name,hp)
        self.damage = damage
    
    def attack(self,location):
        print("{} : {} 방향으로 적군을 공격 합니다.[공격력 : {} ]".format(\
            self.name,location,self.damage))

    def damaged(self,damage):
        print("{} : {} 데미지를 입었습니다.".format(self.name,damage))
        self.hp -=damage
        print("{} : 현재 체력은 {} 입니다.".format(self.name,self.hp))
        if self.hp<=0 :
            print("{} : 파괴되었습니다.".format(self.name))

firebat1 = AttackUnit("파이어뱃",50,16)
firebat1.attack("5시")

firebat1.damaged(25)
firebat1.damaged(25)

# 드랍쉽 : 공중유닛, 수송기
class Flyable:
    def __init__(self,flying_speed):
        self.flying_speed = flying_speed

    def fly(self,name,location):
        print("{} : {} 방향으로 날아갑니다.[속도 {}]".format(\
            name,location,self.flying_speed))

class FlyableAttackUnit(AttackUnit,Flyable):
    def __init__(self,name,hp,damage,flying_speed):
        AttackUnit.__init__(self,name,hp,damage)
        Flyable.__init__(self,flying_speed)

#발키리 : 공중 공격 유닛, 한번에 4번 공격
valkyrie = FlyableAttackUnit("발키리",200,6,5)
valkyrie.fly(valkyrie.name,"3시")
