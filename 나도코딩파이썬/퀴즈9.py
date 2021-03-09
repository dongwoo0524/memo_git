# 동네에 항상 대기 손님이 있는 맛있는 치킨집
# 대기 손님의 치킨 요리 시간을 줄이고자 자동 주문 시스템
# 시스템 코드를 확인하고 적절한 예외처리 구문을 넣으시오.

# 1 보다 작거나 숫자가 아닌 입력값이 들어올 때는 ValueError 로 처리
# 출력 메세지도 입력
# 대기 손님이 주문할 수 있는 총 치킨량은 10마리로 한정
# 치킨 소진시 사용자 정의 에러 를 발생시키고 프로그램 종료
class ChickenError(Exception):
    pass
    # def __init__(self,msg):
    #     self.msg = msg
    
    # def __str__(self):
    #     return self.msg


chicken  = 10
waiting  =1

while(True):
    try:
        print("[남은 치킨 : {}]".format(chicken))
        order = int(input("몇 마리 주문하시겠습니까?"))
        if order > chicken:
            print("재료가 부족합니다.")
        elif order <1:
            raise ValueError
        else:
            print("[대기 번호 {}] {} 마리 주문 완료되었습니다.".format(waiting,order))
            waiting +=1
            chicken -= order
        if chicken<=0:
            raise ChickenError
    except ValueError:
        print("잘못된 값을 입력하셨습니다.")
    except ChickenError:
        print("재고가 소진되어 더 이상 주문을 받지 않습니다.")
        break
    finally:
        print("이용해주셔서 감사합니다.")
    
