class BigNumberError(Exception):
    def __init__(self,meg):
        self.meg = meg
    
    def __str__(self):
        return self.meg

try:
    print("한 자리 숫자 나누기 전용 계산기 입니다.")
    num1 = int(input("첫 번째 숫자를 입력하세요 : "))
    num2 = int(input("두 번째 숫자를 입력하세요 : "))
    if num1 >= 10 or num2 >=10:
        # raise ValueError # 에러가 발생하면 이후의 문장을 실행하지 않고 바로 에러처리 문장으로
        raise BigNumberError("입력값 : {} {} ".format(num1,num2)) # 사용자 지정 에러처리
    print("{} / {}  = {} ".format(num1,num2,int(num1/num2)))
except ValueError:
    print("잘못된 값을 입력했습니다. 한자리 숫자만 입력하세요.")
except BigNumberError as err:
    print("에러가 발생하였습니다. 한자리 숫자만 입력하세요.")
    print(err)
finally:
    print("계산기를 이용해 주셔서 감사합니다.")