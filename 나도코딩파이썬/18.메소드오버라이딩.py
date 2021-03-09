class Unit:
    def __init__(self,name,hp,speed):
        self.name = name
        self.hp = hp
        self.speed = speed

    def move(self,location):
        print("[지상 유닛 이동]")
        print("{} : {} 방향으로 이동합니다.[속도 : {}]".format(\
            self.name,location,self.speed))

class AttackUnit(Unit):
    def __init__(self,name,hp,speed,damage):
        Unit.__init__(self,name,hp,speed)
        self.damage = damage

    def attack(self,location):
        print("{} : {} 방향으로 적을 공격합니다.[공격력 : {} ]".formant(\
            self.name,location,self.damage))
        
    def damaged(self,damage):
        print("{} : {}  데미지를 입었습니다.".format(self.name,damage))
        self.hp -= damage
        print("{} : 현재 체력은 {} 입니다.".format(self.name,self.hp))
        if self.hp <=0:
            print("{} : 파괴되었습니다.".format(self.name))

class Flyable:
    def __init__(self,flying_speed):
        self.flying_speed = flying_speed
    
    def fly(self,name,location):
        print("{} : {} 방향으로 날아갑니다.[속도 : {}]".format(name,location,self.flying_speed))

class FlyableAttackUnit(AttackUnit,Flyable):
    def __init__(self,name,hp,damage,flying_speed):
        AttackUnit.__init__(self,name,hp,0,damage) #지상 스피드는 0
        Flyable.__init__(self,flying_speed)

    def move(self,location):
        print("[공중 유닛 이동]")
        self.fly(self.name,location)

# 벌처 : 지상유닛, 기동성 좋음
# vulture = AttackUnit("벌처",80,10,20)

# battlecruiser = FlyableAttackUnit("배틀크루저",500,25,3)

# vulture.move("11시")
# battlecruiser.move("9시")

#건물
class BuildingUinit(Unit):
    def __init__(self,name,hp,location):
        # Unit.__init__(self,name,hp,0)
        super().__init__(name,hp,0)
        self.location = location


# supply_depot = BuildingUinit("서플라이 디폿",500,"7시")

# def game_start():
#     print("[알림] 새로운 게임을 시작합니다.")

# def game_over():
#     pass

